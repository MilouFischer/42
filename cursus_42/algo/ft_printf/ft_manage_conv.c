/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_conv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 11:28:14 by efischer          #+#    #+#             */
/*   Updated: 2019/04/11 19:31:29 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*ft_manage_str(char c, va_list *arg, t_flag *flag)
{
	if (c == 'C' || (flag->l && (c == 'c')))
		return (ft_manage_unicode_char(arg, flag));
	else if (c == 'S' || (flag->l && (c == 's')))
		return (ft_manage_unicode_str(arg, flag));
	else if (c == 'c')
		return (ft_manage_c(arg, flag));
	else if (c == 's')
		return (ft_manage_s(arg, flag));
	else
		return (ft_manage_p(arg, flag));
}

static char		*ft_process_round(char *tmp, int i)
{
	int		ret;
	char	*str;

	ret = 1;
	if (!(str = (char*)malloc(sizeof(char) * i + 1)))
		return (NULL);
	str[i--] = '\0';
	while (i > -1)
	{
		if (ret == 1)
		{
			ret = 0;
			tmp[i]++;
		}
		if (tmp[i] - '0' >= 5)
		{
			if (tmp[i] - '0' == 10)
				tmp[i] = '0';
			ret = 1;
		}
		str[i] = tmp[i];
		i--;
	}
	return (str);
}

static char		*ft_round(char *s, int n)
{
	int		i;
	char	*str;
	char	*tmp;

	i = 0;
	tmp = ft_strchr(s, '.');
	tmp++;
	while (tmp[i] && i < n)
		i++;
	if (tmp[i] - '0' >= 5)
		str = ft_process_round(tmp, i);
	else
		str = ft_strndup(tmp, i);
	tmp = ft_strsub(s, 0, tmp - s);
	str = ft_join_free(tmp, str, 3);
	ft_strdel(&s);
	return (ft_strdup(str));
}

static char		*ft_float(va_list *arg, t_flag *flag)
{
	double	f;
	char	*str;

	f = va_arg(*arg, double);
	str = ft_printfloat(f);
	if (!flag->width && flag->precision == -1)
	{
		str = ft_round(str, 6);
	}
	return (str);
}

static char		*ft_manage_conv(char c, va_list *arg, t_flag *flag)
{
	char	*str;

	if (c == 'f' || c == 'F')
		str = ft_float(arg, flag);
	else if (flag->l || flag->ll || flag->j || flag->z || c == 'D' || c == 'O'
	|| c == 'U')
		str = ft_long_diouxx(c, arg, flag);
	else
		str = ft_diouxx(c, arg, flag);
	if ((c == 'x' || c == 'X') && flag->sharp && flag->width
	&& flag->precision == -1)
		flag->width -= 2;
	return (str);
}

char			*ft_diouxxf(char c, va_list *arg, t_flag *flag)
{
	char	*format;

	format = ft_manage_conv(c, arg, flag);
	if (*format == '-')
	{
		flag->plus = 0;
		flag->space = 0;
	}
	if (flag->precision >= 0 || flag->width)
	{
		if (flag->precision >= 0)
			format = ft_precision(c, format, flag);
		if (flag->width)
			format = ft_width(c, format, flag);
		else if (flag->space)
			format = ft_join_free(" ", format, 2);
		else if (flag->plus)
			format = ft_join_free("+", format, 2);
	}
	else
		format = ft_apply_flag(c, format, flag);
	return (c == 'X' ? ft_strupcase(format) : format);
}
