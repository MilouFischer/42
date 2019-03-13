#include "libft/libft.h"

int		main(int ac, char **av)
{
	char			*str;
	unsigned int	c;

	c = ft_atoi(av[1]);
	if (ac == 2)
	{
		str = ft_putunicode((wchar_t*)&c);
		ft_putstr(str);
	}
	write(1, "\n", 1);
	return (0);
}
