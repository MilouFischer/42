/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 13:54:00 by efischer          #+#    #+#             */
/*   Updated: 2018/09/02 10:42:48 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	print_line(char c1, char c2, char c3, int x)
{
	int i;

	i = 0;
	while (i < x)
	{
		if (i == 0)
			ft_putchar(c1);
		else if (i == x - 1)
			ft_putchar(c3);
		else
			ft_putchar(c2);
		i++;
	}
}

void	rush(int x, int y)
{
	int i;

	i = 0;
	if (x <= 0 || y <= 0)
		return ;
	while (i < y)
	{
		if (i == 0)
			print_line('A', 'B', 'C', x);
		else if (i == y - 1)
			print_line('C', 'B', 'A', x);
		else
			print_line('B', ' ', 'B', x);
		ft_putchar('\n');
		i++;
	}
}
