/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_collatz_conjecture.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 00:08:06 by efischer          #+#    #+#             */
/*   Updated: 2018/09/07 01:16:01 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_collatz_conjecture(unsigned int base)
{
	if (base <= 1)
		return (0);
	else
	{
		if (base % 2 == 1 && base != 0)
			return (1 + ft_collatz_conjecture(base * 3 + 1));
		else
			return (1 + ft_collatz_conjecture(base / 2));
	}
}
