/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_matrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 18:35:57 by efischer          #+#    #+#             */
/*   Updated: 2019/01/15 13:56:51 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_matrix(int **matrix, unsigned int x, unsigned int y)
{
	unsigned int	i;
	unsigned int	j;

	if (!matrix || !*matrix)
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
