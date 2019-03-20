#include "libft/libft.h"

int		main(void)
{
	char			*str;

	wchar_t	ws[] = {50836};
	str = ft_putunicode(ws);
	ft_putstr(str);
	write(1, "\n", 1);
	return (0);
}
