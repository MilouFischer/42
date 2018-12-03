/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 18:41:04 by efischer          #+#    #+#             */
/*   Updated: 2018/11/05 19:19:03 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int		*range;
	int		i;

	i = 0;
	if (min >= max)
		return (NULL);
	if (!(range = (int *)malloc(sizeof(int) * (max - min))))
		return (NULL);
	while (min < max)
		range[i++] = min++;
	return (range);
}
