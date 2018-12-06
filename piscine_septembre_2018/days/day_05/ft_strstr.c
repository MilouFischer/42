/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 17:05:33 by efischer          #+#    #+#             */
/*   Updated: 2018/09/04 17:10:00 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_compare(char *str, char *to_find)
{
	while (*to_find)
	{
		if (*str != *to_find)
			return (0);
		str++;
		to_find++;
	}
	return (1);
}

char	*ft_strstr(char *str, char *to_find)
{
	int		i;
	char	*not_find;

	not_find = "(null)";
	i = 0;
	while (*str)
	{
		if (ft_compare(str, to_find))
			return (str);
		str++;
		i++;
	}
	return (not_find);
}
