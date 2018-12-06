/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_str.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 14:57:42 by efischer          #+#    #+#             */
/*   Updated: 2018/09/15 15:00:02 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CHECK_STR_H
# define FT_CHECK_STR_H

int		ft_check_str(char *str);
int		ft_check_char(char c1, char c2, char c3, char *str);
int		ft_check_colle_00(char *str);
int		ft_check_colle_01(char *str);
int		ft_check_colle_02(char *str);
int		ft_check_colle_03(char *str);
int		ft_check_colle_04(char *str);
void	ft_which_colle(char *str);
int		ft_check_line(char *tab, char *str, int i, int line);
void	ft_count(char *str, int *line, int *letter);
char	*ft_strcpy(char *src, char *dest);
char	*ft_get_figure(void);
int		main(void);

#endif
