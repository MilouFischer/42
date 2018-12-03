/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 18:26:41 by efischer          #+#    #+#             */
/*   Updated: 2018/11/06 18:41:35 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	int		count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}

char	*ft_strdup(char *src)
{
	char	*str;
	int		i;

	i = 0;
	if (!(str = (char *)malloc(sizeof(char) * (ft_strlen(src) + 1))))
		return (0);
	while (src[i])
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
