#include "libft/libft.h"

int		main(void)
{
	char			*str;

	str = ft_putunicode(L"요");
	ft_putstr(str);
	write(1, "\n", 1);
	ft_strdel(&str);
	return (0);
}
