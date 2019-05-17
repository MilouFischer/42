#include "libft/libft.h"

void	ft_putfloat(float f)
{
	int		nb;

	if (f < 0)
	{
		ft_putchar('-');
		f *= -1;
	}
	nb = f;
	ft_putnbr(nb);
	f -= nb;
	nb = 0;
	ft_putchar('.');
	while (f && f < 1)
	{
		f *= 10;
		nb = f;
		f -= nb;
		ft_putchar(nb + '0');
	}
}
