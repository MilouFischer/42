/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width_precision_float.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 17:41:39 by efischer          #+#    #+#             */
/*   Updated: 2019/04/12 17:47:23 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*ft_process_round(char *tmp, int i)
{
	int		ret;
	char	*str;

	ret = 1;
	if (!(str = (char*)malloc(sizeof(char) * i + 1)))
		return (NULL);
	str[i--] = '\0';
	while (i > -1)
	{
		if (ret == 1)
		{
			ret = 0;
			tmp[i]++;
		}
		if (tmp[i] - '0' >= 5)
		{
			if (tmp[i] - '0' == 10)
				tmp[i] = '0';
			ret = 1;
		}
		str[i] = tmp[i];
		i--;
	}
	return (str);
}

char			*ft_round(char *s, int n)
{
	int		i;
	char	*str;
	char	*tmp;

	i = 0;
	tmp = ft_strchr(s, '.');
	tmp++;
	while (tmp[i] && i < n)
		i++;
	if (tmp[i] - '0' >= 5)
		str = ft_process_round(tmp, i);
	else
		str = ft_strndup(tmp, i);
	tmp = ft_strsub(s, 0, tmp - s);
	str = ft_join_free(tmp, str, 3);
	ft_strdel(&s);
	return (ft_strdup(str));
}
