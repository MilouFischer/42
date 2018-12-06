/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 11:41:11 by efischer          #+#    #+#             */
/*   Updated: 2018/11/30 15:30:54 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft/libft.h"
# define BUFF_SIZE 32
# define FILEL ((t_file *)(list->content))
# define T_FILEL ((t_file *)(tmp->content))

typedef struct		s_file
{
	char			*rest;
	char			*cur;
	int				fd;
}					t_file;

int					get_next_line(const int fd, char **line);

#endif
