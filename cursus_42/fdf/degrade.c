/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   degrade.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 12:35:35 by efischer          #+#    #+#             */
/*   Updated: 2018/12/05 12:36:22 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_color(int color, unsigned int stop)
{
	unsigned int	i;

	i = 0;
	while (i < stop)
	{
		if (color > 0x00FF00 && color % 0x000100 == 0)
		{
			color -= 0x010000;
			color += 0x000100;
		}
		else if (color > 0x0000FF && color / 0x010000 == 0)
		{
			color -= 0x000100;
			color += 0x000001;
		}
		else
		{
			color += 0x010000;
			color -= 0x000001;
		}
		i++;
	}
	return (color);
}
