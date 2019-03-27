/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 11:58:40 by efischer          #+#    #+#             */
/*   Updated: 2019/03/12 12:26:23 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_init_flag(t_flag *flag)
{
	flag->width = 0;
	flag->precision = 0;
	flag->sharp = 0;
	flag->zero = 0;
	flag->min = 0;
	flag->space = 0;
	flag->plus = 0;
	flag->h = 0;
	flag->hh = 0;
	flag->l = 0;
	flag->ll = 0;
	flag->j = 0;
	flag->null = 0;
}

void	ft_manage_flag(char c, t_flag *flag)
{
	if (c == '#')
		flag->sharp = 1;
	else if (c == '0' && !flag->min)
		flag->zero = 1;
	else if (c == '+')
		flag->plus = 1;
	else if (c == '-')
		flag->min = 1;
	else if (c == '.' && !flag->precision)
		flag->precision = -1;
	else if (c == ' ')
		flag->space = 1;
}

void	ft_manage_conv_flag(char c, t_flag *flag)
{
	if (c == 'l' && flag->l)
		flag->ll = 1;
	else if (c == 'l')
		flag->l = 1;
	else if (c == 'h' && flag->h)
		flag->hh = 1;
	else if (c == 'h')
		flag->h = 1;
	else if (c == 'j')
		flag->j = 1;
}
