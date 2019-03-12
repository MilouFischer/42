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

#include "libft/libft.h"

static unsigned int	ft_atoi_base(char *str, int base)
{
	unsigned int	nb;

	nb = 0;
	if (base < 2 || base > 16)
		return (0);
	str = ft_strupcase(str);
	while (*str && (ft_isdigit(*str) || (*str >= 'A' && *str <= 'F')))
	{
		if (*str - '0' < 10)
			nb = *str++ - '0' + nb * base;
		else
			nb = *str++ - 'A' + 10 + nb * base;
	}
	return (nb);
}

static void		ft_init_str(char *s, int n)
{
	int		i;

	i = 0;
	while (i < n)
		s[i++] = '\0';
}

static void			ft_print_unicode(char *s)
{
	char	unicode[4];
	char	tmp[3];
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
	write(1, unicode, i);
}

void				ft_putunicode(unsigned int c)
{
	ft_print_unicode(ft_itoa_base(c, 16));
}
