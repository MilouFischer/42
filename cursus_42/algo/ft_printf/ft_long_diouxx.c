#include "ft_printf.h"

static char		*ft_manage_long_o(va_list *arg, t_flag *flag)
{
	unsigned long	u;
	char			*s;

	u = va_arg(*arg, unsigned long);
	s = ft_itoa_base_u(u, 8);
	if (flag->sharp)
		s = ft_join_free("0", s, 2);
	return (s);
}

static char		*ft_manage_long_diu(char c, va_list *arg)
{
	long long int	nb;
	unsigned long	u;

	if (c == 'd' || c == 'i')
	{
		nb = va_arg(*arg, long long int);
		return (ft_itoa_base(nb, 10));
	}
	else
	{
		u = va_arg(*arg, unsigned long);
		return (ft_itoa_base_u(u, 10));
	}
}

char			*ft_long_diouxx(char c, va_list *arg, t_flag *flag)
{
	unsigned long	u;

	if (c == 'd' || c == 'i' || c == 'u')
		return (ft_manage_long_diu(c, arg));
	else if (c == 'o')
		return (ft_manage_long_o(arg, flag));
	else if (c == 'x' || c == 'X')
	{
		u = va_arg(*arg, unsigned long);
		return (ft_itoa_base_u(u, 16));
	}
	else
		return (NULL);
}
