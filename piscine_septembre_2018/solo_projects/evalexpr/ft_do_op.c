/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 11:01:25 by efischer          #+#    #+#             */
/*   Updated: 2018/09/16 21:04:56 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_do_op.h"

int		ft_do_op(int nb1, char op, int nb2)
{
	if (op == '+')
		return (nb1 + nb2);
	if (op == '-')
		return (nb1 - nb2);
	if (op == '*')
		return (nb1 * nb2);
	if (op == '/')
		return (nb1 / nb2);
	if (op == '%')
		return (nb1 % nb2);
	else
		return (0);
}

int		ft_check_op(int *nbr, int *i, char *str, int *j)
{
	int		res;

	if (str[*j] == '0')
	{
		(*j)++;
		return (nbr[(*i)++]);
	}
	else if (str[*j] == '(')
	{
		(*j)++;
		res = ft_non_priority_calcul(nbr, i, str, j);
		(*j)++;
		return (res);
	}
	else
		return (0);
}

int		ft_priority_calcul(int *nbr, int *i, char *str, int *j)
{
	int		nb1;
	int		nb2;
	char	op;

	nb1 = ft_check_op(nbr, i, str, j);
	while (str[*j] == '*' || str[*j] == '/' || str[*j] == '%')
	{
		op = str[(*j)++];
		nb2 = ft_check_op(nbr, i, str, j);
		nb1 = ft_do_op(nb1, op, nb2);
	}
	return (nb1);
}

int		ft_non_priority_calcul(int *nbr, int *i, char *str, int *j)
{
	int		nb1;
	int		nb2;
	char	op;

	nb1 = ft_priority_calcul(nbr, i, str, j);
	while (str[*j] == '+' || str[*j] == '-')
	{
		op = str[(*j)++];
		nb2 = ft_priority_calcul(nbr, i, str, j);
		nb1 = ft_do_op(nb1, op, nb2);
	}
	return (nb1);
}

int		ft_calcul(int *nbr, char *str)
{
	int		res;
	int		i;
	int		j;

	i = 0;
	j = 0;
	res = ft_non_priority_calcul(nbr, &i, str, &j);
	return (res);
}
