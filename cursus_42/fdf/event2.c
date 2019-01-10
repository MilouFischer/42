/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 14:46:15 by efischer          #+#    #+#             */
/*   Updated: 2019/01/10 14:58:33 by efischer         ###   ########.fr       */
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
	p->im = ft_print_fdf(&p->mx, p->px, p->var);
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
	p->im = ft_print_fdf(&p->mx, p->px, p->var);
}

void	ft_exit(t_pack *p)
{
	int		i;

	i = 0;
	free(p->px.mlx_ptr);
	free(p->px.win_ptr);
	while (i < p->mx.x)
	{
		free(p->mx.matrix[i]);
		i++;
	}
	free(p->mx.matrix);
	exit(0);
}
