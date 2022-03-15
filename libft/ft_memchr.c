#include "libft.h"

void	*ft_memchr(const void *arr, int c, size_t n)
{
	char	*chr;

	chr = (char *)arr;
	c %= 256;
	while (n--)
	{
		if (*chr == c)
			return (chr);
		chr++;
	}
	return (NULL);
}
