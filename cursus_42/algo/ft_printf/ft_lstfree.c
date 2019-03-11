#include "libft.h"

void			ft_lstfree(t_list *list)
{
	if (!list)
		return ;
	ft_strdel(&list->content);
	ft_lstfree(list->next);
	free(list);
}
