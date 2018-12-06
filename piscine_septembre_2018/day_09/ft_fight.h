/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fight.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 13:04:12 by efischer          #+#    #+#             */
/*   Updated: 2018/09/07 16:51:20 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FIGHT_H
# define FT_FIGHT_H

typedef struct	s_perso
{
	float	life;
	char	*name;
}				t_perso;

enum			e_attack
{
	PUNCH,
	KICK,
	HEADBUTT
};

#endif
