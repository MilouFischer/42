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
	void	*p;
	
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
	{
		return (s);
	}
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
		return ("i");
	else if (c == 'o')
		return ("o");
	else if (c == 'u')
		return ("u");
	else if (c == 'x')
		return ("x");
	else if (c == 'X')
		return ("X");
	else
		return ("f");
}
