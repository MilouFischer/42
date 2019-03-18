/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 11:28:28 by efischer          #+#    #+#             */
/*   Updated: 2019/03/15 16:41:52 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_list	*ft_join_content(t_list *lst, char *str, t_flag flag)
{
	char	*tmp;

	if (flag.null)
	{
		tmp = lst->content;
		lst->content = ft_memjoin(tmp, str, lst->content_size, ft_strlen(str) + 1);
		ft_strdel(&tmp);
		lst->content_size += ft_strlen(str) + 1;
	}
	else
	{
		lst->content = ft_join_free(lst->content, str, 1);
		lst->content_size += ft_strlen(str);
	}
	return (lst);
}

static t_list	*ft_fill_content(t_list *lst, char *str, t_flag flag)
{
	size_t	i;

	i = 0;
	ft_strdel(&lst->content);
	if (flag.null)
	{
		lst->content_size = ft_strlen(str) + 1;
		if (!(lst->content = (char*)malloc(sizeof(char)
		* (lst->content_size + 1))))
			return (NULL);
		while (i < lst->content_size)
			lst->content[i++] = *str++;
		lst->content[i] = '\0';
	}
	else
	{
		lst->content = ft_strdup(str);
		lst->content_size = ft_strlen(lst->content);
	}
	return (lst);
}

static t_list	*ft_get_flags(t_list *list, va_list *arg, char *str)
{
	char	*tmp;
	char	*format;
	t_list	*new;
	t_list	*tmp_list;
	t_flag	flag;

	tmp_list = list;
	while ((format = ft_strchr(str, '%')))
	{
		ft_init_flag(&flag);
		list = ft_fill_content(list, tmp = ft_strsub(str, 0, format - str), flag);
		ft_strdel(&tmp);
		str = format;
		if (!(tmp = ft_process_flag(&str, arg, &flag)))
			return (NULL);
		str++;
		list = ft_join_content(list, tmp, flag);
		ft_strdel(&tmp);
		new = ft_lstnew_str(NULL, 0);
		ft_lstadd(&new, list);
		list = list->next;
	}
	if (*str)
	{
		ft_init_flag(&flag);
		list = ft_fill_content(list, str, flag);
	}
	return (tmp_list);
}

int				ft_printf(const char *format, ...)
{
	int		len;
	va_list	arg;
	t_list	*list;
	char	*str;

	if (!format)
		return (0);
	list = ft_lstnew(format, ft_strlen(format));
	str = ft_strdup(format);
	if (ft_strchr(str, '%'))
	{
		va_start(arg, format);
		if (!(list = ft_get_flags(list, &arg, str)))
			return (0);
		va_end(arg);
	}
	ft_strdel(&str);
	len = ft_lstprint(list);
	len = 0;
	ft_lstfree(list);
	return (len);
}
