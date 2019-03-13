/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunicode.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 12:32:14 by efischer          #+#    #+#             */
/*   Updated: 2019/03/12 13:12:15 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_init_str(char *s, int n)
{
	int		i;

	i = 0;
	while (i < n)
		s[i++] = '\0';
}

static char		*ft_print_unicode(char *s)
{
	char	unicode[4];
	char	tmp[3];
	char	*str;
	int		i;
	int		tmp_i;

	i = 0;
	tmp_i = 0;
	ft_init_str(unicode, 4);
	while (*s && i < 4)
	{
		tmp[tmp_i++] = *s;
		if (tmp_i == 2)
		{
			tmp[tmp_i] = '\0';
			unicode[i++] = ft_atoi_base(tmp, 16);
			tmp_i = 0;
			ft_init_str(tmp, 3);
		}
		s++;
	}
	str = unicode;
	//write(1, unicode, i);
	return (str);
}

char			*ft_putunicode(unsigned int c)
{
	if (c > 128 && ft_check_unicode(ft_itoa_base(c, 2), c))
		c = ft_convert_to_unicode(c);
	return (ft_print_unicode(ft_itoa_base(c, 16)));
}
