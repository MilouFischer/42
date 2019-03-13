#include "libft/libft.h"

int		main(int ac, char **av)
{
	char	*str;

	if (ac == 2)
	{
		str = ft_putunicode(ft_atoi(av[1]));
		ft_putstr(str);
	}
	write(1, "\n", 1);
	return (0);
}
