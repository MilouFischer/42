/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_colle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 17:24:32 by efischer          #+#    #+#             */
/*   Updated: 2018/09/15 19:36:26 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_check_str.h"

int		ft_check_colle_00(char *str)
{
	int		line;
	int		i;
	char	*tab;

	line = 0;
	i = 0;
	ft_count(str, &line, &i);
	tab = "o-o";
	if (ft_check_line(tab, str, i, line) == 1)
		return (0);
	while (i < line)
	{
		tab = "| |";
		if (ft_check_line(tab, str, i, line) == 1)
			return (0);
		i++;
	}
	tab = "o-o";
	if (ft_check_line(tab, str, i, line) == 1)
		return (0);
}

int		ft_check_colle_01(char *str)
{
	int		line;
	int		i;
	char	*tab;

	line = 0;
	i = 0;
	ft_count(str, &line, &i);
	tab = "/*\\";
	if (ft_check_line(tab, str, i, line) == 1)
		return (0);
	while (i < line)
	{
		tab = "* *";
		if (ft_check_line(tab, str, i, line) == 1)
			return (0);
		i++;
	}
	tab = "\\*/";
	if (ft_check_line(tab, str, i, line) == 1)
		return (0);
}

int		ft_check_colle_02(char *str)
{
	int		line;
	int		i;
	char	*tab;

	line = 0;
	i = 0;
	ft_count(str, &line, &i);
	tab = "ABC";
	if (ft_check_line(tab, str, i, line) == 1)
		return (0);
	while (i < line)
	{
		tab = "B B";
		if (ft_check_line(tab, str, i, line) == 1)
			return (0);
		i++;
	}
	tab = "ABC";
	if (ft_check_line(tab, str, i, line) == 1)
		return (0);
}

int		ft_check_colle_03(char *str)
{
	int		line;
	int		i;
	char	*tab;

	line = 0;
	i = 0;
	ft_count(str, &line, &i);
	tab = "ABA";
	if (ft_check_line(tab, str, i, line) == 1)
		return (0);
	while (i < line)
	{
		tab = "B B";
		if (ft_check_line(tab, str, i, line) == 1)
			return (0);
		i++;
	}
	tab = "CBC";
	if (ft_check_line(tab, str, i, line) == 1)
		return (0);
}

int		ft_check_colle_04(char *str)
{
	int		line;
	int		i;
	char	*tab;

	line = 0;
	i = 0;
	ft_count(str, &line, &i);
	tab = "ABC";
	if (ft_check_line(tab, str, i, line) == 1)
		return (0);
	while (i < line)
	{
		tab = "B B";
		if (ft_check_line(tab, str, i, line) == 1)
			return (0);
		i++;
	}
	tab = "CBA";
	if (ft_check_line(tab, str, i, line) == 1)
		return (0);
}

int		ft_check_line(char *tab, char *str, int i, int line)
{
	int	j;
	int a;

	a = 0;
	j = (i + 1) * (line - 1);
	j++;
	while (j != '\n')
	{
		a = 0;
		while(tab[a])
		{
			if (tab[a] != str[j])
				return(1);
			a++;
		}
		j++;
	}
	return (0);
}
