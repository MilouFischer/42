#include "libft/libft.h"
#include <locale.h>

/*static unsigned int	ft_atoi_base(char *str, int base)
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
}*/

static void			ft_print_unicode(unsigned int nb)
{
	wchar_t				c;
	unsigned long int	tmp;

	if (nb < 128)
		write(1, &nb, 1);
	else if (nb < 2048)
	{
		c = 49280;
		c |= nb % 64;
		tmp = nb / 64;
		tmp <<= 8;
		c |= tmp;
		ft_putstr(ft_itoa_base(c, 2));
		write(1, &c, 2);
	}
	else if (nb <= 65535)
	{
		c = 14712960;
		c |= nb % 64;
		tmp = nb / 4096;
		tmp <<= 8;
		tmp |= nb % 4096 / 64;
		tmp <<= 8;
		c |= tmp;
		ft_putendl(ft_itoa_base(c, 2));
		write(1, &c, 3);
	}
/*	else if (nb <= 2097152)
	{
		c = 3766517888;
		c |= nb % 64;
		tmp = nb / 262144;
		tmp <<= 8;
		tmp |= nb % 262144 / 4096;
		tmp <<= 8;
		tmp |= nb % 4096 / 64;
		tmp <<= 8;
		c |= tmp;
		ft_putstr(ft_itoa_base(c, 2));
		write(1, &c, 4);
	}
*/	return ;
}

void				ft_putunicode(wchar_t c)
{
	ft_putnbr(c);
	ft_putchar('\n');
	ft_putendl(ft_itoa_base(c, 2));
	setlocale(LC_CTYPE, "");
	ft_print_unicode(c);
}
