#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"

typedef struct	s_flag
{
	int			sharp;
	int			zero;
	int			min;
	int			space;
	int			plus;
	int			h;
	int			hh;
	int			l;
	int			ll;
	int			L;
}				t_flag;

int		ft_printf(const char *format, ...);
void	ft_manage_flag(char c, t_flag *flag);
char	*ft_manage_conv_flag(char c, t_flag *flag);
char	*ft_manage_str(char c, char *format, va_list *arg, t_flag *flag);
char	*ft_manage_conv(char c, va_list *arg, t_flag *flag);
char	*ft_itoa_base_u(unsigned long nb, unsigned long base);
void	ft_init_flag(t_flag *flag);

#endif
