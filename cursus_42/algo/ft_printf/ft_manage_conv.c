/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_conv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 11:28:14 by efischer          #+#    #+#             */
/*   Updated: 2019/02/22 17:24:48 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
}

static char		*ft_c_width(char *s, t_flag *flag)
{
	int		len;
	char	*tmp;
	char	c;

	if (!(len = flag->width - 1))
	{
		ft_strdel(&s);
		return (ft_strdup("\0"));
	}
	if (!(tmp = (char*)malloc(sizeof(char) * len)))
	{
		ft_strdel(&s);
		return (NULL);
	}
	tmp[len--] = '\0';
	c = flag->zero ? '0' : ' ';
	while (len)
		tmp[len--] = c;
	tmp[len] = c;
	if (flag->min)
		s = ft_join_free(s, tmp, 1);
	else
		s = ft_join_free(tmp, s, 2);
	ft_strdel(&tmp);
	return (s);
}

static char		*ft_manage_c(va_list *arg, t_flag *flag)
{
	char	*s;

	if (!(s = (char*)malloc(sizeof(char) * 2)))
		return (NULL);
	s[0] = va_arg(*arg, int);
	s[1] = '\0';
	if (!s[0])
	{
		if (!flag->width)
			flag->precision--;
		flag->null = 1;
	}
	if (flag->width >= 1)
		s = ft_c_width(s, flag);
	return (s);
}

static char		*ft_s_width(char *s, t_flag *flag)
{
	int		len;
	char	*tmp;
	char	c;

	len = ft_strlen(s);
	if (len < flag->width)
	{
		len = flag->width - len;
		if (!(tmp = (char*)malloc(sizeof(char) * (len + 1))))
			return (NULL);
		c = flag->zero ? '0' : ' ';
		tmp[len--] = '\0';
		while (len)
			tmp[len--] = c;
		tmp[len] = c;
		if (flag->min)
			s = ft_join_free(s, tmp, 1);
		else
			s = ft_join_free(tmp, s, 2);
		ft_strdel(&tmp);
	}
	return (s);
}

static char		*ft_manage_s(va_list *arg, t_flag *flag)
{
	char	*s;

	if (!(s = va_arg(*arg, char*)))
	{
		if (flag->width)
			s = ft_strdup("");
		else
			return (s = ft_strdup("(null)"));
	}
	if (flag->precision > 0)
		s = ft_strndup(s, flag->precision);
	else if (flag->precision == -1)
		s = ft_strdup("");
	else
		s = ft_strdup(s);
	if (flag->width)
		s = ft_s_width(s, flag);
	return (s);
}

static char		*ft_p_precision(char *s, t_flag *flag)
{
	int		len;
	char	*tmp;

	if ((len = flag->precision - ft_strlen(s)) > 0)
	{
		if (!(tmp = (char*)malloc(sizeof(char) * (len + 1))))
			return (NULL);
		tmp[len--] = '\0';
		while (len >= 0)
			tmp[len--] = '0';
		if (flag->min)
			s = ft_join_free(s, tmp, 1);
		else
			s = ft_join_free(tmp, s, 2);
		ft_strdel(&tmp);
	}
	return (s);
}

static char		*ft_p_width(char *s, t_flag *flag)
{
	int		len;
	char	*tmp;

	if ((len = flag->width - ft_strlen(s)) > 0)
	{
		if (!(tmp = (char*)malloc(sizeof(char) * (len + 1))))
			return (NULL);
		tmp[len--] = '\0';
		while (len >= 0)
			tmp[len--] = ' ';
		if (flag->min)
			s = ft_join_free(s, tmp, 1);
		else
			s = ft_join_free(tmp, s, 2);
		ft_strdel(&tmp);
	}
	return (s);
}

static char		*ft_manage_p(va_list *arg, t_flag *flag)
{
	void	*p;
	char	*s;

	p = va_arg(*arg, void*);
	if (flag->precision == -1)
		s = ft_strdup("");
	else
		s = ft_itoa_base_u((unsigned long)p, 16);
	if (flag->precision)
		s = ft_p_precision(s, flag);
	s = ft_join_free("0x", s, 2);
	if (flag->width)
		s = ft_p_width(s, flag);
	return (s);
}

char	*ft_manage_str(char c, va_list *arg, t_flag *flag)
{
	if (c == 'c')
		return (ft_manage_c(arg, flag));
	else if (c == 's')
		return (ft_manage_s(arg, flag));
	else
		return (ft_manage_p(arg, flag));
}

char	*ft_float(va_list *arg, t_flag *flag)
{
	double	f;
	char	*str;

	(void)flag;
	f = va_arg(*arg, double);
	//str = ft_printfloat(f);
	//ft_putendl(str);
	str = "float";
	return (str);
}

static char		*ft_manage_d(va_list *arg, t_flag *flag)
{
	int		nb;
	short	sh;
	char	c;

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
	unsigned int	u;

	u = va_arg(*arg, unsigned long long);
	if (!flag->l)
		u = (unsigned)u;
	flag->space = 0;
	flag->plus = 0;
	return (ft_itoa_base_u(u, 10));
}

char	*ft_diouxx(char c, va_list *arg, t_flag *flag)
{
	int				nb;
	unsigned int	u;

	if (c == 'd')
		return (ft_manage_d(arg, flag));
	else if (c == 'i')
	{
		nb = va_arg(*arg, int);
		return (ft_itoa(nb));
	}
	else if (c == 'o')
		return (ft_manage_o(arg, flag));
	else if (c == 'u')
		return (ft_manage_u(arg, flag));
	else if (c == 'x' || c == 'X')
	{
		u = va_arg(*arg, unsigned int);
		return (ft_itoa_base_u(u, 16));
	}
	else
		return (NULL);
}

char	*ft_long_diouxx(char c, va_list *arg, t_flag *flag)
{
	long long int	nb;
	unsigned long	u;
	char			*s;
	char			*tmp;

	if (c == 'd')
	{
		nb = va_arg(*arg, long long int);
		return (ft_itoa_base(nb, 10));
	}
	else if (c == 'i')
	{
		nb = va_arg(*arg, long long int);
		return (ft_itoa_base_u(nb, 10));
	}
	else if (c == 'o')
	{
		u = va_arg(*arg, unsigned long);
		s = ft_itoa_base_u(u, 8);
		if (flag->sharp)
		{
			tmp = s;
			s = ft_strjoin("0", tmp);
			ft_strdel(&tmp);
		}
		return (s);
	}
	else if (c == 'u')
	{
		u = va_arg(*arg, unsigned long);
		return (ft_itoa_base_u(u, 10));
	}
	else if (c == 'x' || c == 'X')
	{
		u = va_arg(*arg, unsigned long);
		s = ft_itoa_base_u(u, 16);
		return (s);
	}
	else
		return (NULL);
}

char	*ft_manage_conv(char c, va_list *arg, t_flag *flag)
{
	char	*str;

	if (c == 'f')
		str = ft_float(arg, flag);
	else if (flag->l || flag->ll)
		str = ft_long_diouxx(c, arg, flag);
	else
		str = ft_diouxx(c, arg, flag);
	return (str);
}
