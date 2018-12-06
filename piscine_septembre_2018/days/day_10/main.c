/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 13:57:20 by efischer          #+#    #+#             */
/*   Updated: 2018/09/20 17:37:51 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "io.h"
#include "functions_calcul.h"

int		ft_calcul(int nb1, int nb2, int i)
{
	int		(*f[5])(int, int);

	f[0] = &ft_add;
	f[1] = &ft_min;
	f[2] = &ft_multi;
	f[3] = &ft_div;
	f[4] = &ft_mod;
	return (f[i](nb1, nb2));
}

int		ft_do_op(char **av)
{
	int		nb1;
	int		nb2;
	char	op;

	if (av[2][0] != '+' && av[2][0] != '-' && av[2][0] != '*' && av[2][0] != '/'
		&& av[2][0] != '%')
		return (0);
	op = av[2][0];
	nb1 = ft_atoi(av[1]);
	nb2 = ft_atoi(av[3]);
	if (op == '+')
		return (ft_calcul(nb1, nb2, 0));
	if (op == '-')
		return (ft_calcul(nb1, nb2, 1));
	if (op == '*')
		return (ft_calcul(nb1, nb2, 2));
	if (op == '/')
		return (ft_calcul(nb1, nb2, 3));
	if (op == '%')
		return (ft_calcul(nb1, nb2, 4));
	return (0);
}

int		main(int ac, char **av)
{
	if (ac == 4)
	{
		ft_putnbr(ft_do_op(av));
	}
	return (0);
}
