#include "libft.h"

void	*ft_memset(void *buf, int ch, size_t count)
{
	char	*ptr;

	ptr = buf;
	while (count--)
		*ptr++ = ch;
	return (buf);
}
