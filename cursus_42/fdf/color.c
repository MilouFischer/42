/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 12:35:35 by efischer          #+#    #+#             */
/*   Updated: 2019/01/15 13:24:09 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_test_int_max(int height)
{
	long	max;

	max = height * 0x010000;
	return (max > 2147483647 || max < -2147483648);
}

static int	ft_set_color(int color, int height)
{
	if (ft_test_int_max(height))
		return (color);
	if (height != 0)
	{
		if (height > 0)
		{
			if (height <= 225)
				color += 0x010000 * height;
			else if (height <= 450)
				color = 0xffff00 - 0x000100 * (height - 225);
			else
				color = 0xff0000;
		}
		else
		{
			if (height >= -225)
				color -= 0x000001 * height;
			else if (height >= -450)
				color = 0x00ffff - (0x000100 * (height - 225));
			else
				color = 0x0000ff;
		}
	}
	return (color);
}

int			ft_color_height(int color, int height, t_matrix *mx)
{
	float		pad;

	pad = 1;
	if (height > 0 && mx->max != 0)
		pad = 256 / (float)mx->max;
	else if (height < 0 && mx->min != 0)
		pad = 256 / (float)mx->min * -1;
	height *= pad;
	return (ft_set_color(color, height));
}
