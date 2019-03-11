#include "libft.h"

int				ft_lstprint(t_list *list)
{
	int		len;
	size_t	i;

	len = 0;
	while (list)
	{
		i = 0;
		while (i < list->content_size)
			ft_putchar(list->content[i++]);
		len += list->content_size;
		list = list->next;
	}
	return (len);
}
