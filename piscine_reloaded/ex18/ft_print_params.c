/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 17:32:36 by efischer          #+#    #+#             */
/*   Updated: 2018/11/05 17:59:31 by efischer         ###   ########.fr       */
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

int		main(int ac, char **av)
{
	if (ac > 1)
		ft_print_params(av + 1);
	return (0);
}
