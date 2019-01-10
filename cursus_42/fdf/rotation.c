/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 16:16:53 by efischer          #+#    #+#             */
/*   Updated: 2019/01/09 15:50:43 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float		ft_dtor(float angle)
{
	float	res;

	res = angle * M_PI / 180;
	return (res);
}

t_pixel		ft_pixel_dest(t_pixel pixel, float angle, t_var *var, int hill)
{
	float	rad;
	t_pixel	pixel_dest;

	rad = ft_dtor(angle);
	pixel_dest = pixel;
	pixel_dest.x = var->step1 * cos(rad) + (pixel.x < 0 ? pixel.x - 0.5 : pixel.x + 0.5);
	pixel_dest.y = var->step2 * sin(rad) + (pixel.y < 0 ? pixel.y - 0.5 : pixel.y + 0.5) + hill;
	return (pixel_dest);
}
