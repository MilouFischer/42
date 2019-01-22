#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

int		ft_printf(const char *format, ...);
char	*ft_manage_flag(char c);
char	*ft_manage_conv_flag(char c);
char	*ft_manage_str(char c, va_list *arg);
char	*ft_manage_conv(char c, va_list *arg);

#endif
