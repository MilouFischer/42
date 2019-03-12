/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 11:28:28 by efischer          #+#    #+#             */
/*   Updated: 2019/03/12 12:00:24 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_list	*ft_fill_content(t_list *lst, char *str, t_flag flag)
{
	int		i;
	char	*tmp;

	i = 0;
	if (flag.null)
	{
		tmp = lst->content;
		lst->content_size = ft_strlen(lst->content) + 1;
		if (!(lst->content = (char*)malloc(sizeof(char) *
		(lst->content_size + ft_strlen(str) + 1))))
			lst->content = NULL;
		lst->content = (char*)ft_memcpy(lst->content, tmp, lst->content_size);
		i = lst->content_size;
		while (*str)
			lst->content[i++] = *str++;
		lst->content[i] = '\0';
		lst->content_size = i;
	}
	else
	{
		lst->content = ft_join_free(lst->content, str, 1);
		lst->content_size = ft_strlen(lst->content);
	}
	return (lst);
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
		str++;
		list = ft_fill_content(list, str, flag);
	}
	return (tmp_list);
}

int				ft_printf(const char *format, ...)
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
		if (!(list = ft_get_flags(list, &arg)))
			return (0);
		va_end(arg);
	}
	len = ft_lstprint(list);
	ft_lstfree(list);
	return (len);
}
