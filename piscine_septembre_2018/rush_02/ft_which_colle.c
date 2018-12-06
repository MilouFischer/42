/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_which_colle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 16:14:22 by efischer          #+#    #+#             */
/*   Updated: 2018/09/15 18:41:46 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_check_str.h"

void	ft_count(char *str, int *line, int *letter)
{
	while (str[*letter] != '\n')
		*letter++;
	while (*str)
	{
		while (*str != '\n')
			str++;
		*line++;
		str++;
	}
}

void	ft_which_colle(char *str)
{
	int		line;
	int		letter;
	int		last_line;

	line = 0;
	letter = 0;
	ft_count(str, &line, &letter);
	last_line = (letter + 1) * (line - 1);
	if (str[last_line] == 'A')
		ft_check_colle_03(str);
	else if (str[last_line + letter] == 'A')
		ft_check_colle_04(str);
	else
		ft_check_colle_02(str);
}
