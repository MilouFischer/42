/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_matrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 18:35:57 by efischer          #+#    #+#             */
/*   Updated: 2018/12/04 15:41:25 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_matrix(int	**matrix, unsigned int x, unsigned int y)
{
	unsigned int	i;
	unsigned int	j;

	if (!matrix)
		return ;
	i = 0;
	while (i < x)
	{
		j = 0;
		while (j < y)
		{
			ft_putnbr(matrix[i][j++]);
			ft_putchar(' ');
		}
		ft_putchar('\n');
		i++;
	}
}
