/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 11:09:47 by efischer          #+#    #+#             */
/*   Updated: 2018/09/12 22:20:29 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int		*tab;
	int		i;

	i = 0;
	if (min >= max || !(tab = (int *)malloc(sizeof(int) * (max - min))))
	{
		tab = NULL;
		return (tab);
	}
	while (min < max)
	{
		tab[i] = min++;
		i++;
	}
	return (tab);
}
