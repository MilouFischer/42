/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 17:55:59 by efischer          #+#    #+#             */
/*   Updated: 2018/11/06 18:13:37 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

void	ft_putstr(char *str, int len)
{
	write(1, str, len);
}

int		main(int ac, char **av)
{
	int		fd;
	int		ret;
	char	buf[16001];

	if (ac == 2)
	{
		if ((fd = open(av[1], O_RDONLY)) != -1)
		{
			while ((ret = read(fd, buf, 16000)))
			{
				buf[ret] = '\0';
				ft_putstr(buf, ret);
			}
		}
		close(fd);
	}
	else if (ac == 1)
		write(2, "File name missing.\n", 19);
	else
		write(2, "Too many arguments.\n", 20);
	return (0);
}
