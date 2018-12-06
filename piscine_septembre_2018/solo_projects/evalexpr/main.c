/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 19:45:59 by efischer          #+#    #+#             */
/*   Updated: 2018/09/16 21:05:44 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "io.h"
#include "ft_do_op.h"

void	ft_count(int *nbr, int *op, char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			while (str[i] >= '0' && str[i] <= '9')
				i++;
			(*nbr)++;
			(*op)++;
		}
		else if (!(str[i] == ' ' || (str[i] == '-' && (str[i + 1] >= '0'
		&& str[i + 1] <= '9'))))
		{
			(*op)++;
			i++;
		}
		else
			i++;
	}
}

int		ft_atoi(char *str, int *k)
{
	int		nbr;

	nbr = 0;
	if (str[*k] == '-')
		(*k)++;
	while (str[*k] >= '0' && str[*k] <= '9')
		nbr = str[(*k)++] - '0' + nbr * 10;
	return (nbr);
}

void	ft_fill_tab(int *tab, char *op, char *str)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	while (str[k])
	{
		if (str[k] == '-' && (str[k + 1] >= '0' && str[k + 1] <= '9'))
		{
			tab[i++] = -ft_atoi(str, &k);
			op[j++] = '0';
		}
		else if (str[k] >= '0' && str[k] <= '9')
		{
			tab[i++] = ft_atoi(str, &k);
			op[j++] = '0';
		}
		else if (str[k] != ' ')
			op[j++] = str[k++];
		else
			k++;
	}
	op[j] = '\0';
}

int		eval_expr(char *str)
{
	int		*nbr;
	char	*op;
	int		i;
	int		j;
	int		result;

	i = 0;
	j = 0;
	ft_count(&i, &j, str);
	nbr = (int *)malloc(sizeof(int) * i);
	op = (char *)malloc(sizeof(char) * (j + 1));
	ft_fill_tab(nbr, op, str);
	result = ft_calcul(nbr, op);
	free(nbr);
	free(op);
	return (result);
}

int		main(int ac, char **av)
{
	if (ac > 1)
	{
		ft_putnbr(eval_expr(av[1]));
		ft_putchar('\n');
	}
	return (0);
}
