#include "ft_printf.h"

static char *ft_process_flag(char **s, va_list *arg, t_flag *flag)
{
	char	*format;
	char	*tmp;
	char	*nb;

	format = NULL;
	(*s)++;
	while (**s)
	{
		tmp = format;
		if (**s == '#' || **s == '0' || **s == '-' || **s == '+' || **s == ' ' || **s == '.')
			ft_manage_flag(s, flag);
		else if (**s == '%')
		{
			format = ft_strdup("%");
			if (flag->precision)
				format = ft_precision(**s, format, flag);
			return (format);
		}
		else if (**s == 'h' || **s == 'l' || **s == 'L')
			ft_manage_conv_flag(**s, flag);
		else if (**s == 'c' || **s == 's' || **s == 'p')
		{
			format = ft_manage_str(**s, format, arg, flag);
			return (format);
		}
		else if (**s == 'd' || **s == 'i' || **s == 'o' || **s == 'u' || **s == 'x'
				|| **s == 'X' || **s == 'f')
		{
			format = ft_strjoin(tmp, nb = ft_manage_conv(**s, arg, flag));
			ft_strdel(&tmp);
			ft_strdel(&nb);
			if (flag->sharp > 0 && (**s == 'x' || **s == 'X') && *format != '0' && !flag->zero)
			{
				format = ft_join_free("0x", format, 2);
				flag->sharp = 0;
			}
			if (flag->precision || flag->width >= 0)
			{
				if (flag->precision)
					format = ft_precision(**s, format, flag);
				if (flag->width >= 0)
					format = ft_width(**s, format, flag);
			}
			else if (flag->plus && *format != '-')
				format = ft_join_free("+", format, 2);
			else if (flag->space && *format != '-')
				format = ft_join_free(" ", format, 2);
			return (**s == 'X' ? ft_strupcase(format) : format);
		}
		else if (**s >= '1' && **s <= '9')
		{
			flag->precision = ft_atoi(*s);
			while (ft_isdigit(**s))
				(*s)++;
			(*s)--;
		}
		(*s)++;
	}
	return (NULL);
}

static char	*ft_get_flags(char *cp, va_list *arg)
{
	char	*s;
	char	*out;
	char	*tmp;
	char	*format;
	t_flag	flag;

	(void)arg;
	out = NULL;
	while ((s = ft_strchr(cp, '%')))
	{
		ft_init_flag(&flag);
		format = ft_strsub(cp, 0, s - cp);
		tmp = out;
		out = ft_strjoin(tmp, format);
		ft_strdel(&format);
		ft_strdel(&tmp);
		if (!(format = ft_process_flag(&s, arg, &flag)))
			return (NULL);
		tmp = out;
		out = ft_strjoin(tmp, format);
		ft_strdel(&format);
		ft_strdel(&tmp);
		tmp = cp;
		cp = ft_strdup(s + 1);
		ft_strdel(&tmp);
	}
	tmp = out;
	out = ft_strjoin(tmp, cp);
	ft_strdel(&tmp);
	ft_strdel(&cp);
	return (out);
}

int			ft_printf(const char *format, ...)
{
	char	*out;
	int		len;
	va_list	arg;

	if (!format)
		return (0);
	out = ft_strdup(format);
	if (ft_strchr(out, '%'))
	{
		va_start(arg, format);
		out = ft_get_flags(out, &arg);
		va_end(arg);
	}
	ft_putstr(out);
	len = ft_strlen(out);
	ft_strdel(&out);
	return (len);
}
