/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 13:52:40 by efischer          #+#    #+#             */
/*   Updated: 2018/09/07 16:44:24 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_putstr(char *str)
{
	while (*str)
		ft_putchar(*str++);
}

int		ft_compare(char *s1, char *s2)
{
	while (*s1)
	{
		if ((*s1) != (*s2))
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (*s2)
		return (-1);
	return (0);
}

char	**ft_sort_params(int argc, char **argv)
{
	int		i;
	int		j;
	char	*tmp;

	i = 1;
	while (i < argc)
	{
		j = 1;
		while (j < argc)
		{
			if (ft_compare(argv[i], argv[j]) < 0)
			{
				tmp = argv[i];
				argv[i] = argv[j];
				argv[j] = tmp;
			}
			j++;
		}
		i++;
	}
	return (argv);
}

int		main(int argc, char **argv)
{
	int		i;

	i = 1;
	argv = ft_sort_params(argc, argv);
	while (i < argc)
	{
		ft_putstr(argv[i]);
		ft_putchar('\n');
		i++;
	}
	return (0);
}
