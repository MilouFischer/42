/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 13:44:41 by efischer          #+#    #+#             */
/*   Updated: 2019/01/15 13:37:57 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_pov(int key, t_pack *p)
{
	if (key == ONE)
		ft_flat(p);
	if (key == TWO)
		ft_iso(p);
	if (key == THREE)
		ft_cavalier(p);
	if (key == FOUR)
		ft_top_down(p);
	p->var.angle1 = ft_dtor(p->var.angle1);
	p->var.angle2 = ft_dtor(p->var.angle2);
	ft_center(p);
}

static void	ft_move(int key, t_pack *p)
{
	if (key == I || key == K)
	{
		if (key == I)
			p->var.height += 2;
		else if (key == K)
			p->var.height -= 2;
	}
	else if (p->var.rot == 1)
		ft_rot(key, p);
	else if (key == A)
		p->px.x -= p->var.step1;
	else if (key == S)
		p->px.y += p->var.step2;
	else if (key == D)
		p->px.x += p->var.step1;
	else if (key == W)
		p->px.y -= p->var.step2;
}

static void	ft_zoom(int key, t_pack *p)
{
	if (key == PLUS)
	{
		if (p->var.step1 >= p->var.step2 && p->var.step2)
			p->var.step2 += 4;
		else if (p->var.step2)
			p->var.step2 += p->var.step2 % 4;
		p->var.step1 += 4;
		if (p->var.height)
			p->var.height += 2;
	}
	if (key == MINUS && p->var.step1 > 4 && p->var.step2 > 1)
	{
		if (p->var.step1 >= p->var.step2 && p->var.step2)
			p->var.step2 -= 4;
		else if (p->var.step2)
			p->var.step2 -= p->var.step2 % 4;
		p->var.step1 -= 4;
		if (p->var.height)
			p->var.height -= 2;
	}
	ft_center(p);
}

static void	ft_grid(int key, t_pack *p)
{
	int		i;

	i = 0;
	if (key == G)
		p->grid *= -1;
	if (p->grid == 1)
	{
		while (i < WIDTH)
			mlx_pixel_put(p->px.mlx_ptr, p->px.win_ptr, LENGTH / 2, i++,
			0xffffff);
		i = 0;
		while (i < LENGTH)
			mlx_pixel_put(p->px.mlx_ptr, p->px.win_ptr, i++, WIDTH / 2,
			0xffffff);
	}
}

int			ft_get_var(int key, t_pack *p)
{
	if (key == R)
		p->var.rot *= -1;
	else if (key == H)
		p->var.hud *= -1;
	else if (key == ONE || key == TWO || key == THREE || key == FOUR)
		ft_pov(key, p);
	else if (key == A || key == S || key == D || key == W || key == I ||
	key == K)
		ft_move(key, p);
	else if (key == PLUS || key == MINUS || key == C)
		ft_zoom(key, p);
	ft_print_fdf(&p->mx, p->px, p->var);
	if (p->var.hud == 1)
		ft_hud(p);
	if (key == G || p->grid)
		ft_grid(key, p);
	if (key == ESC)
		ft_exit(&p->mx, &p->px);
	return (0);
}
