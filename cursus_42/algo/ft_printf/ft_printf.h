/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 11:27:09 by efischer          #+#    #+#             */
/*   Updated: 2019/03/12 12:26:11 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"

# define PM1 "5"
# define PM2 "25"
# define PM3 "125"
# define PM4 "0625"
# define PM5 "03125"
# define PM6 "015625"
# define PM7 "0078125"
# define PM8 "00390625"
# define PM9 "001953125"
# define PM10 "0009765625"
# define PM11 "00048828125"
# define PM12 "00024414062"
# define PM13 "00012207031"
# define PM14 "00006103515"
# define PM15 "00003051757"
# define PM16 "00001525878"
# define PM17 "00000762939"
# define PM18 "00000381469"
# define PM19 "00000190734"
# define PM20 "00000095367"
# define PM21 "00000047683"
# define PM22 "00000023841"
# define PM23 "00000011920"

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
