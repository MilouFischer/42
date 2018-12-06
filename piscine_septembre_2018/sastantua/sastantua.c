/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sastantua.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 16:18:55 by efischer          #+#    #+#             */
/*   Updated: 2018/09/02 23:40:10 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int		ft_count_line(int step, int nbr_line)
{
	if (step == 1)
		return (3);
	else
	{
		nbr_line++;
		return (nbr_line + 5 + ft_count_line(step - 1, nbr_line));
	}
}

void	ft_print_line(int step, int star, int line)
{
	int		tmp;

	tmp = star / 2 + (step + 1) / 2;
	if (step % 2 == 0)
		step--;
	while (star > 0)
	{
		if (star == tmp)
		{
			while (star > tmp - step + 1 && line != 0)
			{
				if (line == 2 && star == tmp - step + 2)
					ft_putchar('$');
				else
					ft_putchar('|');
				star--;
			}
			if (line != 0)
			{
				ft_putchar('|');
				star--;
			}
		}
		ft_putchar('*');
		star--;
	}
}

void	ft_print_sastantua(int *nbr_l, int step, int *space, int *star)
{
	int		i;
	int		tmp_space;

	i = -1;
	while (++i < *nbr_l)
	{
		tmp_space = (*space)--;
		while (--tmp_space >= 0)
			ft_putchar(' ');
		ft_putchar('/');
		if ((*nbr_l == step + 2) && i >= *nbr_l - (((step - 1) / 2) * 2 + 1))
		{
			if (i == *nbr_l - (step + 1) / 2 && step > 4)
				ft_print_line(step, *star, 2);
			else
				ft_print_line(step, *star, 1);
		}
		else
			ft_print_line(step, *star, 0);
		ft_putchar('\\');
		ft_putchar('\n');
		*star += 2;
	}
	*star += ((*nbr_l + *nbr_l % 2) / 2) * 2;
	*space -= (*nbr_l + (*nbr_l)++ % 2) / 2;
}

int		shift(int step)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	while (i++ < step)
	{
		if ((i - 1) < 3)
		{
			if ((i - 1) % 2 == 1)
				j--;
		}
		else if ((i - 1) > 3)
		{
			if ((i - 1) % 2 == 0)
				k++;
			j += k;
		}
	}
	return (j);
}

void	sastantua(int size)
{
	int		space;
	int		star;
	int		nbr_line_step;
	int		i;
	int		j;

	if (size <= 0)
		return ;
	star = 1;
	i = 0;
	j = 0;
	space = ft_count_line(size, 0) - 1 + (size / 2) + shift(size);
	nbr_line_step = 3;
	while (j < size)
	{
		ft_print_sastantua(&nbr_line_step, size, &space, &star);
		j++;
	}
}
