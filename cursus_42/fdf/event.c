/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 13:44:41 by efischer          #+#    #+#             */
/*   Updated: 2019/01/10 14:58:19 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_pov(int key, t_pack *p)
{
	if (key == ONE)
		ft_flat(p);
	if (key == TWO)
		ft_iso(p);
	if (key == THREE)
		ft_cavalier(p);
	ft_center(p);
	p->im = ft_print_fdf(&p->mx, p->px, p->var);
}

void	ft_move(int key, t_pack *p)
{
	if (key == A)
		p->px.x -= p->var.step1;
	if (key == S)
		p->px.y += p->var.step2;
	if (key == D)
		p->px.x += p->var.step1;
	if (key == W)
		p->px.y -= p->var.step2;
	p->im = ft_print_fdf(&p->mx, p->px, p->var);
}

void	ft_zoom(int key, t_pack *p)
{
	if (key == PLUS)
	{
		p->var.step1 += 4;
		p->var.step2 += 4;
		if (p->var.height)
			p->var.height += 2;
		p->px.x -= 2 * (p->mx.y - 1);
		p->px.y -= 2 * (p->mx.x - 1);
	}
	if (key == MINUS)
	{
		p->var.step1 -= 4;
		p->var.step2 -= 4;
		if (p->var.height)
			p->var.height -= 2;
		p->px.x += 2 * (p->mx.y - 1);
		p->px.y += 2 * (p->mx.x - 1);
	}
	p->im = ft_print_fdf(&p->mx, p->px, p->var);
}

void	ft_height(int key, t_pack *p)
{
	if (key == UP)
		p->var.height += 2;
	if (key == DOWN)
		p->var.height -= 2;
	p->im = ft_print_fdf(&p->mx, p->px, p->var);
}

void	ft_grid(int key, t_pack *p)
{
	int		i;

	i = 0;
	if (key == G)
		p->grid *= -1;
	p->im = ft_print_fdf(&p->mx, p->px, p->var);
	if (p->grid == 1)
	{
		while (i < WIDTH)
			mlx_pixel_put(p->px.mlx_ptr, p->px.win_ptr, LENGTH / 2, i++, 0xffffff);
		i = 0;
		while (i < LENGTH)
			mlx_pixel_put(p->px.mlx_ptr, p->px.win_ptr, i++, WIDTH / 2, 0xffffff);
	}
}
