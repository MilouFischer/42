/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 12:04:30 by efischer          #+#    #+#             */
/*   Updated: 2019/03/15 14:10:29 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*ft_c_width(char *s, t_flag *flag)
{
	int		len;
	char	*tmp;
	char	c;

	if (!(len = flag->width - 1))
	{
		ft_strdel(&s);
		return (ft_strdup("\0"));
	}
	if (!(tmp = (char*)malloc(sizeof(char) * len)))
	{
		ft_strdel(&s);
		return (NULL);
	}
	tmp[len--] = '\0';
	c = flag->zero ? '0' : ' ';
	while (len)
		tmp[len--] = c;
	tmp[len] = c;
	len = flag->null ? 1 : ft_strlen(s);
	if (flag->min)
		s = ft_memjoin(s, tmp, len, ft_strlen(tmp));
	else
		s = ft_join_free(tmp, s, 3);
	return (s);
}

char			*ft_manage_c(va_list *arg, t_flag *flag)
{
	char	*s;

	if (!(s = (char*)malloc(sizeof(char) * 2)))
		return (NULL);
	s[0] = va_arg(*arg, unsigned int);
	s[1] = '\0';
	if (!s[0])
		flag->null = 1;
	if (flag->width >= 1)
		s = ft_c_width(s, flag);
	return (s);
}

char			*ft_manage_s(va_list *arg, t_flag *flag)
{
	char	*s;

	if (!(s = va_arg(*arg, char*)))
	{
		if (flag->width)
			s = ft_strdup("");
		else
			return (ft_strdup("(null)"));
	}
	else
		s = ft_strdup(s);
	if (flag->precision >= 0)
		s = ft_precision('s', s, flag);
	if (flag->width)
		s = ft_width('s', s, flag);
	return (s);
}
