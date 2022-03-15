#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len;
	size_t	src_len;
	size_t	dst_len;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (dstsize > dst_len)
		len = src_len + dst_len;
	else
		return (src_len + dstsize);
	dst += dst_len;
	while (*src && (dst_len++ + 1 < dstsize))
		*dst++ = *src++;
	*dst = '\0';
	return (len);
}
