/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width_precision.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 14:36:23 by efischer          #+#    #+#             */
/*   Updated: 2019/03/12 11:55:56 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*ft_process_precision(char *format, int len, t_flag *flag)
{
	char	c;
	char	*str;

	c = '0';
	(void)flag;
	if (!*format)
		return (format);
	if (!(str = (char*)malloc(sizeof(char) * (len + 1))))
	{
		ft_strdel(&format);
		return (NULL);
	}
	str[len--] = '\0';
	while (len > -1)
		str[len--] = c;
	if (*format == '-')
	{
		str[0] = '-';
		format[0] = '0';
	}
	format = ft_join_free(str, format, 3);
	return (format);
}

char			*ft_precision(char conv, char *format, t_flag *flag)
{
	int		len;
	char	*tmp;

	if (!flag->precision && !((conv == 'o' || conv == 'O') && flag->sharp)
	&& !(conv == 'd' && *format != '0') && conv != 's')
	{
		ft_strdel(&format);
		return (ft_strdup(""));
	}
	len = flag->precision - ft_strlen(format);
	if (*format == '-')
		len++;
	if (len > 0 && conv != 's')
		format = ft_process_precision(format, len, flag);
	if (flag->sharp && (conv == 'x' || conv == 'X'))
		format = ft_join_free("0x", format, 2);
	else if (conv == 's')
	{
		tmp = format;
		format = ft_strndup(format, flag->precision);
		ft_strdel(&tmp);
	}
	return (format);
}

static char		*ft_process_width(int len, char *format, char x, t_flag *flag)
{
	int		i;
	char	*str;
	char	c;

	i = 0;
	if (flag->plus)
		len--;
	if (!(str = (char*)malloc(sizeof(char) * (len + 1))))
	{
		ft_strdel(&format);
		return (NULL);
	}
	c = ' ';
	if (flag->zero && !flag->min)
		c = '0';
	while (i < len)
		str[i++] = c;
	str[i] = '\0';
	if (flag->plus && c == '0')
		str = ft_join_free("+", str, 2);
	else if (flag->plus && c == ' ')
		format = ft_join_free("+", format, 2);
	if (flag->space)
		str[0] = ' ';
	if (flag->sharp && (x == 'x' || x == 'X') && c == ' ')
		format = ft_join_free("0x", format, 2);
	else if (flag->sharp && (x == 'x' || x == 'X') && c == '0')
		str = ft_join_free("0x", str, 2);
	if (*format == '-' && c == '0')
	{
		str[0] = '-';
		format[0] = '0';
	}
	if (flag->min)
		format = ft_join_free(format, str, 3);
	else
		format = ft_join_free(str, format, 1);
	return (format);
}

char			*ft_width(char conv, char *format, t_flag *flag)
{
	int		len;

	len = flag->width - ft_strlen(format);
	if (len > 0)
		format = ft_process_width(len, format, conv, flag);
	else if (flag->plus)
		format = ft_join_free("+", format, 2);
	return (format);
}
