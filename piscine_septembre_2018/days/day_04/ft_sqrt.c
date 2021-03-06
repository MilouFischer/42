/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 11:59:56 by efischer          #+#    #+#             */
/*   Updated: 2018/09/04 17:38:13 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_sqrt(int nb)
{
	int		test;

	test = 1;
	while (test * test != nb)
	{
		if (nb == 0 || test >= nb / 2)
			return (0);
		test++;
	}
	return (test);
}
