/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concat_params.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 13:32:25 by efischer          #+#    #+#             */
/*   Updated: 2018/09/12 10:53:43 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	int		count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}

int		ft_total_len(int argc, char **argv)
{
	int		lenght;

	lenght = 0;
	while (argc)
	{
		lenght += ft_strlen(*argv++);
		argc--;
	}
	return (lenght);
}

char	*ft_concat_params(int argc, char **argv)
{
	int		i;
	int		j;
	int		k;
	char	*str;

	i = 1;
	k = 0;
	if (!(str = (char *)malloc(sizeof(char) * ft_total_len(argc, argv))))
		return (str = NULL);
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			str[k] = argv[i][j];
			j++;
			k++;
		}
		str[k++] = '\n';
		i++;
	}
	str[--k] = '\0';
	return (str);
}
