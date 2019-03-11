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

static char		*ft_manage_s(va_list *arg, t_flag *flag)
{
	int		len;
	char	*s;
	char	*tmp;
	char	c;

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
	{
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
	}
	return (s);
}

static char		*ft_manage_p(va_list *arg, t_flag *flag)
{
	int		len;
	void	*p;
	char	*s;
	char	*tmp;

	p = va_arg(*arg, void*);
	if (flag->precision == -1)
		s = ft_strdup("");
	else
		s = ft_itoa_base_u((unsigned long)p, 16);
	if (flag->precision)
	{
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
	}
	s = ft_join_free("0x", s, 2);
	if (flag->width)
	{
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
	}
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

char	*ft_diouxx(char c, va_list *arg, t_flag *flag)
{
	int				nb;
	short			sh;
	char			ch;
	unsigned short	u_sh;
	unsigned char	u_ch;
	unsigned int	u;
	char			*s;
	char			*tmp;

	if (c == 'd')
	{
		nb = va_arg(*arg, int);
		if (flag->hh)
		{
			ch = (char)nb;
			nb = ch;
		}
		else if (flag->h)
		{
			sh = (short)nb;
			nb = sh;
		}
		return (ft_itoa(nb));
	}
	else if (c == 'i')
	{
		nb = va_arg(*arg, int);
		return (ft_itoa(nb));
	}
	else if (c == 'o')
	{
		u = va_arg(*arg, unsigned long long);
		if (flag->hh)
		{
			u_ch = (char)u;
			u = u_ch;
		}
		else if (flag->h)
		{
			u_sh = (short)u;
			u = u_sh;
		}
		s = ft_itoa_base_u(u, 8);
		if (flag->sharp && u)
		{
			tmp = s;
			s = ft_strjoin("0", tmp);
			ft_strdel(&tmp);
			flag->sharp = -1;
		}
		return (s);
	}
	else if (c == 'u')
	{
		u = va_arg(*arg, unsigned long long);
		if (!flag->l)
			u = (unsigned)u;
		flag->space = 0;
		flag->plus = 0;
		return (ft_itoa_base_u(u, 10));
	}
	else if (c == 'x' || c == 'X')
	{
		u = va_arg(*arg, unsigned int);
		s = ft_itoa_base_u(u, 16);
		return (s);
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
