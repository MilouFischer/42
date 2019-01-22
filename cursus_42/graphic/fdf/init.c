/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 11:40:30 by efischer          #+#    #+#             */
/*   Updated: 2019/01/14 18:56:38 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_flat(t_pack *p)
{
	p->var.angle1 = 0;
	p->var.angle2 = 90;
	p->var.height = 0;
	p->var.step1 = 20;
	p->var.step2 = 20;
	while ((p->var.step1 * (p->mx.y - 1) > LENGTH - LENGTH / 10 ||
	p->var.step2 * (p->mx.x - 1) > WIDTH - WIDTH / 10) && p->var.step1 > 4
	&& p->var.step2 > 4)
	{
		p->var.step1 -= 4;
		p->var.step2 -= 4;
	}
}

void	ft_iso(t_pack *p)
{
	p->var.angle1 = 30;
	p->var.angle2 = 150;
	p->var.height = 8;
	p->var.step1 = 20;
	p->var.step2 = 20;
	while ((p->var.step1 * (p->mx.y - 1) > LENGTH - LENGTH / 10 ||
	p->var.step2 * (p->mx.x - 1) > WIDTH - WIDTH / 10) && p->var.step1 > 4
	&& p->var.step2 > 4)
	{
		p->var.step1 -= 4;
		p->var.step2 -= 4;
	}
}

void	ft_cavalier(t_pack *p)
{
	p->var.angle1 = 0;
	p->var.angle2 = 135;
	p->var.height = 16;
	p->var.step1 = 20;
	p->var.step2 = 5;
	while ((p->var.step1 * (p->mx.y - 1) > LENGTH - LENGTH / 10 ||
	p->var.step2 * (p->mx.x - 1) > WIDTH - WIDTH / 10) && p->var.step1 > 4
	&& p->var.step2 > 4)
	{
		p->var.step1 -= 4;
		p->var.step2 -= 1;
	}
}

void	ft_top_down(t_pack *p)
{
	p->var.angle1 = 0;
	p->var.angle2 = 90;
	p->var.height = 8;
	p->var.step1 = 20;
	p->var.step2 = 20;
	while ((p->var.step1 * (p->mx.y - 1) > LENGTH - LENGTH / 10 ||
	p->var.step2 * (p->mx.x - 1) > WIDTH - WIDTH / 10) && p->var.step1 > 4
	&& p->var.step2 > 4)
	{
		p->var.step1 -= 4;
		p->var.step2 -= 4;
	}
}
