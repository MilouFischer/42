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

char	*ft_manage_str(char c, va_list *arg)
{
	char	*s;
	int		a;
	void	*p;
	
	if (c == 'c')
	{
		a = va_arg(*arg, int);
		if (!(s = (char*)malloc(sizeof(char) * 2)))
			return (NULL);
		s[0] = a;
		s[1] = '\0';
		return (s);
	}
	else if (c == 's')
	{
		s = va_arg(*arg, char*);
		return (s);
	}
	else
	{
		p = va_arg(*arg, void*);
		return ((char*)p);
	}
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
