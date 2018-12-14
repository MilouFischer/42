/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 09:35:30 by efischer          #+#    #+#             */
/*   Updated: 2018/12/14 18:11:17 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft/libft.h"
# include <fcntl.h>
# include <math.h>
# include "mlx.h"

typedef struct		s_matrix
{
	int				**matrix;
	int				x;
	int				y;
	int				i;
}					t_matrix;

typedef struct		s_pixel
{
	void			*mlx_ptr;
	void			*win_ptr;
	int				x;
	int				y;
	int				color;
}					t_pixel;

typedef struct		s_bres
{
	int				count_x;
	int				count_y;
	int				ex;
	int				ey;
	int				x_inc;
	int				y_inc;
}					t_bres;

typedef struct		s_im
{
	void			*im_ptr;
	int				*str;
	int				bpp;
	int				l_s;
	int				endian;
}					t_im;

typedef struct		s_var
{
	float			angle1;
	float			angle2;
	int				x;
	int				y;
	int				step;
	int				height;
}					t_var;

char				*ft_get_map(char *src);
void				ft_matrix(char **tab, t_matrix *matrix);
void				ft_fdf(t_matrix *matrix);
void				ft_print_line(t_pixel pixel, int x_end, int y_end, int color);
t_pixel				ft_pixel_dest(t_pixel pixel, float angle, int step, int hill);
int					ft_color(int color, int stop);
int					ft_color_height(int color, int stop);
void				ft_create_window(t_pixel pixel, int x_end, int y_end, int color, t_im im);

#endif
