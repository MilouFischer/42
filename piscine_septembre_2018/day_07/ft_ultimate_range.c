/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 12:20:16 by efischer          #+#    #+#             */
/*   Updated: 2018/09/12 22:21:02 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_ultimate_range(int **range, int min, int max)
{
	int		length;
	int		i;

	i = 0;
	length = max - min;
	if (min >= max)
	{
		range = NULL;
		return (0);
	}
	if (!(*range = (int *)malloc(sizeof(int) * length)))
		return (0);
	while (i < length)
	{
		range[0][i] = min++;
		i++;
	}
	return (length);
}
