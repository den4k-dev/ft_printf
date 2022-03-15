#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*ptr_dst;
	const char	*ptr_src;

	ptr_dst = dst;
	ptr_src = src;
	while (n--)
		*ptr_dst++ = *ptr_src++;
	return (dst);
}
