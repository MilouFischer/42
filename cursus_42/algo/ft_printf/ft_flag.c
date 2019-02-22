#include "ft_printf.h"

char	*ft_width(char conv, char *format, t_flag *flag)
{
	int		len;
	int		i;
	char	*str;
	char	c;

	i = 0;
	if (flag->width >= 0 && !flag->precision && *format == '0')
	{
		ft_strdel(&format);
		if (conv == 'o' && flag->sharp == -1)
			format = ft_strdup("0");
		else
			format = ft_strdup("");
		flag->zero = 0;
	}
	len = flag->width - ft_strlen(format);
	if (len > 0)
	{
		c = ' ';
		if (flag->precision > (int)ft_strlen(format))
			c = '0';
		if (!(str = (char*)malloc(sizeof(char) * (len + 1))))
		{
			ft_strdel(&format);
			return (NULL);
		}
		while (i < len)
			str[i++] = c;
		str[i] = '\0';
		if (flag->min)
			format = ft_join_free(format, str, 1);
		else
			format = ft_join_free(str, format, 2);
		ft_strdel(&str);
	}
	return (format);
}

char	*ft_precision(char conv, char *format, t_flag *flag)
{
	int		len;
	int		i;
	char	*str;
	char	*tmp;
	char	c;

	i = 0;
	if (flag->sharp > 0 && (conv == 'x' || conv == 'X'))
	{
		flag->precision -= 2;
		flag->plus = 0;
	}
	if (flag->plus && *format != '-' && flag->width == -1)
		flag->precision--;
	len = flag->precision - ft_strlen(format);
	if (!len && *format == '-')
	{
		*format = '0';
		return (ft_join_free("-", format, 2));
	}
	if (len > 0)
	{
		c = ' ';
		if (flag->zero || flag->width >= 0)
			c = '0';
		if (!(str = (char*)malloc(sizeof(char) * (len + 1))))
		{
			ft_strdel(&format);
			return (NULL);
		}
		if (flag->space && len != 1)
			str[i++] = ' ';
		while (i < len)
			str[i++] = c;
		str[i] = '\0';
		if (flag->plus && *format != '-')
			str = ft_join_free("+", str, 2);
		if (flag->min && flag->width == -1)
			format = ft_join_free(format, str, 1);
		else if (*format == '-' && c == '0')
		{
			str = ft_join_free("-", str, 2);
			if (flag->width == -1)
			{
				tmp = format;
				format = ft_strsub(tmp, 1, ft_strlen(tmp + 1));
				ft_strdel(&tmp);
			}
			else
				format[0] = '0';
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
