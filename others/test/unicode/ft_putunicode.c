#include "libft/libft.h"

void	ft_putunicode(unsigned char *str)
{
	unsigned char	*tmp;
	//wchar_t			c[4];
	//int				i;

	//i = 0;
	tmp = str;
	while (*tmp)
	{
		ft_putnbr(*tmp++);
		ft_putchar(' ');
	}
	ft_putchar('\n');
	tmp = str;
	while (*tmp)
	{
		ft_putstr(ft_itoa_base(*tmp++, 2));
		ft_putchar(' ');
	}
	//while (*str)
	//	c[i++] = *str++;
	write(1, "\U0000c593", 2);
}
