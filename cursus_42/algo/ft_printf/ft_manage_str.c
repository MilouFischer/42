#include "ft_printf.h"

static char		*ft_c_width(char *s, t_flag *flag)
{
	int		len;
	char	*tmp;
	char	c;

	if (!(len = flag->width - 1))
	{
		ft_strdel(&s);
		return (ft_strdup("\0"));
	}
	if (!(tmp = (char*)malloc(sizeof(char) * len)))
	{
		ft_strdel(&s);
		return (NULL);
	}
	tmp[len--] = '\0';
	c = flag->zero ? '0' : ' ';
	while (len)
		tmp[len--] = c;
	tmp[len] = c;
	if (flag->min)
		s = ft_join_free(s, tmp, 3);
	else
		s = ft_join_free(tmp, s, 3);
	return (s);
}

char			*ft_manage_c(va_list *arg, t_flag *flag)
{
	char	*s;

	if (!(s = (char*)malloc(sizeof(char) * 2)))
		return (NULL);
	s[0] = va_arg(*arg, int);
	s[1] = '\0';
	if (!s[0])
	{
		if (!flag->width)
			flag->precision--;
		flag->null = 1;
	}
	if (flag->width >= 1)
		s = ft_c_width(s, flag);
	return (s);
}

static char		*ft_s_width(char *s, t_flag *flag)
{
	int		len;
	char	*tmp;
	char	c;

	len = ft_strlen(s);
	if (len < flag->width)
	{
		len = flag->width - len;
		if (!(tmp = (char*)malloc(sizeof(char) * (len + 1))))
			return (NULL);
		c = flag->zero ? '0' : ' ';
		tmp[len--] = '\0';
		while (len)
			tmp[len--] = c;
		tmp[len] = c;
		if (flag->min)
			s = ft_join_free(s, tmp, 3);
		else
			s = ft_join_free(tmp, s, 3);
	}
	return (s);
}

char			*ft_manage_s(va_list *arg, t_flag *flag)
{
	char	*s;

	if (!(s = va_arg(*arg, char*)))
	{
		if (flag->width)
			s = ft_strdup("");
		else
			return (s = ft_strdup("(null)"));
	}
	if (flag->precision > 0)
		s = ft_strndup(s, flag->precision);
	else if (flag->precision == -1)
		s = ft_strdup("");
	else
		s = ft_strdup(s);
	if (flag->width)
		s = ft_s_width(s, flag);
	return (s);
}
