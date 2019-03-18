#include "libft.h"

void	*ft_memjoin(void *s1, void *s2, size_t len1, size_t len2)
{
	void				*dst;
	unsigned char		*tmp_dst;
	unsigned const char	*tmp_src;
	size_t				len;
	size_t				i;

	len = len1 + len2 + 1;
	dst = ft_memalloc(len);
	dst = ft_memcpy(dst, s1, len1);
	tmp_dst = (unsigned char *)dst;
	tmp_src = (unsigned const char *)s2;
	i = len1;
	while (i < len)
		tmp_dst[i++] = *tmp_src++;
	tmp_dst[i] = '\0';
	return (tmp_dst);
}
