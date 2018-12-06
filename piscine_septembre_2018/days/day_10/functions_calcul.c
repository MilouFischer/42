/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_calcul.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 13:41:33 by efischer          #+#    #+#             */
/*   Updated: 2018/09/20 14:17:33 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_add(int nb1, int nb2)
{
	return (nb1 + nb2);
}

int		ft_min(int nb1, int nb2)
{
	return (nb1 - nb2);
}

int		ft_multi(int nb1, int nb2)
{
	return (nb1 * nb2);
}

int		ft_div(int nb1, int nb2)
{
	if (nb2 != 0)
		return (nb1 / nb2);
	return (0);
}

int		ft_mod(int nb1, int nb2)
{
	if (nb2 != 0)
		return (nb1 % nb2);
	return (0);
}
