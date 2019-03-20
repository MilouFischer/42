#include "ft_printf.h"

char			*ft_manage_unicode_char(va_list *arg, t_flag *flag)
{
	wchar_t	*ws;
	char	*s;

	if (!(ws = (wchar_t*)malloc(sizeof(wchar_t) * 2)))
		return (NULL);
	ws[0] = va_arg(*arg, unsigned int);
	ws[1] = '\0';
	if (!ws[0])
	{
		if (!flag->width)
			flag->precision--;
		flag->null = 1;
		s = ft_strdup("\0");
	}
	else
		s = ft_putunicode(ws);
	free(ws);
//	if (flag->width >= 1)
//		s = ft_c_width(s, flag);
	return (s);
}

static char		*ft_unicode_str_width(char *s, t_flag *flag)
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
char			*ft_manage_unicode_str(va_list *arg, t_flag *flag)
{
	wchar_t	*ws;
	char	*s;

	if (!(ws = va_arg(*arg, wchar_t*)))
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
	s = ft_putunicode(ws);		
	if (flag->width)
		s = ft_unicode_str_width(s, flag);
	return (s);
}
