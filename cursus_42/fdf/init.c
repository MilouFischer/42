/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 11:40:30 by efischer          #+#    #+#             */
/*   Updated: 2019/01/10 14:57:48 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_var	ft_init_var(void)
{
	t_var	var;

	var.angle1 = 0;
	var.angle2 = 0;
	var.step1 = 20;
	var.step2 = 20;
	var.height = 0;
	var.rot = -1;
	return (var);
}

void	ft_flat(t_pack *p)
{
		p->var.angle1 = 0;
		p->var.angle2 = 90;
		p->var.height = 0;
		p->var.step1 = 20;
		p->var.step2 = 20;
}

void	ft_iso(t_pack *p)
{
		p->var.angle1 = 30;
		p->var.angle2 = 150;
		p->var.height = 4;
		p->var.step1 = 20;
		p->var.step2 = 20;
}

void	ft_cavalier(t_pack *p)
{
		p->var.angle1 = 0;
		p->var.angle2 = 135;
		p->var.height = 4;
		p->var.step2 = 5;
}
