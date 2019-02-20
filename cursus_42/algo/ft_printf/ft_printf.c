/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 11:28:28 by efischer          #+#    #+#             */
/*   Updated: 2019/02/20 14:43:56 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char *ft_process_flag(char **s, va_list *arg, t_flag *flag)
{
	char	*format;
	char	*tmp;
	char	*nb;

	format = NULL;
	(*s)++;
	while (**s)
	{
		tmp = format;
		if (**s == '#' || **s == '0' || **s == '-' || **s == '+' || **s == ' ' || **s == '.')
			ft_manage_flag(**s, flag);
		else if (**s == '%')
		{
			(*s)++;
			format = ft_strdup("%");
			if (flag->precision)
				format = ft_precision(**s, format, flag);
			return (format);
		}
		else if (**s == 'h' || **s == 'l' || **s == 'L')
			ft_manage_conv_flag(**s, flag);
		else if (**s == 'c' || **s == 's' || **s == 'p')
		{
			format = ft_manage_str(**s, format, arg, flag);
			return (format);
		}
		else if (**s == 'd' || **s == 'i' || **s == 'o' || **s == 'u' || **s == 'x'
				|| **s == 'X' || **s == 'f')
		{
			format = ft_strjoin(tmp, nb = ft_manage_conv(**s, arg, flag));
			ft_strdel(&tmp);
			ft_strdel(&nb);
			if (flag->sharp > 0 && (**s == 'x' || **s == 'X') && *format != '0' && !flag->zero)
			{
				format = ft_join_free("0x", format, 2);
				flag->sharp = 0;
			}
			if (flag->precision || flag->width >= 0)
			{
				if (flag->precision)
					format = ft_precision(**s, format, flag);
				if (flag->width >= 0)
					format = ft_width(**s, format, flag);
			}
			else if (flag->plus && *format != '-')
				format = ft_join_free("+", format, 2);
			else if (flag->space && *format != '-')
				format = ft_join_free(" ", format, 2);
			return (**s == 'X' ? ft_strupcase(format) : format);
		}
		else if (**s >= '1' && **s <= '9')
		{
			flag->precision = ft_atoi(*s);
			while (ft_isdigit(**s))
				(*s)++;
			(*s)--;
		}
		else if (**s == 'Z')
			return (ft_strdup("Z"));
		(*s)++;
	}
	return (NULL);
}

static t_list	*ft_fill_content(t_list *list, char *str, t_flag flag)
{
	int		i;
	char	*tmp;

	i = 0;
	if (flag.null)
	{
		tmp = list->content;
		list->content_size = ft_strlen(list->content) + 1;
		if (!(list->content = (char*)malloc(sizeof(char) * (list->content_size + ft_strlen(str) + 1))))
			list->content = NULL;
		list->content = (char*)ft_memcpy(list->content, tmp, list->content_size);
		i = list->content_size;
		while (*str)
			list->content[i++] = *str++;
		list->content[i] = '\0';
		list->content_size = i;
	}
	else
	{
		list->content = ft_join_free(list->content, str, 1);
		list->content_size = ft_strlen(list->content);
	}
	return (list);
}

static t_list	*ft_get_flags(t_list *list, va_list *arg)
{
	char	*str;
	char	*tmp;
	t_list	*tmp_list;
	t_list	*new;
	t_flag	flag;

	tmp_list = list;
	str = list->content;
	while ((tmp = ft_strchr(str, '%')))
	{
		ft_init_flag(&flag);
		new = ft_lstnew_str(NULL, 0);
		str = ft_strdup(tmp);
		tmp = list->content;
		list->content = ft_strsub(tmp, 0, list->content_size - ft_strlen(str));
		list->content_size = ft_strlen(list->content);
		ft_lstadd(&new, list);
		list = list->next;
		if (!(list->content = ft_process_flag(&str, arg, &flag)))
			return (NULL);
		list = ft_fill_content(list, str + 1, flag);
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
