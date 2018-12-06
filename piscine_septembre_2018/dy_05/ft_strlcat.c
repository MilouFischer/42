/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 13:54:11 by efischer          #+#    #+#             */
/*   Updated: 2018/09/04 17:08:02 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	dest_size;
	unsigned int	i;

	dest_size = 0;
	i = 0;
	while (*(src + 1))
	{
		src++;
		dest_size++;
	}
	while (dest[i] && (i) <= size)
	{
		i++;
		dest_size++;
	}
	return (dest_size);
}
