/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_image.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 13:34:44 by efischer          #+#    #+#             */
/*   Updated: 2019/01/15 14:02:10 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_pixel	ft_print_y_line(t_matrix *mx, t_pixel pixel, t_var var,
					t_im *im)
{
	t_pixel			pixel_dest1;
	int				hill;

	hill = 0;
	if (mx->j + 1 < mx->y)
		hill = mx->matrix[mx->i][mx->j + 1];
	pixel_dest1 = ft_pixel_dest(pixel, var.angle1, &var,
	(mx->matrix[mx->i][mx->j] - hill) * var.height);
	if (mx->j != mx->y - 1)
	{
		pixel.color = ft_color_height(0x00ff00,
		mx->matrix[mx->i][mx->j] > hill ? mx->matrix[mx->i][mx->j] : hill, mx);
		ft_create_window(pixel, pixel_dest1.x, pixel_dest1.y, *im);
	}
	return (pixel_dest1);
}

static void		ft_print_x_line(t_matrix *mx, t_pixel pixel, t_var var,
					t_im *im)
{
	t_pixel			pixel_dest2;
	int				hill;

	hill = 0;
	if (mx->i + 1 < mx->x)
		hill = mx->matrix[mx->i + 1][mx->j];
	pixel_dest2 = ft_pixel_dest(pixel, var.angle2, &var,
	(mx->matrix[mx->i][mx->j] - hill) * var.height);
	if (mx->i != mx->x - 1)
	{
		pixel.color = ft_color_height(0x00ff00,
		mx->matrix[mx->i][mx->j] > hill ? mx->matrix[mx->i][mx->j] : hill, mx);
		ft_create_window(pixel, pixel_dest2.x, pixel_dest2.y, *im);
	}
}

static void		ft_print_matrix_line(t_matrix *mx, t_pixel pixel, t_var var,
				t_im *im)
{
	t_pixel			pixel_dest1;

	mx->j = 0;
	while (mx->j < mx->y)
	{
		pixel_dest1 = ft_print_y_line(mx, pixel, var, im);
		ft_print_x_line(mx, pixel, var, im);
		pixel = pixel_dest1;
		mx->j++;
	}
}

void			ft_print_fdf(t_matrix *matrix, t_pixel pixel, t_var var)
{
	t_pixel		tmp;
	int			hill;
	t_im		im;
	long		max;

	matrix->i = 0;
	hill = 0;
	im.im_ptr = mlx_new_image(pixel.mlx_ptr, 2560, 1600);
	im.str = (int *)mlx_get_data_addr(im.im_ptr, &im.bpp, &im.l_s, &im.endian);
	im.l_s /= 4;
	max = (long)pixel.x + (long)im.l_s * (long)pixel.y;
	if (max > 2147483647 || max < -2147483648)
		ft_exit(matrix, &pixel);
	while (matrix->i < matrix->x)
	{
		if (matrix->i + 1 < matrix->x)
			hill = matrix->matrix[matrix->i + 1][0];
		tmp = ft_pixel_dest(pixel, var.angle2, &var,
		(matrix->matrix[matrix->i][0] - hill) * var.height);
		ft_print_matrix_line(matrix, pixel, var, &im);
		pixel = tmp;
		matrix->i++;
	}
	mlx_put_image_to_window(pixel.mlx_ptr, pixel.win_ptr, im.im_ptr, 0, 0);
	mlx_destroy_image(pixel.mlx_ptr, im.im_ptr);
}
