#include "ft_printf.h"

char	*ft_width(char conv, char *format, t_flag *flag)
{
	int		len;
	int		i;
	char	*str;
	char	c;

	i = 0;
	if (flag->sharp && (conv == 'x' || conv == 'X'))
			flag->width -= 2;
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
		if ((conv == 'x' || conv == 'X') && flag->zero)
			str = ft_join_free("0x", str, 2);
		else if ((conv == 'x' || conv == 'X'))
			str = ft_join_free(str, "0x", 1);
		format = ft_join_free(str, format, 2);
		ft_strdel(&str);
	}
	return (format);
}
