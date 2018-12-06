/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_compact.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 11:44:35 by efischer          #+#    #+#             */
/*   Updated: 2018/09/07 12:09:10 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		ft_compact(char **tab, int lenght)
{
	int		i;

	i = 0;
	while (tab[i])
	{
		if (*tab[i] == 0)
		{
			if (tab[i] == 0)
				*tab[i] = *tab[i + 1];
			lenght--;
		}
		i++;
	}
	return (lenght);
}

int		main(int argc, char **argv)
{
	printf("%d", ft_compact(argv, argc));
	return (0);
}
