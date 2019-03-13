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
	char	unicode[5];
	char	tmp[3];
	char	*str;
	int		i;
	int		tmp_i;

	i = 0;
	tmp_i = 0;
	ft_init_str(unicode, 5);
	while (*s && i < 5)
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
	return (str);
}

char			*ft_putunicode(wchar_t *s)
{
	char	**tab;
	char	*str;
	int		i;
	int		j;
	int		len;

	i = 0;
	j = 0;
	len = 0;
	while (s[i])
	{
		if (s[i] > 128 && ft_check_unicode(ft_itoa_base(s[i], 2), s[i]))
			s[i] = ft_convert_to_unicode(s[i]);
		i++;
	}
	if (!(tab = (char**)malloc(sizeof(char*) * (i + 1))))
		return (NULL);
	i = 0;
	while (s[i])
		tab[j++] = ft_print_unicode(ft_itoa_base(s[i++], 16));
	tab[j] = 0;
	i = 0;
	while (tab[i])
		len += ft_strlen(tab[i++]);
	if (!(str = (char*)malloc(sizeof(char) * (len + 1))))
	{
		free(tab);
		return (NULL);
	}
	i = 0;
	while (*tab)
	{
		while (**tab)
		{
			str[i++] = *(*tab)++;
		}
		tab++;
	}
	str[i] = '\0';
	return (str);
}
