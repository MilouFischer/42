#include "libft.h"

char	*ft_join_free(char *s1, char *s2, int op)
{
	char	*str;
	
	str = ft_strjoin(s1, s2);
	if (op == 1)
		ft_strdel(&s1);
	else if (op == 2)
		ft_strdel(&s2);
	else
	{
		ft_strdel(&s1);
		ft_strdel(&s2);
	}
	return (str);
}
