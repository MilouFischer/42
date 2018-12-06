/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 09:35:30 by efischer          #+#    #+#             */
/*   Updated: 2018/12/05 18:15:50 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft/libft.h"
# include <fcntl.h>
# include "mlx.h"
# define PIXEL_X 750
# define PIXEL_Y 500
# define PIXEL_STEP 30

typedef struct		s_matrix
{
	int				**matrix;
	unsigned int	x;
	unsigned int	y;
}					t_matrix;

typedef struct		s_pixel
{
	void			*mlx_ptr;
	void			*win_ptr;
	int				x;
	int				y;
}					t_pixel;

char				*ft_get_map(char *src);
void				ft_matrix(char **tab, t_matrix *matrix);
void				ft_fdf(t_matrix *matrix);

#endif
