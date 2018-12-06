/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 18:50:11 by efischer          #+#    #+#             */
/*   Updated: 2018/08/29 22:48:17 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_print_comb2(void)
{
	int		nbr1;
	int		nbr2;

	nbr1 = 0;
	while (nbr1 < 99)
	{
		nbr2 = nbr1 + 1;
		while (nbr2 <= 99)
		{
			ft_putchar((nbr1 / 10) + '0');
			ft_putchar((nbr1 % 10) + '0');
			ft_putchar(' ');
			ft_putchar((nbr2 / 10) + '0');
			ft_putchar((nbr2 % 10) + '0');
			if (nbr1 != 98)
			{
				ft_putchar(',');
				ft_putchar(' ');
			}
			nbr2++;
		}
		nbr1++;
	}
}
