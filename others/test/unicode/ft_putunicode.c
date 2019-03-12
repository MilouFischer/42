/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunicode.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 12:32:14 by efischer          #+#    #+#             */
/*   Updated: 2019/03/12 13:12:15 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

unsigned int	ft_convert_to_unicode(unsigned int nb);

static void		ft_init_str(char *s, int n)
{
	int		i;

	i = 0;
	while (i < n)
		s[i++] = '\0';
}

static int		ft_check_unicode(char *s, unsigned int c)
{
	int				len;
	unsigned int	nb;

	len = ft_strlen(s);
	if (len != 16 && len != 24 && len != 32)
		return (1);
	else if (len == 16)
	{
		nb = 6;
		c >>= 6;
		if (c % 2 || !((c >> 1) % 2))
			return (1);
		c >>= 7;
		if (c != nb)
			return (1);
	}
	else if (len == 24)
	{
		nb = 14;
		c >>= 6;
		if (c % 2 || !((c >> 1) % 2))
			return (1);
		c >>= 8;
		if (c % 2 || !((c >> 1) % 2))
			return (1);
		c >>= 6;
		if (c != nb)
			return (1);
	}
	else if (len == 32)
	{
		nb = 30;
		c >>= 6;
		if (c % 2 || !((c >> 1) % 2))
			return (1);
		c >>= 8;
		if (c % 2 || !((c >> 1) % 2))
			return (1);
		c >>= 8;
		if (c % 2 || !((c >> 1) % 2))
			return (1);
		c >>= 5;
		if (c != nb)
			return (1);
	}
	return (0);
}

static void		ft_print_unicode(char *s)
{
	char	unicode[4];
	char	tmp[3];
	int		i;
	int		tmp_i;

	i = 0;
	tmp_i = 0;
	ft_init_str(unicode, 4);
	while (*s && i < 4)
	{
		tmp[tmp_i++] = *s;
		if (tmp_i == 2)
		{
			tmp[tmp_i] = '\0';
			unicode[i++] = ft_atoi_base(tmp, 16);
			tmp_i = 0;
			ft_init_str(tmp, 3);
		}
		s++;
	}
	write(1, unicode, i);
}

void				ft_putunicode(unsigned int c)
{
	if (c < 128)
	{
		ft_putchar(c);
		return ;
	}
	if (ft_check_unicode(ft_itoa_base(c, 2), c))
		c = ft_convert_to_unicode(c);
	ft_print_unicode(ft_itoa_base(c, 16));
}
