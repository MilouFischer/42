#include "libft/libft.h"

void				ft_putunicode(unsigned int c);

int		main(int ac, char **av)
{
	if (ac == 2)
		ft_putunicode(ft_atoi(av[1]));
	write(1, "\n", 1);
	return (0);
}
