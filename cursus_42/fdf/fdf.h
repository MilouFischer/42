/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 09:35:30 by efischer          #+#    #+#             */
/*   Updated: 2019/01/11 17:37:18 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft/libft.h"
# include <fcntl.h>
# include <math.h>
# include "mlx.h"
# define ONE 0x53
# define TWO 0x54
# define THREE 0x55
# define A 0x00
# define S 0x01
# define D 0x02
# define G 0x05
# define C 0x08
# define W 0x0D
# define R 0x0F
# define PLUS 0x45
# define MINUS 0x4E
# define UP 0x22
# define DOWN 0x28
# define ESC 0x35
# define LENGTH 2560
# define WIDTH 1396

typedef struct	s_matrix
{
	int			**matrix;
	int			x;
	int			y;
	int			i;
	int			j;
	int			min;
	int			max;
}				t_matrix;

typedef struct	s_pixel
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			x;
	int			y;
	int			color;
}				t_pixel;

typedef struct	s_bres
{
	int			count_x;
	int			count_y;
	int			ex;
	int			ey;
	int			x_inc;
	int			y_inc;
}				t_bres;

typedef struct	s_im
{
	void		*im_ptr;
	int			*str;
	int			bpp;
	int			l_s;
	int			endian;
}				t_im;

typedef struct	s_var
{
	float		angle1;
	float		angle2;
	int			step1;
	int			step2;
	int			height;
	int			rot;
}				t_var;

typedef struct	s_pack
{
	t_pixel		px;
	t_matrix	mx;
	t_var		var;
	t_im		im;
	int			grid;
}				t_pack;

char			*ft_get_map(char *src);
void			ft_matrix(char **tab, t_matrix *matrix);
void			ft_print_line(t_pixel pixel, int x_end, int y_end, int color);
t_pixel			ft_pixel_dest(t_pixel pixel, float angle, t_var *var, int hill);
int				ft_color(int color, int stop);
int				ft_color_height(int color, int stop, t_matrix *mx);
void			ft_create_window(t_pixel pixel, int x_end, int y_end, t_im im);
void			ft_move(int key, t_pack *p);
void			ft_print_fdf(t_matrix *matrix, t_pixel pixel, t_var var);
void			ft_pov(int key, t_pack *p);
void			ft_zoom(int key, t_pack *p);
void			ft_height(int key, t_pack *p);
void			ft_center(t_pack *p);
t_var			ft_init_var(void);
void			ft_flat(t_pack *p);
void			ft_iso(t_pack *p);
void			ft_cavalier(t_pack *p);
void			ft_grid(int key, t_pack *p);
float			ft_dtor(float angle);
void			ft_rot(int key, t_pack *p);
void			ft_exit(t_pack *p);
int				ft_check_str(char *s);
void			ft_free_matrix(t_matrix *mx);

#endif
