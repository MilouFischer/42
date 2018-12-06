/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 16:03:07 by efischer          #+#    #+#             */
/*   Updated: 2018/09/08 16:04:41 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CHECK_H
# define FT_CHECK_H

int		ft_check_line(int grid[9][9], int x, int test);
int		ft_check_column(int grid[9][9], int y, int test);
int		ft_check_square(int grid[9][9], int x, int y, int test);
int		ft_check(int grid[9][9], int x, int y, int test);

#endif
