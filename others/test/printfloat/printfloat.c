#include "libft/libft.h"
#include "float.h"

static char	**ft_init_pm(char **tab)
{
	tab[0] = pm1;
	tab[1] = pm2;
	tab[2] = pm3;
	tab[3] = pm4;
	tab[4] = pm5;
	tab[5] = pm6;
	tab[6] = pm7;
	tab[7] = pm8;
	tab[8] = pm9;
	tab[9] = pm10;
	tab[10] = pm11;
	tab[11] = pm12;
	tab[12] = pm13;
	tab[13] = pm14;
	tab[14] = pm15;
	tab[15] = pm16;
	tab[16] = pm17;
	tab[17] = pm18;
	tab[18] = pm19;
	tab[19] = pm20;
	tab[20] = pm21;
	tab[21] = pm22;
	tab[22] = pm23;
	tab[23] = 0;
	return (tab);
}

static void	ft_init_tab(char *tab)
{
	int	i;

	i = 0;
	while (i < 23)
		tab[i++] = '0';
	tab[i] = '\0';
}

static char	*ft_add(char *s1, char *s2)
{
	int		i;
	int		nb;
	int		ret;

	i = 0;
	ret = 0;
	while (s2[i + 1])
		i++;
	while (i > -1)
	{
		nb = s1[i] - '0' + s2[i] - '0';
		if (ret)
		{
			nb += 1;
			ret = 0;
		}
		if (nb >= 10)
		{
			nb -= 10;
			ret = 1;
		}
		s1[i] = nb + '0';
		i--;
	}
	return (s1);
}

static char	*ft_print_mentice(char *str)
{
	char	*tab;
	char	*pm[24];
	int		i;

	i = 0;
	ft_init_pm(pm);
	if (!(tab = (char*)malloc(sizeof(char) * 12)))
		return (NULL);
	while (i < 11)
		tab[i++] = '0';
	tab[i] = '\0';
	i = 0;
	while (str[i])
	{
		if (str[i] == '1')
			tab = ft_add(tab, pm[i]);
		i++;
	}
	return (tab);
}

char		*ft_printfloat(float f)
{
	int		nb;
	int		i;
	char	tab[24];
	char	*str;
	char	*tmp;

	i = 0;
	ft_init_tab(tab);
	ft_putendl(tab);
	nb = (int)f;
	str = ft_itoa(nb);
	if (f < 0)
	{
		f *= -1;
		nb *= -1;
	}
	str = ft_strjoin(str, ".");
	f -= nb;
	while (f && i < 24)
	{
		f *= 2;
		tab[i++] = (int)f + '0';
		f -= (int)f;
	}
	tmp = ft_print_mentice(tab);
	str = ft_strjoin(str, tmp);
	ft_putendl(str);
	return (NULL);
}
