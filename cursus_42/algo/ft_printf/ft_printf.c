#include "ft_printf.h"

static char *ft_process_flag(char *s, char *out, va_list *arg)
{
	char	*tmp;
	char	*tmp2;

	while (*s)
	{
		tmp = out;
		if (*s == '#' || *s == '0' || *s == '-' || *s == '+' || *s == ' ')
		{
			out = ft_strjoin(tmp, ft_manage_flag(*s));
			ft_strdel(&tmp);
		}
		else if (*s == 'h' || *s == 'l' || *s == 'L')
		{
			out = ft_strjoin(tmp, ft_manage_conv_flag(*s));
			ft_strdel(&tmp);
		}
		else if (*s == 'c' || *s == 's' || *s == 'p')
		{
			out = ft_strjoin(tmp, ft_manage_str(*s, arg));
			ft_strdel(&tmp);
			tmp = out;
			out = ft_strjoin(tmp, s + 1);
			ft_strdel(&tmp);
			return (out);
		}
		else if (*s == 'd' || *s == 'i' || *s == 'o' || *s == 'u' || *s == 'x'
				|| *s == 'X' || *s == 'f')
		{
			out = ft_strjoin(tmp, tmp2 = ft_manage_conv(*s, arg));
			ft_strdel(&tmp);
			ft_strdel(&tmp2);
			tmp = out;
			out = ft_strjoin(tmp, s + 1);
			ft_strdel(&tmp);
			return (out);
		}
		s++;
	}
	return (NULL);
}

static char	*ft_get_flags(char *out, va_list *arg)
{
	char	*format;
	char	*tmp;

	while ((format = ft_strchr(out, '%')))
	{
		tmp = out;
		out = ft_strsub(tmp, 0, format - tmp);
		ft_strdel(&tmp);
		out = ft_process_flag(format, out, arg);
	}
	return (out);
}

int			ft_printf(const char *format, ...)
{
	char	*out;
	int		len;
	va_list	arg;

	out = ft_strdup(format);
	if (ft_strchr(format, '%'))
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
