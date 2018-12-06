/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fight.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 13:04:12 by efischer          #+#    #+#             */
/*   Updated: 2018/09/07 14:19:13 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_fight.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
		ft_putchar(*str++);
}

void	ft_fight(t_perso *attacker, t_perso *defender, int attack)
{
	if (attacker->life <= 0 || defender->life <= 0)
		return ;
	if (attack == KICK)
		defender->life -= 15;
	else if (attack == PUNCH)
		defender->life -= 5;
	else if (attack == HEADBUTT)
		defender->life -= 20;
	ft_putstr(attacker->name);
	if (attack == KICK)
		ft_putstr(" does a judo kick on ");
	else if (attack == PUNCH)
		ft_putstr(" does a judo punch on ");
	else if (attack == HEADBUTT)
		ft_putstr(" does a judo headbutt on ");
	ft_putstr(defender->name);
	ft_putchar('\n');
	if (defender->life <= 0)
	{
		ft_putstr(defender->name);
		ft_putstr(" is dead");
		ft_putchar('\n');
	}
}
