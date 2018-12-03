/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 17:57:51 by efischer          #+#    #+#             */
/*   Updated: 2018/11/05 18:24:50 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_putstr(char *str)
{
	while (*str)
		ft_putchar(*str++);
	ft_putchar('\n');
}

void	ft_print_params(char **av)
{
	while (*av)
		ft_putstr(*av++);
}

int		ft_strcmp(char *s1, char *s2)
{
	while (*s1 == *s2)
	{
		if (!*s1 && !*s2)
			return (0);
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void	ft_sort_params(char **av)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	while (av[i])
	{
		j = i + 1;
		while (av[j])
		{
			if (ft_strcmp(av[i], av[j]) > 0)
			{
				tmp = av[i];
				av[i] = av[j];
				av[j] = tmp;
			}
			j++;
		}
		i++;
	}
	ft_print_params(av);
}

int		main(int ac, char **av)
{
	if (ac > 1)
		ft_sort_params(av + 1);
	return (0);
}
