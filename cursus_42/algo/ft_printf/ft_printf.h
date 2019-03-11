/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 11:27:09 by efischer          #+#    #+#             */
/*   Updated: 2019/02/22 10:57:20 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"

# define pm1 "5"
# define pm2 "25"
# define pm3 "125"
# define pm4 "0625"
# define pm5 "03125"
# define pm6 "015625"
# define pm7 "0078125"
# define pm8 "00390625"
# define pm9 "001953125"
# define pm10 "0009765625"
# define pm11 "00048828125"
# define pm12 "00024414062"
# define pm13 "00012207031"
# define pm14 "00006103515"
# define pm15 "00003051757"
# define pm16 "00001525878"
# define pm17 "00000762939"
# define pm18 "00000381469"
# define pm19 "00000190734"
# define pm20 "00000095367"
# define pm21 "00000047683"
# define pm22 "00000023841"
# define pm23 "00000011920"

typedef struct	s_flag
{
	int			width;
	int			precision;
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
	int			null;
}				t_flag;

int				ft_printf(const char *format, ...);
t_list			*ft_lstnew_str(char const *content, size_t content_size);
char			*ft_process_flag(char **s, va_list *arg, t_flag *flag);
void			ft_init_flag(t_flag *flag);
void			ft_manage_flag(char c, t_flag *flag);
void			ft_manage_conv_flag(char c, t_flag *flag);
char			*ft_manage_str(char c, va_list *arg, t_flag *flag);
char			*ft_manage_c(va_list *arg, t_flag *flag);
char			*ft_manage_s(va_list *arg, t_flag *flag);
char			*ft_manage_p(va_list *arg, t_flag *flag);
char			*ft_diouxxf(char c, va_list *arg, t_flag *flag);
char			*ft_long_diouxx(char c, va_list *arg, t_flag *flag);
char			*ft_diouxx(char c, va_list *arg, t_flag *flag);
char			*ft_precision(char conv, char *format, t_flag *flag);
char			*ft_width(char conv, char *format, t_flag *flag);
int				ft_strlen_null(char *s, int nb);
int				ft_putstr_null(char	*s, int nb);

#endif
