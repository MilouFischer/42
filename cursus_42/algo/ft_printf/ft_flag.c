/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 14:36:23 by efischer          #+#    #+#             */
/*   Updated: 2019/02/22 17:41:02 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
static char		*ft_process_precision(char *format, int len, t_flag *flag)
{
	char	c;
	char	*str;

	c = ' ';
	if (flag->precision > (int)ft_strlen(format))
		c = '0';
	if (!(str = (char*)malloc(sizeof(char) * (len + 1))))
	{
		ft_strdel(&format);
		return (NULL);
	}
	str[len--] = '\0';
	while (len > -1)
		str[len--] = c;
	if (*format == '-' && c == '0')
	{
		format[0] = '0';
		str = ft_join_free("-", str, 2);
	}
	if (flag->min && (!flag->width || !flag->precision))
		format = ft_join_free(format, str, 1);
	else
		format = ft_join_free(str, format, 2);
	ft_strdel(&str);
	return (format);
}

char	*ft_precision(char conv, char *format, t_flag *flag)
{
	int		len;

	if (flag->precision == -1 && *format == '0')
	{
		ft_strdel(&format);
		if (conv == 'o' && flag->sharp)
			format = ft_strdup("0");
		else
			format = ft_strdup("");
		flag->zero = 0;
	}
	len = flag->precision - ft_strlen(format);
	if (len > 0)
		format = ft_process_precision(format, len, flag);
	return (format);
}

char	*ft_width(char conv, char *format, t_flag *flag)
{
	int		len;
	int		i;
	char	*str;
	char	c;

	i = 0;
	if (flag->sharp > 0 && (conv == 'x' || conv == 'X'))
	{
		flag->width -= 2;
		flag->plus = 0;
	}
	if (flag->plus && *format != '-')
		flag->width--;
	len = flag->width - ft_strlen(format);
	if (*format == '-' && flag->precision)
		flag->precision++;
	if (len > 0)
	{
		if (!(str = (char*)malloc(sizeof(char) * (len + 1))))
		{
			ft_strdel(&format);
			return (NULL);
		}
		c = ' ';
		if (flag->zero && !flag->min && (flag->precision <= 0
		|| flag->width <= flag->precision))
			c = '0';
		if (flag->space && len != 1)
			str[i++] = ' ';
		while (i < len)
			str[i++] = c;
		str[i] = '\0';
		if (flag->plus && *format != '-' && c == '0')
			str = ft_join_free("+", str, 2);
		else if (flag->plus && *format != '-' && c == ' ')
			format = ft_join_free("+", format, 2);
		if (flag->min)
			format = ft_join_free(format, str, 1);
		else if (*format == '-' && c == '0')
		{
			str[0] = '-';
			format[0] = '0';
			format = ft_join_free(str, format, 2);
		}
		else
			format = ft_join_free(str, format, 2);
		if (flag->sharp && flag->zero && (conv == 'x' || conv == 'X'))
			format = ft_join_free("0x", format, 2);
		ft_strdel(&str);
	}
	else if (flag->plus && *format != '-')
		format = ft_strjoin("+", format);
	return (format);
}
