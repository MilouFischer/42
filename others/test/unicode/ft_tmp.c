/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 13:52:58 by efischer          #+#    #+#             */
/*   Updated: 2019/03/15 13:53:19 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		tab[i++] = ft_print_unicode(tmp);
		ft_strdel(&tmp);
		u++;
	}
	tab[i] = 0;
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