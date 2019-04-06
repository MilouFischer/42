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

/*static t_list	*ft_join_content(t_list *lst, char *str, t_flag flag)
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
}*/

static int	ft_get_flags(va_list *arg, char *str)
{
	char	*out;
	char	*tmp;
	char	*format;
	t_flag	flag;
	int		null;
	int		i;
	void	*null_str;
	int		len;

	len = 0;
	out = NULL;
	while ((format = ft_strchr(str, '%')))
	{
		ft_init_flag(&flag);
		tmp = ft_strsub(str, 0, format - str);
		len += ft_strlen(tmp);
		out = ft_join_free(out, tmp, 3);
		str = format;
		if (!(tmp = ft_process_flag(&str, arg, &flag)))
			tmp = ft_strdup("(null)");
		if ((*str == 'c' || *str == 'C') && (int)ft_strlen(tmp) < flag.precision)
		{
			null = 0;
			i = 0;
			while (null < 2)
			{
				if (tmp[i] == '\0')
					null++;
				i++;
			}
			null_str = ft_memjoin(out, tmp, len, i);
			out = (char*)null_str;
			len += i - 1;
		}
		else if ((*str == 'c' || *str == 'C') && (!*tmp || (int)ft_strlen(tmp) < flag.width))
		{
			null_str = ft_memjoin(out, tmp, len, ft_strlen(tmp) + 1);
			out = (char*)null_str;
			len++;
		}
		else
		{
			if ((int)ft_strlen(out) < len)
				out = ft_memjoin(out, tmp, len, ft_strlen(tmp));
			else
				out = ft_join_free(out, tmp, 3);
		}
		len += ft_strlen(tmp);
		if (*str)
			str++;
	}
	if (*str)
	{
		ft_init_flag(&flag);
		if ((int)ft_strlen(out) < len)
			out = ft_memjoin(out, str, len, ft_strlen(str));
		else
			out = ft_join_free(out, str, 1);
		len += ft_strlen(str);
	}
	write(1, out, len);
	ft_strdel(&out);
	return (len);
}

int				ft_printf(const char *format, ...)
{
	int		len;
	va_list	arg;
	char	*str;

	if (!format)
		return (0);
	str = ft_strdup(format);
	len = ft_strlen(format);
	if (ft_strchr(str, '%'))
	{
		va_start(arg, format);
		len = ft_get_flags(&arg, str);
		va_end(arg);
	}
	else
		write(1, str, len);
	ft_strdel(&str);
	return (len);
}
