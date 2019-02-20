/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_conv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 11:28:14 by efischer          #+#    #+#             */
/*   Updated: 2019/02/20 15:47:57 by efischer         ###   ########.fr       */
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
	else if (c == '.')
	{
		flag->width = flag->precision;
		flag->precision = 0;
		if (flag->sharp && !flag->width)
			flag->sharp = -1;
	}
	else if (c == ' ')
		flag->space = 1;
}

char	*ft_manage_conv_flag(char c, t_flag *flag)
{
	if (c == 'l' && flag->l)
		flag->ll = 1;
	else if (c == 'l')
		flag->l = 1;
	else if (c == 'h' && flag->h)
		flag->hh = 1;
	else if (c == 'h')
		flag->h = 1;
	else
		(void)flag;
	return (" conv_flag");
}

char	*ft_manage_str(char c, char	*format, va_list *arg, t_flag *flag)
{
	char			*s;
	char			*tmp;
	void			*p;
	int				len;

	(void)flag;	
	if (c == 'c')
	{
		len = 2;
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
		if (flag->precision >= 1)
		{
			if (!(len = flag->precision - 1))
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
			while (len)
				tmp[len--] = ' ';
			tmp[len] = ' ';
			if (flag->min)
				s = ft_join_free(s, tmp, 1);
			else
				s = ft_join_free(tmp, s, 2);
			ft_strdel(&tmp);
		}
		format = ft_strdup(s);
		ft_strdel(&s);
		return (format);
	}
	else if (c == 's')
	{
		if (!(s = va_arg(*arg, char*)))
			return (s = ft_strdup("(null)"));
		if (flag->precision)
			s = ft_strndup(s, flag->precision);
		else
			s = ft_strdup(s);
		if (flag->width || (flag->precision && *s))
		{
			if (flag->width < flag->precision)
				flag->width = flag->precision;
			len = ft_strlen(s);
			if (len > flag->width)
			{
				tmp = s;
				s = ft_strndup(tmp, len);
				ft_strdel(&tmp);
			}
			else if (len < flag->width)
			{
				len = flag->width - len;
				if (!(tmp = (char*)malloc(sizeof(char) * (len + 1))))
				{
					ft_strdel(&format);
					return (NULL);
				}
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
	else
	{
		p = va_arg(*arg, void*);
		if (!p)
			s = ft_strdup("0x0");
		else
		{
			s = ft_itoa_base_u((unsigned long)p, 16);
			s = ft_join_free("0x", s, 2);
		}
		if (flag->precision)
		{
			if ((len = flag->precision - ft_strlen(s)) > 0)
			{
				if (!(tmp = (char*)malloc(sizeof(char) * (len + 1))))
				{
					ft_strdel(&format);
					return (NULL);
				}
				tmp[len--] = '\0';
				while (len >= 0)
					tmp[len--] = ' ';
				s = ft_join_free(tmp, s, 2);
				ft_strdel(&tmp);
			}
		}
		return (s);
	}
}

char	*ft_float(va_list *arg, t_flag *flag)
{
	int		nb;

	(void)flag;
	nb = va_arg(*arg, int);
	return (ft_itoa(nb));
}

char	*ft_diouxx(char c, va_list *arg, t_flag *flag)
{
	int					nb;
	short				sh;
	char				ch;
	unsigned int	u;
	char				*s;
	char				*tmp;

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
		s = ft_itoa_base_u(u, 8);
		if (flag->sharp)
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
