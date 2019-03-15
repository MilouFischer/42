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
	/*if (flag->precision > 0)
		s = ft_strndup(s, flag->precision);
	else if (flag->precision == -1)
		s = ft_strdup("");
	else
		s = ft_strdup(s);
	if (flag->width)
		s = ft_s_width(s, flag);
	*/s = ft_putunicode(ws);		
	return (s);
}
