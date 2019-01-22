/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 14:46:15 by efischer          #+#    #+#             */
/*   Updated: 2019/01/15 14:03:23 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_center(t_pack *p)
{
	t_pixel	px_dest;
	t_var	tmp;
	int		x;
	int		y;

	tmp = p->var;
	tmp.step1 *= p->mx.y - 1;
	tmp.step2 *= p->mx.y - 1;
	px_dest = ft_pixel_dest(p->px, p->var.angle1, &tmp, 0);
	tmp = p->var;
	tmp.step2 *= p->mx.x - 1;
	tmp.step1 *= p->mx.x - 1;
	px_dest = ft_pixel_dest(px_dest, p->var.angle2, &tmp, 0);
	x = px_dest.x;
	y = px_dest.y;
	p->px.x = LENGTH / 2 - (x - p->px.x) / 2;
	p->px.y = WIDTH / 2 - (y - p->px.y) / 2;
}

void		ft_rot(int key, t_pack *p)
{
	float	rot;

	rot = 5 * M_PI / 180;
	if (key == A)
	{
		p->var.angle1 += rot;
		p->var.angle2 += rot;
	}
	if (key == S)
	{
		if (p->var.step2 <= 2 * p->var.step1)
			p->var.step2 += 1;
	}
	if (key == D)
	{
		p->var.angle1 -= rot;
		p->var.angle2 -= rot;
	}
	if (key == W)
	{
		if (p->var.step2 >= -2 * p->var.step1)
			p->var.step2 -= 1;
	}
	ft_center(p);
}

static void	ft_move_hud(t_pack *p)
{
	if (p->var.rot == -1)
	{
		mlx_string_put(p->px.mlx_ptr, p->px.win_ptr, LENGTH - 90, 100,
		0xdb1702, "R");
		mlx_string_put(p->px.mlx_ptr, p->px.win_ptr, LENGTH - 250, 130,
		0x87cefa, "Move:         W");
		mlx_string_put(p->px.mlx_ptr, p->px.win_ptr, LENGTH - 250, 160,
		0x87cefa, "            A S D");
	}
	else
	{
		mlx_string_put(p->px.mlx_ptr, p->px.win_ptr, LENGTH - 90, 100,
		0x7fff00, "R");
		mlx_string_put(p->px.mlx_ptr, p->px.win_ptr, LENGTH - 250, 130,
		0x87cefa, "Rotation:     W");
		mlx_string_put(p->px.mlx_ptr, p->px.win_ptr, LENGTH - 250, 160,
		0x87cefa, "            A S D");
	}
}

void		ft_hud(t_pack *p)
{
	if (LENGTH - 250 < 0 || WIDTH < 220)
		return ;
	mlx_string_put(p->px.mlx_ptr, p->px.win_ptr, LENGTH - 250, 30, 0xffffff,
	"       HUD");
	mlx_string_put(p->px.mlx_ptr, p->px.win_ptr, LENGTH - 250, 70, 0xffa500,
	"Pov:      1 2 3 4");
	mlx_string_put(p->px.mlx_ptr, p->px.win_ptr, LENGTH - 250, 100, 0x87cefa,
	"Rotation mode:");
	ft_move_hud(p);
	mlx_string_put(p->px.mlx_ptr, p->px.win_ptr, LENGTH - 250, 190, 0x87cefa,
	"Zoom:         - +");
	mlx_string_put(p->px.mlx_ptr, p->px.win_ptr, LENGTH - 250, 220, 0x87cefa,
	"Height:       K I");
	mlx_string_put(p->px.mlx_ptr, p->px.win_ptr, LENGTH - 250, 250, 0xffffff,
	"Center:         C");
	mlx_string_put(p->px.mlx_ptr, p->px.win_ptr, LENGTH - 250, 280, 0xffffff,
	"Grid:           G");
	mlx_string_put(p->px.mlx_ptr, p->px.win_ptr, LENGTH - 250, 310, 0xffffff,
	"Hud:            H");
	mlx_string_put(p->px.mlx_ptr, p->px.win_ptr, LENGTH - 250, 340, 0xdb1702,
	"Exit:         ESC");
}

void		ft_exit(t_matrix *mx, t_pixel *px)
{
	free(px->mlx_ptr);
	free(px->win_ptr);
	ft_free_matrix(mx->matrix, mx->x);
	exit(errno);
}
