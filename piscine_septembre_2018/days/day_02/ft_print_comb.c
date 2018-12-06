/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 17:05:02 by efischer          #+#    #+#             */
/*   Updated: 2018/08/29 18:38:58 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_print_comb(void)
{
	char	nbr1;
	char	nbr2;
	char	nbr3;

	nbr1 = '0';
	while (nbr1 <= '7')
	{
		nbr2 = ++nbr1;
		while (nbr2 <= '8')
		{
			nbr3 = ++nbr2;
			while (nbr3 <= '9')
			{
				ft_putchar(nbr1 - 1);
				ft_putchar(nbr2 - 1);
				ft_putchar(nbr3++);
				if (!(nbr1 - 1 == '7' && nbr2 - 1 == '8' && nbr3 - 1 == '9'))
				{
					ft_putchar(',');
					ft_putchar(' ');
				}
			}
		}
	}
}
