#include "libft/libft.h"

static unsigned int	ft_atoi_base(char *str, int base)
{
	unsigned int	nb;

	nb = 0;
	if (base < 2 || base > 16)
		return (0);
	while (*str && (ft_isdigit(*str) || (*str >= 'A' && *str <= 'F')))
	{
		if (*str - '0' < 10)
			nb = *str++ - '0' + nb * base;
		else
			nb = *str++ - 'A' + 10 + nb * base;
	}
	return (nb);
}

static unsigned int	ft_c_value(char *str)
{
	unsigned int	nb;

	nb = ft_atoi_base(str, 16);
	return (nb);
}

static void			ft_print_unicode(unsigned int nb)
{
	wchar_t		tab[4];
	int			i;

	i = 0;
	if (nb < 128)
		write(1, &nb, 1);
	else if (nb < 2048)
	{
		i = 0;
		tab[0] = 3;
		tab[0] <<= 6;
		tab[1] = 1;
		tab[1] <<= 7;
		tab[1] |= nb % 64;
		tab[0] |= nb / 64;
		ft_putstr("00000000 00000000 ");
		while (i < 2)
		{
			ft_putstr(ft_itoa_base(tab[i++], 2));
			ft_putchar(' ');
		}
		ft_putchar('\n');
		write(1, tab, 2);
	}
	else if (nb <= 65535)
	{
		i = 0;
		tab[0] = 7;
		tab[0] <<= 5;
		tab[1] = 1;
		tab[1] <<= 7;
		tab[2] = tab[1];
		tab[2] |= nb % 64;
		tab[1] |= nb % 4096 / 64;
		tab[0] |= nb / 4096;
		ft_putstr("00000000 ");
		while (i < 3)
		{
			ft_putstr(ft_itoa_base(tab[i++], 2));
			ft_putchar(' ');
		}
		ft_putchar('\n');
		write(1, tab, 3);
	}
	else if (nb <= 2097152)
	{
		i = 0;
		tab[0] = 15;
		tab[0] <<= 4;
		tab[1] = 1;
		tab[1] <<= 7;
		tab[2] = tab[1];
		tab[3] = tab[1];
		tab[3] |= nb % 64;
		tab[2] |= nb % 4096 / 64;
		tab[1] |= nb % 262144 / 4096;
		tab[0] |= nb / 262144;
		while (i < 4)
		{
			ft_putstr(ft_itoa_base(tab[i++], 2));
			ft_putchar(' ');
		}
		ft_putchar('\n');
		write(1, tab, 4);
	}
	return ;
}

void				ft_putunicode(char *str)
{
	unsigned int	c;

	c = 0;
	str = ft_strupcase(str);
	if (*str == '0' && *(str + 1) == 'X')
		c = ft_c_value(str + 2);
	else
		c = ft_atoi(str);
	ft_putnbr(c);
	ft_putchar('\n');
	ft_putendl(ft_itoa_base(c, 2));
	ft_print_unicode(c);
}
