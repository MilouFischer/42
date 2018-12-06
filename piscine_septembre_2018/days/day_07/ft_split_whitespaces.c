/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 14:31:55 by efischer          #+#    #+#             */
/*   Updated: 2018/09/11 20:59:28 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_count_word(char *str)
{
	int		count;

	count = 0;
	if (!(*str == ' ' || *str == '\t' || *str == '\n'))
	{
		count++;
		str++;
	}
	while (*str)
	{
		if (*str == ' ' || *str == '\t' || *str == '\n')
		{
			while (*str == ' ' || *str == '\t' || *str == '\n')
				str++;
			if (*str)
				count++;
		}
		str++;
	}
	return (count);
}

char	**ft_malloc_str(char **range, char *str, int nb_word)
{
	int		i;
	int		count;

	i = 0;
	while (*str && i < nb_word)
	{
		count = 0;
		while (*str == ' ' || *str == '\t' || *str == '\n')
			str++;
		while (*str > ' ')
		{
			count++;
			str++;
		}
		if (!(range[i] = (char *)malloc(sizeof(char) * count + 1)))
			return (range = NULL);
		str++;
		i++;
	}
	return (range);
}

void	ft_fill_range(char **range, char *str, int nb_word)
{
	int		i;
	int		j;

	i = 0;
	if (!range)
		return ;
	while (*str && i < nb_word)
	{
		j = 0;
		while (*str == ' ' || *str == '\t' || *str == '\n')
			str++;
		while (*str > ' ')
		{
			range[i][j] = *str;
			j++;
			str++;
		}
		range[i][j] = '\0';
		str++;
		i++;
	}
}

char	**ft_split_whitespaces(char *str)
{
	char	**range;
	int		nb_word;

	if (!*str)
	{
		return (0);
	}
	nb_word = ft_count_word(str);
	if (!(range = (char **)malloc(sizeof(char *) * nb_word + 1)))
		return (range = NULL);
	range = ft_malloc_str(range, str, nb_word);
	ft_fill_range(range, str, nb_word);
	range[nb_word] = NULL;
	return (range);
}
