/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 15:27:40 by efischer          #+#    #+#             */
/*   Updated: 2018/09/08 20:13:25 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_check_line(int grid[9][9], int x, int y, int test)
{
	int		i;

	i = 0;
	while (i < 9)
	{
		if (grid[x][i] == test && i != y)
			return (1);
		i++;
	}
	return (0);
}

int		ft_check_column(int grid[9][9], int x, int y, int test)
{
	int		i;

	i = 0;
	while (i < 9)
	{
		if (grid[i][y] == test && i != x)
			return (1);
		i++;
	}
	return (0);
}

int		ft_check_square(int grid[9][9], int x, int y, int test)
{
	int		square_x;
	int		square_y;
	int		square_x_limit;
	int		square_y_limit;

	square_x_limit = x - x % 3 + 3;
	square_y_limit = y - y % 3 + 3;
	square_x = square_x_limit - 3;
	while (square_x < square_x_limit)
	{
		square_y = square_y_limit - 3;
		while (square_y < square_y_limit)
		{
			if (grid[square_x][square_y] == test
				&& square_x != x && square_y != y)
				return (1);
			square_y++;
		}
		square_x++;
	}
	return (0);
}

int		ft_check(int grid[9][9], int x, int y, int test)
{
	if (ft_check_line(grid, x, y, test))
		return (1);
	if (ft_check_column(grid, x, y, test))
		return (1);
	if (ft_check_square(grid, x, y, test))
		return (1);
	return (0);
}
