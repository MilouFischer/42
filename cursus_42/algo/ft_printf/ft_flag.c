#include "ft_printf.h"

char	*ft_flag_zero(char *format, t_flag *flag)
{
	int		len;
	int		i;
	char	*str;
	char	*tmp;

	i = 0;
	len = flag->zero - ft_strlen(format);
	if (len > 0)
	{
		if (!(str = (char*)malloc(sizeof(char) * (len + 1))))
		{
			ft_strdel(&format);
			return (NULL);
		}
		while (i < len)
			str[i++] = '0';
		str[i] = '\0';
		tmp = format;
		format = ft_strjoin(str, tmp);
		ft_strdel(&tmp);
		ft_strdel(&str);
	}
	return (format);
}
