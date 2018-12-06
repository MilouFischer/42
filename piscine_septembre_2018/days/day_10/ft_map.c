/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 13:10:11 by efischer          #+#    #+#             */
/*   Updated: 2018/09/20 17:32:37 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_map(int *tab, int length, int (*f)(int))
{
	int		*dest;
	int		i;

	i = 0;
	if (!(dest = (int *)malloc(sizeof(int) * length)))
	{
		dest = NULL;
		return (0);
	}
	while (i < length)
	{
		dest[i] = f(tab[i]);
		i++;
	}
	return (dest);
}
