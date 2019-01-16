/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 10:43:22 by efischer          #+#    #+#             */
/*   Updated: 2019/01/15 14:02:15 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_segment(t_pixel px, t_bres bres, t_im im)
{
	int		i;
	int		d;

	i = 0;
	d = bres.ex;
	while (i <= d)
	{
		if (px.x + im.l_s * px.y < im.l_s * WIDTH && px.x + im.l_s * px.y >= 0
			&& px.x >= 0 && px.x < im.l_s)
			im.str[px.x + im.l_s * px.y] = px.color;
		px.x += bres.x_inc;
		i++;
		bres.ex -= bres.count_y;
		if (bres.ex < 0)
		{
			bres.ex += bres.count_x;
			px.y += bres.y_inc;
		}
	}
}

static void	ft_segment_neg(t_pixel px, t_bres bres, t_im im)
{
	int		i;
	int		d;

	i = 0;
	d = bres.ey;
	while (i <= d)
	{
		if (px.x + im.l_s * px.y < im.l_s * WIDTH && px.x + im.l_s * px.y >= 0
			&& px.x >= 0 && px.x < im.l_s)
			im.str[px.x + im.l_s * px.y] = px.color;
		px.y += bres.y_inc;
		i++;
		bres.ey -= bres.count_x;
		if (bres.ey < 0)
		{
			bres.ey += bres.count_y;
			px.x += bres.x_inc;
		}
	}
}

void		ft_create_window(t_pixel pixel, int x_end, int y_end, t_im im)
{
	t_bres	bres;

	bres.x_inc = 1;
	bres.y_inc = 1;
	bres.ex = abs(x_end - pixel.x);
	bres.ey = abs(y_end - pixel.y);
	bres.count_x = 2 * bres.ex;
	bres.count_y = 2 * bres.ey;
	if (pixel.x > x_end)
		bres.x_inc = -1;
	if (pixel.y > y_end)
		bres.y_inc = -1;
	if (bres.ex > bres.ey)
		ft_segment(pixel, bres, im);
	else
		ft_segment_neg(pixel, bres, im);
}
