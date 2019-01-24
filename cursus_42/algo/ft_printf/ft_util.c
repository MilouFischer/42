#include "ft_printf.h"

void			ft_init_flag(t_flag *flag)
{
	flag->width = 0;
	flag->sharp = 0;
	flag->zero = 0;
	flag->min = 0;
	flag->space = 0;
	flag->plus = 0;
	flag->h = 0;
	flag->hh = 0;
	flag->l = 0;
	flag->ll = 0;
	flag->L = 0;
}

static size_t	ft_intlen(int nb, int base)
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

char			*ft_itoa_base_u(unsigned long nb,
				unsigned long base)
{
	size_t	len;
	char	*str;

	if (base < 2 || base > 16)
		return (NULL);
	len = ft_intlen(nb, base);
	if (!(str = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
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

char			*ft_join_free(char *s1, char *s2, int op)
{
	char	*tmp;
	char	*str;

	if (op == 1)
	{
		tmp = s1;
		str = ft_strjoin(tmp, s2);
		ft_strdel(&tmp);
	}
	else
	{
		tmp = s2;
		str = ft_strjoin(s1, tmp);
		ft_strdel(&tmp);
	}
	return (str);
}
