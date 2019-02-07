#include "ft_printf.h"

char	*ft_precision(char conv, char *format, t_flag *flag)
{
	int		len;
	int		i;
	char	*str;
	char	*tmp;
	char	c;

	i = 0;
	if (flag->sharp && (conv == 'x' || conv == 'X'))
	{
		flag->precision -= 2;
		flag->plus = 0;
	}
	if (flag->plus && *format != '-')
		flag->precision--;
	if (flag->width >= 0 && !flag->precision)
	{
		ft_strdel(&format);
		format = ft_strdup("");
		flag->zero = 0;
	}
	len = flag->width - ft_strlen(format);
	if (len > 0)
	{
		c = '0';
		if (!(str = (char*)malloc(sizeof(char) * (len + 1))))
		{
			ft_strdel(&format);
			return (NULL);
		}
		while (i < len)
			str[i++] = c;
		str[i] = '\0';
		format = ft_join_free(str, format, 2);
		ft_strdel(&str);
	}
	len = flag->precision - ft_strlen(format);
	if (len > 0)
	{
		c = flag->zero ? '0' : ' ';
		if (!(str = (char*)malloc(sizeof(char) * (len + 1))))
		{
			ft_strdel(&format);
			return (NULL);
		}
		while (i < len)
			str[i++] = c;
		str[i] = '\0';
		if (flag->plus && *format != '-')
			str = ft_join_free("+", str, 2);
		else if (flag->plus && *format != '-')
			format = ft_join_free("+", format, 2);
		if (flag->min)
			format = ft_join_free(format, str, 1);
		else if (*format == '-' && flag->zero)
		{
			str = ft_join_free("-", str, 2);
			tmp = format;
			format = ft_strsub(tmp, 1, ft_strlen(tmp + 1));
			ft_strdel(&tmp);
			format = ft_join_free(str, format, 2);
		}
		else
			format = ft_join_free(str, format, 2);
		if (flag->sharp && flag->zero)
			format = ft_join_free("0x", format, 2);
		ft_strdel(&str);
	}
	return (format);
}
