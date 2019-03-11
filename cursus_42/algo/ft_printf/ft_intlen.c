#include "libft.h"

size_t	ft_intlen(unsigned long long nb, int base)
{
	size_t	i;

	i = 0;
	if (nb == 0)
		return (1);
	while (nb)
	{
		nb /= base;
		i++;
	}
	return (i);
}
