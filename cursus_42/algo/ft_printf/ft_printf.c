#include "ft_printf.h"
#include "libft.h"

static char *ft_process_flag(char *format, va_list *arg)
{
	char	*s;
	char	*tmp;

	while (*format)
	{
		if (*format == 's')
		{
			s = va_arg(*arg, char *);
			tmp = format + 1;
			format = ft_strjoin(s, tmp);
			return (format);
		}
		format++;
	}
	return (NULL);
}

static char	*ft_get_flags(char *out, va_list *arg)
{
	char	*format;
	char	*tmp;

	while ((format = ft_strchr(out, '%')))
	{
		out = ft_strsub(out, 0, format - out);
		format = ft_process_flag(format, arg);
		tmp = out;
		out = ft_strjoin(out, format);
		ft_strdel(&tmp);
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
