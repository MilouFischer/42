/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_42.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 19:06:33 by efischer          #+#    #+#             */
/*   Updated: 2018/12/05 16:01:32 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_color(int color, int stop)
{
	int		i;

	i = 0;
	while (i < stop * 20)
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

void	ft_print_line(t_pixel pixel, unsigned int x_end, unsigned int y_end, int color)
{
	t_pixel	tmp;
	int		count_x;
	int		count_y;
	int		i;
	int		step;

	tmp = pixel;
	count_x = 0;
	count_y = 0;
	i = 0;
	step = 0;
	count_x = x_end - tmp.x;
	count_y = y_end - tmp.y;
	if (count_x >= count_y)
	{
		if (count_y)
		{
			step = count_x / count_y;
			if (count_x % count_y)
				step += 1;
		}
		while (i != count_x)
		{
			mlx_pixel_put(tmp.mlx_ptr, tmp.win_ptr, tmp.x + i, tmp.y, color);
			if (step && i % step == 0)
				tmp.y++;
			if (count_x < 0)
				i--;
			else
				i++;
		}
	}
	else
	{
		if (count_x)
		{
			step = count_y / count_x;
			if (count_y % count_x)
				step += 1;
		}
		while (i != count_y)
		{
			mlx_pixel_put(tmp.mlx_ptr, tmp.win_ptr, tmp.x, tmp.y + i, color);
			if (step && i % step == 0)
				tmp.x++;
			if (count_y < 0)
				i--;
			else
				i++;
		}
	}
}

void	ft_print_fdf(t_matrix *matrix, void *mlx_ptr, void *win_ptr)
{
	unsigned int	i;
	unsigned int	j;
	t_pixel			*pixel;
	int				color;

	i = 0;
	color = 0x00ff00;
	if (!(pixel = (t_pixel*)malloc(sizeof(t_pixel))))
		return ;
	pixel->mlx_ptr = mlx_ptr;
	pixel->win_ptr = win_ptr;
	pixel->y = PIXEL_Y;
	while (i < matrix->x)
	{
		j = 0;
		pixel->x = PIXEL_X;
		while (j < matrix->y)
		{
			if (j != matrix->y - 1)
				ft_print_line(*pixel, pixel->x + PIXEL_STEP, pixel->y, ft_color(color, matrix->matrix[i][j]));
			if (i != matrix->x - 1)
				ft_print_line(*pixel, pixel->x, pixel->y + PIXEL_STEP, ft_color(color, matrix->matrix[i][j]));
			pixel->x += PIXEL_STEP;
			j++;
		}
		pixel->y += PIXEL_STEP;
		i++;
	}
}

void	ft_fdf(t_matrix *matrix)
{
	void	*mlx_ptr;
	void	*win_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 1500, 1000, "fdf_42");
	ft_print_fdf(matrix, mlx_ptr, win_ptr);
	mlx_loop(mlx_ptr);
}

int		main(int ac, char **av)
{
	t_matrix		*matrix;

	if (ac < 2)
		return (1);
	if (!(matrix = (t_matrix*)malloc(sizeof(t_matrix))))
		return (1);
	matrix->matrix = NULL;
	ft_matrix(ft_strsplit(ft_get_map(av[1]), '\n'), matrix);
	ft_fdf(matrix);
	return (0);
}
