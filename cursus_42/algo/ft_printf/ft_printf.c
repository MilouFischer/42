/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 11:28:28 by efischer          #+#    #+#             */
/*   Updated: 2019/02/20 12:08:44 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char *ft_process_flag(char *s, va_list *arg, t_flag *flag)
{
	char	*format;
	char	*tmp;
	char	*nb;

	format = NULL;
	s++;
	while (*s)
	{
		tmp = format;
		if (*s == '#' || *s == '0' || *s == '-' || *s == '+' || *s == ' ' || *s == '.')
			ft_manage_flag(*s, flag);
		else if (*s == '%')
		{
			format = ft_strdup("%");
			if (flag->precision)
				format = ft_precision(*s, format, flag);
			return (format);
		}
		else if (*s == 'h' || *s == 'l' || *s == 'L')
			ft_manage_conv_flag(*s, flag);
		else if (*s == 'c' || *s == 's' || *s == 'p')
		{
			format = ft_manage_str(*s, format, arg, flag);
			return (format);
		}
		else if (*s == 'd' || *s == 'i' || *s == 'o' || *s == 'u' || *s == 'x'
				|| *s == 'X' || *s == 'f')
		{
			format = ft_strjoin(tmp, nb = ft_manage_conv(*s, arg, flag));
			ft_strdel(&tmp);
			ft_strdel(&nb);
			if (flag->sharp > 0 && (*s == 'x' || *s == 'X') && *format != '0' && !flag->zero)
			{
				format = ft_join_free("0x", format, 2);
				flag->sharp = 0;
			}
			if (flag->precision || flag->width >= 0)
			{
				if (flag->precision)
					format = ft_precision(*s, format, flag);
				if (flag->width >= 0)
					format = ft_width(*s, format, flag);
			}
			else if (flag->plus && *format != '-')
				format = ft_join_free("+", format, 2);
			else if (flag->space && *format != '-')
				format = ft_join_free(" ", format, 2);
			return (*s == 'X' ? ft_strupcase(format) : format);
		}
		else if (*s >= '1' && *s <= '9')
		{
			flag->precision = ft_atoi(s);
			while (ft_isdigit(*s))
				s++;
			s--;
		}
		s++;
	}
	return (NULL);
}

static t_list	*ft_get_flags(t_list *list, va_list *arg)
{
	char	*tmp;
	t_list	*tmp_list;
	t_list	*new;
	t_flag	flag;

	tmp_list = list;
	while ((tmp = ft_strchr(list->content, '%')))
	{
		ft_init_flag(&flag);
		new = ft_lstnew_str(tmp, ft_strlen(tmp));
		tmp = list->content;
		list->content = ft_strsub(tmp, 0, list->content_size - new->content_size);
		list->content_size = ft_strlen(list->content);
		ft_lstadd(&new, list);
		list = list->next;
		tmp = list->content;
		if (!(list->content = ft_process_flag(tmp, arg, &flag)))
			return (NULL);
		list->content_size = ft_strlen(list->content);
		ft_strdel(&tmp);
	}
	return (tmp_list);
}

int			ft_printf(const char *format, ...)
{
	int		len;
	va_list	arg;
	t_list	*list;

	if (!format)
		return (0);
	list = ft_lstnew_str(format, ft_strlen(format));
	if (ft_strchr(list->content, '%'))
	{
		va_start(arg, format);
		if (!(list	= ft_get_flags(list, &arg)))
			return (0);
		va_end(arg);
	}
	len = ft_print_list(list);
	ft_free_list(list);
	return (len);
}
