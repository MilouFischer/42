/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_42.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 19:06:33 by efischer          #+#    #+#             */
/*   Updated: 2019/01/11 17:43:05 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_get_var(int key, t_pack *p)
{
	if (key == ONE || key == TWO || key == THREE)
		ft_pov(key, p);
	if (key == R)
		p->var.rot *= -1;
	if (key == A || key == S || key == D || key == W)
	{
		if (p->var.rot == -1)
			ft_move(key, p);
		else
			ft_rot(key, p);
	}
	if (key == PLUS || key == MINUS)
		ft_zoom(key, p);
	if (key == UP || key == DOWN)
		ft_height(key, p);
	if (key == C)
		ft_center(p);
	if (key == G || p->grid)
		ft_grid(key, p);
	if (key == ESC)
		ft_exit(p);
	return (0);
}

static void	ft_fdf(t_matrix matrix)
{
	t_pack		pack;
	t_pixel		pixel;

	pixel.mlx_ptr = mlx_init();
	pixel.win_ptr = mlx_new_window(pixel.mlx_ptr, LENGTH, WIDTH, "fdf_42");
	pixel.x = 0;
	pixel.y = 0;
	pack.px = pixel;
	pack.mx = matrix;
	pack.var = ft_init_var();
	pack.grid = -1;
	mlx_key_hook(pixel.win_ptr, ft_get_var, &pack);
	mlx_loop(pixel.mlx_ptr);
}

int		ft_check_str(char *s)
{
	while (*s)
	{
		if (!ft_isdigit(*s) && *s != '-' && *s != ' ' && *s != '\n')
			return (1);
		s++;
	}
	return (0);
}

char	*ft_get_map(char *src)
{
	char	buf[BUFF_SIZE + 1];
	char	*str;
	char	*tmp;
	int		fd;
	int		ret;

	str = NULL;
	fd = 0;
	ret = 0;
	if ((fd = open(src, O_RDONLY)) == -1)
		return (NULL);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (ft_check_str(buf))
		{
			ft_strdel(&str);
			return (NULL);
		}
		tmp = str;
		str = ft_strjoin(str, buf);
		ft_strdel(&tmp);
	}
	close(fd);
	return (str);
}

int		main(int ac, char **av)
{
	t_matrix		matrix;
	char			*map;
	char			**tmp;

	if (ac != 2)
	{
		ft_putendl("usage: ./fdf file_name");
		return (1);
	}
	matrix.matrix = NULL;
	if (!(map = ft_get_map(av[1])))
	{
		ft_putendl("map error");
		return (1);
	}
	ft_matrix(tmp = ft_strsplit(map, '\n'), &matrix);
	ft_free_tab(tmp);
	ft_strdel(&map);
	ft_fdf(matrix);
	return (0);
}
