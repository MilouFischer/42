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
void			ft_manage_flag(char c, t_flag *flag);
void			ft_manage_conv_flag(char c, t_flag *flag);
char			*ft_manage_str(char c, char *format, va_list *arg, t_flag *flag);
char			*ft_manage_conv(char c, va_list *arg, t_flag *flag);
char			*ft_itoa_base_u(unsigned long long nb, int base);
void			ft_init_flag(t_flag *flag);
char			*ft_precision(char conv, char *format, t_flag *flag);
char			*ft_join_free(char *s1, char *s2, int op);
char			*ft_width(char conv, char *format, t_flag *flag);
int				ft_strlen_null(char *s, int nb);
int				ft_putstr_null(char	*s, int nb);
t_list			*ft_lstnew_str(char const *content, size_t content_size);
int				ft_print_list(t_list *list);
void			ft_free_list(t_list *list);

#endif
