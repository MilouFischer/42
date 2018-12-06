/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 22:44:37 by efischer          #+#    #+#             */
/*   Updated: 2018/09/06 23:07:18 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ultimator.h"
#include <stdlib.h>

void	ft_destroy(char ***factory)
{
	while (factory)
	{
		while (*factory)
		{
			while (**factory)
			{
				free(**factory);
				(**factory)++;
			}
			free(*factory);
			(*factory)++;
		}
		free(factory);
		(factory)++;
	}
}
