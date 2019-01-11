/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 13:23:48 by efischer          #+#    #+#             */
/*   Updated: 2019/01/11 17:41:16 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		ft_free_matrix_line(int ***matrix, unsigned int line)
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
			ft_free_matrix_line(&matrix, j);
			return (NULL);
		}
		j++;
	}
	return (matrix);
}

void			ft_fill_matrix(t_matrix *matrix, int len, char **tab)
{
	char	**tmp;
	char	**tmp_tmp;

	matrix->min = -5;
	matrix->max = 5;
	while (tab[matrix->x])
	{
		tmp = ft_strsplit(tab[matrix->x], ' ');
		tmp_tmp = tmp;
		matrix->y = 0;
		while (matrix->y < len)
		{
			if (*tmp)
				matrix->matrix[matrix->x][matrix->y] = ft_atoi(*tmp++);
			else
				matrix->matrix[matrix->x][matrix->y] = 0;
			if (matrix->matrix[matrix->x][matrix->y] > matrix->max)
				matrix->max = matrix->matrix[matrix->x][matrix->y];
			else if (matrix->matrix[matrix->x][matrix->y] < matrix->min)
				matrix->min = matrix->matrix[matrix->x][matrix->y];
			matrix->y++;
		}
		matrix->x++;
		ft_free_tab(tmp_tmp);
	}
}

void			ft_matrix(char **tab, t_matrix *matrix)
{
	int				len;

	len = 0;
	matrix->x = 0;
	if (!(matrix->matrix = ft_init_matrix(tab, &len)))
		return ;
	ft_fill_matrix(matrix, len, tab);
	if (matrix->max > 20)
		matrix->max = 20;
	if (matrix->min < -20)
		matrix->min = -20;
}
