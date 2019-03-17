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

static t_list	*ft_fill_content(t_list *lst, char *str, t_flag flag)
{
	size_t	i;

	i = 0;
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

static t_list	*ft_fill_list(t_list *lst, char *str, t_flag flag)
{
	t_list	*new;

	if (!lst->content)
		return (ft_fill_content(lst, str, flag));
	new = ft_lstnew(NULL, 0);
	new = ft_fill_content(new, str, flag);
	ft_lstadd(&new, lst);
	return (lst);
}

static t_list	*ft_get_flags(t_list *list, va_list *arg, char *str)
{
	char	*tmp;
	char	*format;
	t_list	*tmp_list;
	t_flag	flag;

	(void)arg;
	tmp_list = list;
	while ((format = ft_strchr(str, '%')))
	{
		ft_init_flag(&flag);
		tmp = str;
		tmp[format - str] = '\0';
		list = ft_fill_list(list, tmp, flag);
		tmp = str;
		str = ft_strdup(format);
		ft_strdel(&tmp);
		list = list->next;
		/*if (!(tmp = ft_process_flag(&str, arg, &flag)))
			return (NULL);
		list = ft_fill_list(list, tmp, flag);
		str++;
		list = list->next;
		flag.null = 0;*/
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
	list = ft_lstnew(NULL, 0);
	str = ft_strdup(format);
	if (ft_strchr(str, '%'))
	{
		va_start(arg, format);
		if (!(list = ft_get_flags(list, &arg, str)))
			return (0);
		va_end(arg);
	}
	len = ft_lstprint(list);
	len = 0;
	ft_lstfree(list);
	return (len);
}
