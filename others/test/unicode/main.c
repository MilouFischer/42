#include "libft/libft.h"

int		main(void)
{
	char			*str;

	str = ft_putunicode(L"塆");
	ft_putstr(str);
	write(1, "\n", 1);
	return (0);
}
