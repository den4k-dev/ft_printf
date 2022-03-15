#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*pm;
	size_t	total;

	total = count * size;
	pm = malloc(total);
	if (pm)
		ft_memset(pm, 0, total);
	return (pm);
}
