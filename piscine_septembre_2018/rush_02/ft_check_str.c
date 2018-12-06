/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 14:03:41 by efischer          #+#    #+#             */
/*   Updated: 2018/09/15 16:13:57 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_check_str.h"

int		ft_check_char(char c1, char c2, char c3, char *str)
{
	int		i;
	int		count;

	i = 0;
	count = 1;
	while (str[count - 1] != '\n')
		count++;
	while (str[i])
	{
		while (str[i] != '\n')
		{
			if (str[i] != c1 && str[i] != c2 && str[i] != c3 && str[i] != ' ')
			{
				write(1, &str[i], 1);
				return (1);
			}
			i++;
		}
		i++;
		if (i % count)
		{
			write(1, &str[i], 1);
			return (1);
		}
	}
	return (0);
}

int		ft_check_str(char *str)
{
	if (*str == 'o')
	{
		if (ft_check_char('o', '-', '|', str))
			return (1);
		ft_check_colle_00(str);
	}
	else if (*str == '/')
	{
		if (ft_check_char('/', '*', '\\', str))
			return (1);
		ft_check_colle_01(str);
	}
	else if (*str == 'A')
	{
		if (ft_check_char('A', 'B', 'C', str))
			return (1);
		ft_which_colle(str);
	}
	return (0);
}
