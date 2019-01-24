#include "ft_printf.h"

void	ft_manage_flag(char **s, t_flag *flag)
{
	if (**s == '#')
		flag->sharp = 1;
	else if (**s == '0' && !flag->min)
		flag->zero = 1;
	else if (**s == '+' && !flag->min)
		flag->plus = 1;
	else
		(void)flag;
}

char	*ft_manage_conv_flag(char c, t_flag *flag)
{
	(void)c;
	(void)flag;
	return (" conv_flag");
}

char	*ft_manage_str(char c, char	*format, va_list *arg, t_flag *flag)
{
	char	*s;
	void	*p;

	(void)flag;	
	if (c == 'c')
	{
		if (!(s = (char*)malloc(sizeof(char) * 2)))
			return (NULL);
		s[0] = va_arg(*arg, int);
		s[1] = '\0';
		format = ft_strdup(s);
		ft_strdel(&s);
		return (format);
	}
	else if (c == 's')
	{
		s = ft_strdup(va_arg(*arg, char*));
		return (s);
	}
	else
	{
		p = va_arg(*arg, void*);
		return ((char*)p);
	}
}

char	*ft_manage_conv(char c, va_list *arg, t_flag *flag)
{
	int				nb;
	unsigned long	u;
	char			*s;
	char			*tmp;

	if (c == 'd')
	{
		nb = va_arg(*arg, int);
		return (ft_itoa(nb));
	}
	else if (c == 'i')
	{
		nb = va_arg(*arg, int);
		return (ft_itoa(nb));
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
	{
		nb = va_arg(*arg, int);
		return (ft_itoa(nb));
	}
}
