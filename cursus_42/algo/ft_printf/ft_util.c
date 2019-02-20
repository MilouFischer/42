/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 11:26:50 by efischer          #+#    #+#             */
/*   Updated: 2019/02/20 14:09:30 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_list(t_list *list)
{
	int		len;
	size_t	i;

	len = 0;
	while (list)
	{
		i = 0;
		while (i < list->content_size)
			ft_putchar(list->content[i++]);
		len += list->content_size;
		list = list->next;
	}
	return (len);
}

void	ft_free_list(t_list *list)
{
	if (!list)
		return ;
	ft_strdel(&list->content);
	ft_free_list(list->next);
	free(list);
}

t_list	*ft_lstnew_str(char const *content, size_t content_size)
{
	t_list	*list;

	if (!(list = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (content == NULL)
	{
		list->content = NULL;
		list->content_size = 0;
	}
	else
	{
		if (!(list->content = (char*)malloc(sizeof(char) * (content_size + 1))))
		{
			free(list);
			return (NULL);
		}
		list->content = ft_strdup(content);
		list->content_size = content_size;
	}
	list->next = NULL;
	return (list);
}

int				ft_strlen_null(char *s, int nb)
{
	int		count;

	count = 0;
	while (s[count] && nb)
	{
		if (!s[count])
			nb--;
		count++;
	}
	return (count);
}

int				ft_putstr_null(char	*s, int nb)
{
	int		len;

	len = 0;
	write(1, s, len = ft_strlen_null(s, nb));
	return (len);
}

void			ft_init_flag(t_flag *flag)
{
	flag->width = -1;
	flag->precision = 0;
	flag->sharp = 0;
	flag->zero = 0;
	flag->min = 0;
	flag->space = 0;
	flag->plus = 0;
	flag->h = 0;
	flag->hh = 0;
	flag->l = 0;
	flag->ll = 0;
	flag->L = 0;
	flag->null = 0;
}

static size_t	ft_intlen(unsigned long long nb, int base)
{
	size_t	i;

	i = 0;
	if (nb == 0)
		return (1);
	while (nb)
	{
		nb /= base;
		i++;
	}
	return (i);
}

char			*ft_itoa_base_u(unsigned long long nb, int base)
{
	size_t	len;
	char	*str;

	if (base < 2 || base > 16)
		return (NULL);
	len = ft_intlen(nb, base);
	if (!(str = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	if (nb == 0)
		str[0] = '0';
	str[len--] = '\0';
	while (nb)
	{
		if (nb % base < 10)
			str[len--] = nb % base + '0';
		else
			str[len--] = (nb - 10) % base + 'a';
		nb /= base;
	}
	return (str);
}

char			*ft_join_free(char *s1, char *s2, int op)
{
	char	*tmp;
	char	*str;

	if (op == 1)
	{
		tmp = s1;
		str = ft_strjoin(tmp, s2);
		ft_strdel(&tmp);
	}
	else
	{
		tmp = s2;
		str = ft_strjoin(s1, tmp);
		ft_strdel(&tmp);
	}
	return (str);
}
