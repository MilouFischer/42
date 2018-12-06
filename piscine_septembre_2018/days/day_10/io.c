/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 14:27:27 by efischer          #+#    #+#             */
/*   Updated: 2018/09/20 17:37:00 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nbr)
{
	if (nbr < 0)
	{
		ft_putchar('-');
		ft_putnbr(nbr * -1);
	}
	else if (nbr < 10)
		ft_putchar(nbr + '0');
	else
	{
		ft_putnbr(nbr / 10);
		ft_putnbr(nbr % 10);
	}
}

int		ft_atoi(char *str)
{
	int		i;
	int		nbr;

	i = 0;
	nbr = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if ((str[i] == '-' || str[i] == '+') && (str[i + 1] >= '0'
		&& str[i + 1] <= '9'))
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = str[i] - '0' + nbr * 10;
		i++;
	}
	if (str[0] == '-')
		return (-nbr);
	return (nbr);
}
