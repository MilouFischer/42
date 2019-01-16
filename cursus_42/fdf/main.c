/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 19:06:33 by efischer          #+#    #+#             */
/*   Updated: 2019/01/15 12:17:59 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		ft_fdf(t_matrix *matrix)
{
	t_pack		pack;
	t_pixel		pixel;

	pixel.mlx_ptr = mlx_init();
	pixel.win_ptr = mlx_new_window(pixel.mlx_ptr, LENGTH, WIDTH, "fdf_42");
	pixel.x = 0;
	pixel.y = 0;
	pack.px = pixel;
	pack.mx = *matrix;
	pack.var.rot = -1;
	pack.var.hud = 1;
	ft_flat(&pack);
	pack.grid = -1;
	mlx_key_hook(pixel.win_ptr, ft_get_var, &pack);
	mlx_loop(pixel.mlx_ptr);
}

static int		ft_check_str(char *s)
{
	while (*s)
	{
		if (!ft_isdigit(*s) && *s != '-' && *s != ' ' && *s != '\n')
			return (1);
		s++;
	}
	return (0);
}

static char		*ft_read_file(int fd)
{
	char	buf[BUFF_SIZE + 1];
	int		ret;
	char	*str;
	char	*tmp;

	str = NULL;
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (ft_check_str(buf))
		{
			ft_strdel(&str);
			ft_putendl("Map error");
			return (NULL);
		}
		tmp = str;
		str = ft_strjoin(str, buf);
		ft_strdel(&tmp);
	}
	return (str);
}

static char		*ft_get_map(char *src)
{
	char	*str;
	int		fd;

	str = NULL;
	if ((fd = open(src, O_RDONLY)) == -1)
	{
		perror(str);
		return (NULL);
	}
	str = ft_read_file(fd);
	close(fd);
	return (str);
}

int				main(int ac, char **av)
{
	t_matrix	matrix;
	char		*map;
	char		**tmp;
	char		*str;

	str = NULL;
	if (ac != 2)
	{
		ft_putendl("usage: ./fdf file_name");
		return (errno);
	}
	matrix.matrix = NULL;
	if (!(map = ft_get_map(av[1])))
		return (errno);
	ft_matrix(tmp = ft_strsplit(map, '\n'), &matrix);
	ft_free_tab(tmp);
	ft_strdel(&map);
	ft_fdf(&matrix);
	return (errno);
}
