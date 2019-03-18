/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 12:04:54 by efischer          #+#    #+#             */
/*   Updated: 2019/03/15 16:41:51 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_lstprint(t_list *list)
{
	char	*str;
	int		len;

	len = 0;
	str = NULL;
	while (list)
	{
		str = ft_join_free(str, list->content, 1);
		if (!*list->content)
			str = ft_join_free(str, "^@", 1);
		len += list->content_size;
		list = list->next;
	}
	write(1, str, len);
	ft_strdel(&str);
	return (len);
}
