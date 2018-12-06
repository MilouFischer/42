/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 11:08:49 by efischer          #+#    #+#             */
/*   Updated: 2018/09/09 21:54:21 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "io.h"
#include "check.h"
#include "sudoku.h"

int		ft_check_grid(int grid[9][9])
{
	int i;
	int j;

	i = 0;
	while (i < 9)
	{
		j = 0;
		while (j < 9)
		{
			if (grid[i][j] >= 1 && grid[i][j] <= 9)
			{
				if (ft_check(grid, i, j, grid[i][j]))
					return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int		ft_check_line_input(char **argv)
{
	int		i;
	int		j;

	i = 1;
	while (i < 10)
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] != '.' && !(argv[i][j] >= '1' && argv[i][j] <= '9'))
				return (1);
			j++;
		}
		if (j != 9)
			return (1);
		i++;
	}
	return (0);
}

int		ft_get_grid(char **argv, int grid[9][9])
{
	int		i;
	int		j;
	int		count_clue;

	i = 1;
	count_clue = 0;
	while (i < 10)
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] == '.')
				grid[i - 1][j] = 0;
			else
			{
				grid[i - 1][j] = argv[i][j] - '0';
				count_clue++;
			}
			j++;
		}
		i++;
	}
	return (count_clue);
}

int		ft_compare(int grid[9][9], int grid2[9][9])
{
	int		i;
	int		j;

	i = 0;
	while (i < 9)
	{
		j = 0;
		while (j < 9)
		{
			if (grid[i][j] != grid2[i][j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int		main(int argc, char **argv)
{
	int		grid[9][9];
	int		grid2[9][9];

	if (argc != 10 || ft_check_line_input(argv)
		|| ft_get_grid(argv, grid) < 17 || ft_check_grid(grid))
	{
		ft_putstr("Error\n");
		return (1);
	}
	ft_get_grid(argv, grid2);
	if (ft_sudoku(grid, 0, 9))
	{
		ft_putstr("Error\n");
		return (1);
	}
	ft_sudoku(grid2, 0, 1);
	if (ft_compare(grid, grid2))
	{
		ft_putstr("Error\n");
		return (1);
	}
	ft_print_grid(grid);
	return (0);
}
