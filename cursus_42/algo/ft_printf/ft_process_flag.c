/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_flag.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 11:56:32 by efischer          #+#    #+#             */
/*   Updated: 2019/03/12 11:56:35 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_percent(char c, t_flag *flag)
{
	char	*format;

	format = ft_strdup("%");
	if (flag->width)
		format = ft_width(c, format, flag);
	return (format);
}

static void	ft_precision_width(va_list *arg, t_flag *flag, char **s)
{
	int		nb;

	if (**s == '*')
	{
		nb = va_arg(*arg, int);
		if (nb < 0 && !flag->dot)
		{
			flag->min = 1;
			nb *= -1;
		}
	}
	else
	{
		nb = ft_atoi(*s);
		while (ft_isdigit(**s))
			(*s)++;
		(*s)--;
	}
	if (flag->dot)
		flag->precision = nb;
	else
		flag->width = nb;
	flag->dot = 0;
}

static char	*ft_flag_error(char c, t_flag *flag)
{
	char	*format;
	char	*tmp;
	int		len;

	format = ft_strdup(&c);
	if ((len = flag->width - ft_strlen(format)) > 0)
	{
		if (!(tmp = (char*)malloc(sizeof(char) * (len + 1))))
		{
			ft_strdel(&format);
			return (NULL);
		}
		tmp[len--] = '\0';
		while (len >= 0)
			tmp[len--] = ' ';
		if (flag->min)
			format = ft_join_free(format, tmp, 3);
		else
			format = ft_join_free(tmp, format, 3);
	}
	return (format);
}

static char	*ft_manage_z(char c, t_flag *flag)
{
	char	*s;

	s = ft_strdup("Z");
	if (flag->width)
		s = ft_width(c, s, flag);
	return (s);
}

static void	ft_all_conv(char c, va_list *arg, t_flag *flag, t_tmp *tmp)
{
	if (c == 'c' || c == 'C' || c == 's' || c == 'S' || c == 'p')
		tmp->str = ft_manage_str(c, arg, flag);
	else if (c == 'd' || c == 'D' || c == 'i' || c == 'o' || c == 'O'
	|| c == 'u' || c == 'U' || c == 'x' || c == 'X' || c == 'f' || c == 'F')
	{
		if (flag->precision >= 0)
			flag->zero = 0;
		tmp->str = ft_diouxxf(c, arg, flag);
	}
	else if (c == 'Z')
		tmp->str = ft_manage_z(c, flag);
	else if (c == '%')
		tmp->str = ft_percent(c, flag);
	else
		tmp->str = ft_flag_error(c, flag);
	if (tmp->str)
		tmp->len = ft_strlen(tmp->str);
	return ;
}

void		ft_process_flag(char **s, va_list *arg, t_flag *flag, t_tmp *tmp)
{
	(*s)++;
	tmp->len = 0;
	while (**s)
	{
		if (**s == '#' || **s == '0' || **s == '-' || **s == '+' || **s == ' '
		|| **s == '.')
			ft_manage_flag(**s, flag);
		else if (**s == 'h' || **s == 'l' || **s == 'L' || **s == 'j' || **s == 'z')
			ft_manage_conv_flag(**s, flag);
		else if ((**s >= '1' && **s <= '9') || **s == '*')
			ft_precision_width(arg, flag, s);
		else
		{
			ft_all_conv(**s, arg, flag, tmp);
			return ;
		}
		(*s)++;
	}
	tmp->str = ft_strdup("\0");
}
