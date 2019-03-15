/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_conv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 11:28:14 by efischer          #+#    #+#             */
/*   Updated: 2019/03/15 14:16:04 by efischer         ###   ########.fr       */
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

static char		*ft_float(va_list *arg, t_flag *flag)
{
//	double	f;
	char	*str;

	(void)flag;
	(void)arg;
//	f = va_arg(*arg, double);
	//str = ft_printfloat(f);
	//ft_putendl(str);
	str = "float";
	return (str);
}

static char		*ft_manage_conv(char c, va_list *arg, t_flag *flag)
{
	char	*str;

	if (c == 'f')
		str = ft_float(arg, flag);
	else if (flag->l || flag->ll)
		str = ft_long_diouxx(c, arg, flag);
	else
		str = ft_diouxx(c, arg, flag);
	return (str);
}

char			*ft_diouxxf(char c, va_list *arg, t_flag *flag)
{
	char	*format;

	format = ft_manage_conv(c, arg, flag);
	if (flag->sharp > 0 && (c == 'x' || c == 'X') && *format != '0'
	&& !flag->zero)
	{
		format = ft_join_free("0x", format, 2);
		flag->sharp = 0;
	}
	if (flag->precision || flag->width)
	{
		if (flag->precision)
			format = ft_precision(c, format, flag);
		if (flag->width)
			format = ft_width(c, format, flag);
	}
	else if (flag->plus && *format != '-')
		format = ft_join_free("+", format, 2);
	else if (flag->space && *format != '-')
		format = ft_join_free(" ", format, 2);
	return (c == 'X' ? ft_strupcase(format) : format);
}
