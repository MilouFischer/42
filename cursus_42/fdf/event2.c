/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 14:46:15 by efischer          #+#    #+#             */
/*   Updated: 2019/01/11 17:37:03 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_center(t_pack *p)
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
	ft_print_fdf(&p->mx, p->px, p->var);
}

void	ft_rot(int key, t_pack *p)
{
	if (key == A)
	{
		p->var.angle1 += 5;
		p->var.angle2 += 5;
	}
	if (key == S)
	{
		p->var.step2 += 1;
	}
	if (key == D)
	{
		p->var.angle1 -= 5;
		p->var.angle2 -= 5;
	}
	if (key == W)
	{
		p->var.step2 -= 1;
	}
	ft_center(p);
	ft_print_fdf(&p->mx, p->px, p->var);
}

void	ft_free_matrix(t_matrix *mx)
{
	int		i;

	i = 0;
	while (i < mx->x)
	{
		free(mx->matrix[i]);
		mx->matrix[i] = NULL;
		i++;
	}
	free(mx->matrix);
	mx->matrix = NULL;
}

void	ft_exit(t_pack *p)
{
	free(p->px.mlx_ptr);
	free(p->px.win_ptr);
	ft_free_matrix(&p->mx);
	exit(0);
}
