/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 16:02:51 by efischer          #+#    #+#             */
/*   Updated: 2018/12/05 18:42:28 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_print_line(t_pixel pixel, int x_end, int y_end, int color)
{
	t_pixel	tmp;
	int		a;
	int		b;

	tmp = pixel;
	a = (y_end - tmp.y) / (x_end - tmp.x);
	b = tmp.y - a * tmp.x;
	while (tmp.x != x_end)
	{
		tmp.y = a * tmp.x + b;
		mlx_pixel_put(pixel.mlx_ptr, pixel.win_ptr, tmp.x, tmp.y, color);
		tmp.x++;
	}
}

int		main()
{
	t_pixel		*pixel;
	int			i;

	i = 0;
	if (!(pixel = (t_pixel*)malloc(sizeof(t_pixel))))
		return (1);
	pixel->x = PIXEL_X;
	pixel->y = PIXEL_Y;
	pixel->mlx_ptr = mlx_init();
	pixel->win_ptr = mlx_new_window(pixel->mlx_ptr, 1500, 1000, "test line");
	ft_print_line(*pixel, 1000, 500, 0xff0000);
	mlx_loop(pixel->mlx_ptr);
	return (0);
}
