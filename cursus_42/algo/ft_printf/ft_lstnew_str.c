#include "libft.h"

t_list			*ft_lstnew_str(char const *content, size_t content_size)
{
	t_list	*list;

	if (!(list = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (content == NULL)
	{
		list->content = NULL;
		list->content_size = 0;
	}
	else
	{
		if (!(list->content = (char*)malloc(sizeof(char) * (content_size + 1))))
		{
			free(list);
			return (NULL);
		}
		list->content = ft_strdup(content);
		list->content_size = content_size;
	}
	list->next = NULL;
	return (list);
}
