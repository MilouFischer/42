/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 10:14:07 by efischer          #+#    #+#             */
/*   Updated: 2018/12/03 11:24:01 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "get_next_line.h"

int		main(int ac, char **av)
{
	int		fd;
	char	*line;

	line = NULL;
	fd = 0;
	if (ac >= 2)
		fd = open(av[1], O_RDONLY);
	while (get_next_line(fd, &line) != 0)
	{
		ft_putendl(line);
		ft_strdel(&line);
	}
	if (fd)
		close(fd);
	return (0);
}
