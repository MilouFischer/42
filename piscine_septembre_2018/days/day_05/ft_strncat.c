/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 13:32:08 by efischer          #+#    #+#             */
/*   Updated: 2018/09/05 10:50:10 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, int nb)
{
	int		i;

	i = 0;
	while (dest[i])
		i++;
	while (nb)
	{
		if (*src)
		{
			dest[i] = *src;
			src++;
		}
		else
			dest[i] = '\0';
		i++;
		nb--;
	}
	return (dest);
}
