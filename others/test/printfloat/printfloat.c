#include "libft/libft.h"

static int	ft_atoi_base(const char *str, int base)
{
	unsigned int	i;
	int				nbr;

	i = 0;
	nbr = 0;
	if (base < 2 || base > 16)
		return (0);
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] && ft_isdigit(str[i]))
		nbr = str[i++] - '0' + nbr * base;
	return (str[0] == '-' ? -nbr : nbr);
}

static int	ft_natoi_base(const char *str, int base, int n)
{
	unsigned int	i;
	int				nbr;

	i = 0;
	nbr = 0;
	if (base < 2 || base > 16 || !n)
		return (0);
	while ((*str == ' ' || (*str >= 9 && *str <= 13)) && n)
	{
		str++;
		n--;
	}
	if ((str[i] == '-' || str[i] == '+') && n)
	{
		i++;
		n--;
	}
	while (str[i] && n && ft_isdigit(str[i]))
	{
		nbr = str[i++] - '0' + nbr * base;
		n--;
	}
	return (str[0] == '-' ? -nbr : nbr);
}

void	ft_printfloat(float f)
{
	int		intf;
	int		exp;
	int		men;
	int		len;
	int		i;
	char	*str;
	char	*tmp;

	i = 0;
	if ((intf = *(int*)&f) < 0)
		str = ft_itoa_base(0x80000000 - intf, 2);
	else
		str = ft_itoa_base(intf, 2);
	len = 32 - ft_strlen(str);
	if (len)
	{
		if (!(tmp = (char*)malloc(sizeof(char) * (len + 1))))
		{
			ft_strdel(&str);
			return ;
		}
		if (intf < 0)
			tmp[i++] = '1';
		while (i < len)
			tmp[i++] = '0';
		tmp[i] = '\0';
		str = ft_strjoin(tmp, str);
	}
	ft_putendl(str);
	if (*str++ == '1')
		ft_putendl("-");
	exp = ft_natoi_base(str, 2, 8);
	ft_putnbr(exp);
	ft_putchar('\n');
	str += 8;
	men = ft_atoi_base(str, 2);
	ft_putnbr(men);
	ft_putchar('\n');
}
