#include "ft_printf.h"

char	*ft_width(char *format, t_flag *flag)
{
	int		len;
	int		i;
	char	*str;
	char	*tmp;
	char	c;

	i = 0;
	len = flag->width - ft_strlen(format);
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
		tmp = format;
		format = ft_strjoin(str, tmp);
		ft_strdel(&tmp);
		ft_strdel(&str);
	}
	return (format);
}
