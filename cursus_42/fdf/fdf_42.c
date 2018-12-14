/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_42.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 19:06:33 by efischer          #+#    #+#             */
/*   Updated: 2018/12/14 18:51:45 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_print_matrix_line(t_matrix *mx, t_pixel pixel, t_var var, t_im *im)
{
	int				j;
	t_pixel			pixel_dest1;
	t_pixel			pixel_dest2;
	int				hill;

	j = 0;
	while (j < mx->y)
	{
		if (j + 1 < mx->y)
			hill = mx->matrix[mx->i][j + 1];
		pixel_dest1 = ft_pixel_dest(pixel, var.angle1, var.step, (mx->matrix[mx->i][j] - hill) * var.height);
		if (j != mx->y - 1)
			ft_create_window(pixel, pixel_dest1.x, pixel_dest1.y, ft_color_height(pixel.color,
			(mx->matrix[mx->i][j] > hill ? mx->matrix[mx->i][j] : hill)), *im);
		if (mx->i + 1 < mx->x)
			hill = mx->matrix[mx->i + 1][j];
		pixel_dest2 = ft_pixel_dest(pixel, var.angle2, var.step, (mx->matrix[mx->i][j] - hill) * var.height);
		if (mx->i != mx->x - 1)
			ft_create_window(pixel, pixel_dest2.x, pixel_dest2.y, ft_color_height(pixel.color,
			(mx->matrix[mx->i][j] > hill ? mx->matrix[mx->i][j] : hill)), *im);
		pixel = pixel_dest1;
		j++;
	}
}

void	ft_print_fdf(t_matrix *matrix, t_pixel pixel)
{
	t_var			var;
	t_pixel			tmp;
	int				hill;
	t_im			im;

	(void)matrix;
	matrix->i = 0;
	var.angle1 = 30;
	var.angle2 = 150;
	var.x = 1000;
	var.y = 50;
	pixel.x = var.x;
	pixel.y = var.y;
	var.step = 20;
	var.height = 5;
	im.im_ptr = mlx_new_image(pixel.mlx_ptr, 2560, 1600);
	im.str = (int *)mlx_get_data_addr(im.im_ptr, &im.bpp, &im.l_s, &im.endian);
	im.l_s /= 4;
	while (matrix->i < matrix->x)
	{
		if (matrix->i + 1 < matrix->x)
			hill = matrix->matrix[matrix->i + 1][0];
		tmp = ft_pixel_dest(pixel, var.angle2, var.step, (matrix->matrix[matrix->i][0] - hill) * var.height);
		ft_print_matrix_line(matrix, pixel, var, &im);
		pixel = tmp;
		matrix->i++;
	}
	mlx_put_image_to_window(pixel.mlx_ptr, pixel.win_ptr, im.im_ptr, 0, 0);
}

void	ft_fdf(t_matrix *matrix)
{
	t_pixel		pixel;

	pixel.color = 0;
	pixel.mlx_ptr = mlx_init();
	pixel.win_ptr = mlx_new_window(pixel.mlx_ptr, 2560, 1314, "fdf_42");
	pixel.color = 0x00ff00;
	ft_print_fdf(matrix, pixel);
	mlx_loop(pixel.mlx_ptr);
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
