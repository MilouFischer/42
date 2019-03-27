/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_diouxx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 11:59:06 by efischer          #+#    #+#             */
/*   Updated: 2019/03/12 11:59:08 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*ft_manage_d(va_list *arg, t_flag *flag)
{
	long long	l;
	int			nb;
	short		sh;
	char		c;

	if (flag->j)
	{
		l = va_arg(*arg, long long);
		return (ft_itoa(l));
	}
	nb = va_arg(*arg, int);
	if (flag->hh)
	{
		c = (char)nb;
		nb = c;
	}
	else if (flag->h)
	{
		sh = (short)nb;
		nb = sh;
	}
	return (ft_itoa(nb));
}

static char		*ft_manage_o(va_list *arg, t_flag *flag)
{
	unsigned int	u;
	unsigned char	c;
	unsigned short	sh;
	char			*s;

	u = va_arg(*arg, unsigned long long);
	if (flag->hh)
	{
		c = (char)u;
		u = c;
	}
	else if (flag->h)
	{
		sh = (short)u;
		u = sh;
	}
	s = ft_itoa_base_u(u, 8);
	if (flag->sharp && u)
	{
		s = ft_join_free("0", s, 2);
		flag->sharp = -1;
	}
	return (s);
}

static char		*ft_manage_u(va_list *arg, t_flag *flag)
{
	unsigned int		u;
	unsigned long long	lu;
	unsigned char		c;
	unsigned short		sh;

	if (flag->j)
	{
		lu = va_arg(*arg, unsigned long long);
		return (ft_itoa_base_u(lu, 10));
	}
	u = va_arg(*arg, unsigned int);
	if (flag->hh)
	{
		c = (unsigned char)u;
		u = c;
	}
	else if (flag->h)
	{
		sh = (unsigned short)u;
		u = sh;
	}
	return (ft_itoa_base_u(u, 10));
}

static char		*ft_manage_x(va_list *arg, t_flag *flag)
{
	unsigned int		u;
	unsigned long long	lu;
	unsigned char		c;
	unsigned short		sh;

	if (flag->j)
	{
		lu = va_arg(*arg, unsigned long long);
		return (ft_itoa_base_u(lu, 16));
	}
	u = va_arg(*arg, unsigned int);
	if (flag->hh)
	{
		c = (unsigned char)u;
		u = c;
	}
	else if (flag->h)
	{
		sh = (unsigned short)u;
		u = sh;
	}
	return (ft_itoa_base_u(u, 16));
}

char			*ft_diouxx(char c, va_list *arg, t_flag *flag)
{
	if ((c == 'o' || c == 'u' || c == 'x' || c == 'X') && (flag->space || flag->plus))
	{
		flag->space = 0;
		flag->plus = 0;
	}
	if (c == 'd' || c == 'i')
		return (ft_manage_d(arg, flag));
	else if (c == 'o')
		return (ft_manage_o(arg, flag));
	else if (c == 'u')
		return (ft_manage_u(arg, flag));
	else if (c == 'x' || c == 'X')
		return (ft_manage_x(arg, flag));
	else
		return (NULL);
}
