/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 16:06:12 by efischer          #+#    #+#             */
/*   Updated: 2018/09/09 17:48:22 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check.h"

int		ft_sudoku(int grid[9][9], int position, int nbr_limit)
{
	int		nbr;

	nbr = 9 - (nbr_limit - 1);
	if (position == 81)
		return (0);
	if (grid[position / 9][position % 9] != 0)
	{
		return (ft_sudoku(grid, position + 1, nbr_limit));
	}
	while (nbr_limit == 9 ? nbr <= nbr_limit : nbr >= nbr_limit)
	{
		if (!ft_check(grid, position / 9, position % 9, nbr))
		{
			grid[position / 9][position % 9] = nbr;
			if (!ft_sudoku(grid, position + 1, nbr_limit))
				return (0);
		}
		if (nbr_limit == 9)
			nbr++;
		else
			nbr--;
	}
	grid[position / 9][position % 9] = 0;
	return (1);
}
