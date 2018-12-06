/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_param_to_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 19:09:04 by efischer          #+#    #+#             */
/*   Updated: 2018/09/20 19:26:51 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_par.h"

int					ft_count_par(int ac, char **av)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (i < ac)
	{
		if (av[i + 1][0])
			count++;
		i++;
	}
	return (count);
}

int					ft_strlen(char *str)
{
	int		length;

	length = 0;
	while (str[length])
	{
		length++;
	}
	return (length);
}

char				*ft_strdup(char *src)
{
	char	*dest;
	int		i;

	i = 0;
	if (!(dest = malloc(sizeof(char) * (ft_strlen(src) + 1))))
		return (0);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

void				ft_fill_struct(t_stock_par *stock_par, int nb_par,
					char **av)
{
	int		i;
	int		j;

	i = 0;
	j = 1;
	while (i < nb_par)
	{
		while (!av[j][0])
			j++;
		stock_par[i].size_param = ft_strlen(av[j]);
		stock_par[i].str = av[j];
		stock_par[i].copy = ft_strdup(av[j]);
		stock_par[i].tab = ft_split_whitespaces(av[j]);
		j++;
		i++;
	}
	stock_par[i].size_param = 0;
	stock_par[i].str = 0;
	stock_par[i].copy = 0;
	stock_par[i].tab = 0;
}

struct s_stock_par	*ft_param_to_tab(int ac, char **av)
{
	int			nb_par;
	t_stock_par	*stock_par;

	if (ac < 2)
		return (NULL);
	nb_par = ft_count_par(ac - 1, av);
	if (!(stock_par = malloc(sizeof(t_stock_par) * (nb_par + 1))))
	{
		stock_par = NULL;
		return (NULL);
	}
	ft_fill_struct(stock_par, nb_par, av);
	return (stock_par);
}
