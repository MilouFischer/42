/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_line_v2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 14:15:32 by efischer          #+#    #+#             */
/*   Updated: 2018/12/14 13:49:53 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_segment(t_pixel px, t_bres bres, int x_inc, int y_inc)
{
	int		i;
	int		d;

	i = 0;
	d = bres.ex;
	while (i <= d)
	{
		mlx_pixel_put(px.mlx_ptr, px.win_ptr, px.x, px.y, px.color);
		px.x += x_inc;
		i++;
		bres.ex -= bres.count_y;
		if (bres.ex < 0)
		{
			bres.ex += bres.count_x;
			px.y += y_inc;
		}
	}
}

static void	ft_segment_neg(t_pixel px, t_bres bres, int x_inc, int y_inc)
{
	int		i;
	int		d;

	i = 0;
	d = bres.ey;
	while (i <= d)
	{
		mlx_pixel_put(px.mlx_ptr, px.win_ptr, px.x, px.y, px.color);
		px.y += y_inc;
		i++;
		bres.ey -= bres.count_x;
		if (bres.ey < 0)
		{
			bres.ey += bres.count_y;
			px.x += x_inc;
		}
	}
}

void		ft_print_line(t_pixel pixel, int x_end, int y_end, int color)
{
	t_bres	bres;
	int		x_inc;
	int		y_inc;

	x_inc = 1;
	y_inc = 1;
	pixel.color = color;
	bres.ex = abs(x_end - pixel.x);
	bres.ey = abs(y_end - pixel.y);
	bres.count_x = 2 * bres.ex;
	bres.count_y = 2 * bres.ey;
	if (pixel.x > x_end)
		x_inc = -1;
	if (pixel.y > y_end)
		y_inc = -1;
	if (bres.ex > bres.ey)
		ft_segment(pixel, bres, x_inc, y_inc);
	else
		ft_segment_neg(pixel, bres, x_inc, y_inc);
}
