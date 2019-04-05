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

static t_list	*ft_get_flags(t_list *lst, va_list *arg, char *str)
{
	char	*tmp;
	char	*format;
	t_list	*new;
	t_list	*tmp_lst;
	t_flag	flag;
	int		null;
	int		i;
	void	*null_str;

	tmp_lst = lst;
	while ((format = ft_strchr(str, '%')))
	{
		ft_init_flag(&flag);
		lst = ft_fill_content(lst, tmp = ft_strsub(str, 0, format - str), flag);
		ft_strdel(&tmp);
		str = format;
		if (!(tmp = ft_process_flag(&str, arg, &flag)))
			tmp = ft_strdup("(null)");
		if (*str == 'c' && (int)ft_strlen(tmp) < flag.width)
		{
			null = 0;
			i = 0;
			while (null < 2)
			{
				if (tmp[i] == '\0')
					null++;
				i++;
			}
			null_str = ft_memjoin(lst->content, tmp, lst->content_size, i);
			lst->content = (char*)null_str;
			lst->content_size += i - 1;
		}
		else
			lst = ft_join_content(lst, tmp, flag);
		ft_strdel(&tmp);
		if (*str)
			str++;
		if (*str)
		{
			new = ft_lstnew_str(NULL, 0);
			ft_lstadd(&new, lst);
			lst = lst->next;
		}
	}
	if (*str)
	{
		ft_init_flag(&flag);
		lst = ft_fill_content(lst, str, flag);
	}
	return (tmp_lst);
}

int				ft_printf(const char *format, ...)
{
	int		len;
	va_list	arg;
	char	*out;
	char	*tmp;

	if (!format)
		return (0);
	out = ft_strdup(format);
	len = ft_strlen(format);
	tmp = out;
	if (ft_strchr(str, '%'))
	{
		va_start(arg, format);
		if (!(len = ft_get_flags(&out, &arg, str)))
			return (0);
		va_end(arg);
	}
	write(1, out, len);
	ft_strdel(&out);
	ft_strdel(&tmp);
	return (len);
}
