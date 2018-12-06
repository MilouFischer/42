/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 12:05:53 by efischer          #+#    #+#             */
/*   Updated: 2018/08/30 19:55:15 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrev(char *str)
{
	char	tmp;
	int		count;
	int		i;

	count = 0;
	i = 0;
	while (str[count + 1])
		count++;
	while (count >= i)
	{
		tmp = str[i];
		str[i] = str[count];
		str[count] = tmp;
		count--;
		i++;
	}
	return (str);
}
