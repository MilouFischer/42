/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 13:23:48 by efischer          #+#    #+#             */
/*   Updated: 2019/01/09 17:54:29 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		ft_free_matrix(int	***matrix, unsigned int line)
{
	unsigned int	i;

	i = 0;
	while (i < line)
	{
		free(*matrix[i]);
		*matrix[i++] = NULL;
	}
	free(*matrix);
	*matrix = NULL;
}

static int		ft_count_number(char *str)
{
	int		i;

	i = 0;
	while (*str)
	{
		if (*str == ' ')
			while (*str && *str == ' ')
				str++;
		else if (ft_isdigit(*str))
		{
			while (*str && ft_isdigit(*str))
				str++;
			i++;
		}
		else
			str++;
	}
	return (i);
}

static int		**ft_init_matrix(char **tab, int *len)
{
	int				**matrix;
	int				tmp;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (tab[i])
	{
		if ((tmp = ft_count_number(tab[i++])) > *len)
			*len = tmp;
	}
	if (!(matrix = (int**)malloc(sizeof(int*) * i)))
		return (NULL);
	while (j < i)
	{
		if (!(matrix[j] = (int*)malloc(sizeof(int) * *len)))
		{
			ft_free_matrix(&matrix, j);
			return (NULL);
		}
		j++;
	}
	return (matrix);
}

void		ft_matrix(char **tab, t_matrix *matrix)
{
	int				len;
	char			**tmp;

	len = 0;
	matrix->x = 0;
	if (!(matrix->matrix = ft_init_matrix(tab, &len)))
		return ;
	while (tab[matrix->x])
	{
		tmp = ft_strsplit(tab[matrix->x], ' ');
		matrix->y = 0;
		while (matrix->y < len)
		{
			if (*tmp)
				matrix->matrix[matrix->x][matrix->y++] = ft_atoi(*tmp++);
			else
				matrix->matrix[matrix->x][matrix->y++] = 0;
		}
		matrix->x++;
	}
}
