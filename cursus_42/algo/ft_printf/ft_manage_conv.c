#include "ft_printf.h"

char	*ft_manage_flag(char c)
{
	(void)c;
	return (" flag");
}

char	*ft_manage_conv_flag(char c)
{
	(void)c;
	return (" conv_flag");
}

char	*ft_manage_str(char c, char	*format, va_list *arg)
{
	char	*s;
	void	*p;
	char	*tmp;
	
	if (c == 'c')
	{
		if (!(s = (char*)malloc(sizeof(char) * 2)))
			return (NULL);
		s[0] = va_arg(*arg, int);
		s[1] = '\0';
	}
	else if (c == 's')
		s = va_arg(*arg, char*);
	else if (c == 'p')
	{
		p = va_arg(*arg, void*);
		return ((char*)p);
	}
	tmp = format;
	format = ft_strjoin(tmp, s);
	ft_strdel(&tmp);
	if (c == 'c')
		ft_strdel(&s);
	return (format);
}

char	*ft_manage_conv(char c, va_list *arg)
{
	int				nb;
	unsigned long	u;
	char			*s;

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
		return (ft_itoa_base_u(u, 8));
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
		return (c == 'X' ? ft_strupcase(s) : s);
	}
	else
	{
		nb = va_arg(*arg, int);
		return (ft_itoa(nb));
	}
}
