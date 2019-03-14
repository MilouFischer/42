#include "ft_printf.h"

char			*ft_manage_unicode(va_list *arg, t_flag *flag)
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
