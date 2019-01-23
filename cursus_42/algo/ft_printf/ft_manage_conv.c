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
	char	a[2];
	
	if (c == 'c')
	{
		a[0] = va_arg(*arg, int);
		a[1] = '\0';
		s = (char*)a;
		return (s);
	}
	else if (c == 's')
	{
		s = va_arg(*arg, char *);
		return (s);
	}
	else
		return ("P");
}

char	*ft_manage_conv(char c, va_list *arg)
{
	int		nb;

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
		nb = va_arg(*arg, int);
		return (ft_itoa_base(nb, 8));
	}
	else if (c == 'u')
	{
		nb = va_arg(*arg, int);
		return (ft_itoa_base(nb, 10));
	}
	else if (c == 'x')
	{
		nb = va_arg(*arg, int);
		return (ft_itoa_base(nb, 16));
	}
	else if (c == 'X')
	{
		nb = va_arg(*arg, int);
		return (ft_strupcase(ft_itoa_base(nb, 16)));
	}
	else
		return ("f");
}
