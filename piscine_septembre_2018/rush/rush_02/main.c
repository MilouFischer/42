/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 10:32:08 by efischer          #+#    #+#             */
/*   Updated: 2018/09/15 18:26:01 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "ft_check_str.h"

char	*ft_strcpy(char *src, char *dest)
{
	int		i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_get_figure(void)
{
	int		i;
	char	buf;
	char	*str;
	char	*tmp;

	i = 0;
	str = "\0";
	tmp = (char *)malloc(sizeof(char));
	tmp = "\0";
	while (read(0, &buf, 1))
	{
		if (*str)
			free(str);
		str = (char *)malloc(sizeof(char) * (i + 2));
		str = ft_strcpy(tmp, str);
		str[i] = buf;
		str[i + 1] = '\0';
		if (*tmp)
			free(tmp);
		tmp = (char *)malloc(sizeof(char) * (i + 2));
		tmp = ft_strcpy(str, tmp);
		i++;
	}
	free(tmp);
	str[i] = '\0';
	return (str);
}

int		main(void)
{
	char	*str;

	str = ft_get_figure();
	if (ft_check_str(str))
		write(1, "aucune\n", 7);
	return (0);
}
