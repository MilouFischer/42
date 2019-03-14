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

size_t			ft_wchar_tlen(wchar_t *ws)
{
	size_t	len;

	len = 0;
	while (ws[len])
		len++;
	return (len);
}

char			*ft_putunicode(wchar_t *u)
{
	char		*str;
	char		*tmp;
	char		**tab;
	size_t		len;
	int			i;
	wchar_t		c;

	i = 0;
	len = ft_wchar_tlen(u);
	if (!(tab = (char**)malloc(sizeof(char*) * (len + 1))))
		return (NULL);
	while (*u)
	{
		if (*u > 128 && ft_check_unicode((tmp = ft_itoa_base(*u, 2)), *u))
		{
			c = ft_convert_to_unicode(*u);
			ft_strdel(&tmp);
		}
		else
			c = (char)*u;
		tmp = ft_itoa_base(c, 16);
		ft_putnbr(i);
		tab[i++] = ft_print_unicode(tmp);
		ft_putendl(tab[0]);
		ft_strdel(&tmp);
		u++;
	}
	tab[i] = 0;
	i = 0;
	while (tab[i])
	{
		ft_putnbr(i);
		ft_putendl(tab[i++]);
	}
	i = 0;
	while (tab[i])
		len += ft_strlen(tab[i++]);
	if (!(str = (char*)malloc(sizeof(char) * (len + 1))))
	{
		ft_free_tab(tab);
		return (NULL);
	}
	i = 0;
	while (*tab)
	{
		while (**tab)
			str[i++] = *(*tab)++;
		tab++;
	}
	str[i] = '\0';
	return (str);
}