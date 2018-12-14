/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 16:16:53 by efischer          #+#    #+#             */
/*   Updated: 2018/12/14 14:50:01 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float		ft_dtor(float angle)
{
	float	res;

	res = angle * M_PI / 180;
	return (res);
}

t_pixel		ft_pixel_dest(t_pixel pixel, float angle, int step, int hill)
{
	float	rad;
	t_pixel	pixel_dest;

	rad = ft_dtor(angle);
	pixel_dest = pixel;
	pixel_dest.x = step * cos(rad) + pixel.x + 0.5;
	pixel_dest.y = step * sin(rad) + pixel.y + hill + 0.5;
	return (pixel_dest);
}
