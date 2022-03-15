#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t count)
{
	unsigned char		*ptr_dst;
	const unsigned char	*ptr_src;
	size_t				i;

	ptr_dst = (unsigned char *)dst;
	ptr_src = (unsigned char *)src;
	i = 0;
	if (ptr_src < ptr_dst)
	{
		while (++i <= count)
			ptr_dst[count - i] = ptr_src[count - i];
	}
	else
	{
		while (count-- > 0)
			*(ptr_dst++) = *(ptr_src++);
	}
	return (dst);
}
