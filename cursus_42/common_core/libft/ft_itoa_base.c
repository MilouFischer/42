#include <stdlib.h>
#include <stdio.h>

static size_t	ft_intlen(int nb, int base)
{
	size_t	i;

	i = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		nb *= -1;
		i++;
	}
	while (nb)
	{
		nb /= base;
		i++;
	}
	return (i);
}

char			*ft_itoa_base(int nb, int base)
{
	size_t	len;
	char	*str;

	if (base < 2 || base > 16)
		return (NULL);
	len = ft_intlen(nb, base);
	if (!(str = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	if (nb < 0)
	{
		str[0] = '-';
		nb *= -1;
	}
	if (nb == 0)
		str[0] = '0';
	str[len--] = '\0';
	while (nb)
	{
		if (nb % base < 10)
			str[len--] = nb % base + '0';
		else
			str[len--] = (nb - 10) % base + 'a';
		nb /= base;
	}
	return (str);
}
