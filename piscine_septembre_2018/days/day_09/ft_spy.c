/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 01:30:58 by efischer          #+#    #+#             */
/*   Updated: 2018/09/07 09:35:58 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
		ft_putchar(*str++);
}

void	ft_lowcase(char *str)
{
	while (*str)
	{
		if (*str >= 'A' && *str <= 'Z')
			*str += 32;
		str++;
	}
}

int		ft_compare(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
		{
			return (0);
		}
		s1++;
		s2++;
	}
	ft_putstr("Alert!!!\n");
	return (1);
}

int		ft_alert(char *str, char *s1, char *s2, char *s3)
{
	ft_lowcase(str);
	while (*str == ' ')
		str++;
	if (*str == 'p')
	{
		if (ft_compare(str, s1))
			return (1);
	}
	else if (*str == 'a')
	{
		if (ft_compare(str, s2))
			return (1);
	}
	else if (*str == 'b')
	{
		if (ft_compare(str, s3))
			return (1);
	}
	return (0);
}
