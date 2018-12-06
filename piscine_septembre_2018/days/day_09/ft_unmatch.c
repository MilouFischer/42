/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unmatch.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 15:47:46 by efischer          #+#    #+#             */
/*   Updated: 2018/09/07 15:58:27 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_unmatch(int *tab, int lenght)
{
	int		i;
	int		j;
	int		test;
	int		solo;

	i = 0;
	while (i < lenght)
	{
		j = 0;
		test = 0;
		while (j < lenght)
		{
			if (tab[i] == tab[j])
				test++;
			j++;
		}
		if (test % 2)
			solo = tab[i];
		i++;
	}
	return (solo);
}
