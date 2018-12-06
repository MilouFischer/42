/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 15:36:06 by efischer          #+#    #+#             */
/*   Updated: 2018/08/31 16:01:38 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_find_next_prime(int nb)
{
	int		test;

	test = 2;
	if (nb < 2)
		return (2);
	while (test < nb)
	{
		if ((nb / test) * test == nb)
		{
			nb++;
			test = 2;
		}
		test++;
	}
	return (nb);
}
