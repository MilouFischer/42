#include "libft/libft.h"

int		main(void)
{
	char			*str;

	str = ft_putunicode(L"Je peux afficher 塆 et Ü");
	ft_putstr(str);
	write(1, "\n", 1);
	return (0);
}
