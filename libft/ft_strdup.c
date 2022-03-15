#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*p;
	char	*res;

	if (!str)
		return (NULL);
	p = malloc(ft_strlen(str) * sizeof(char) + 1);
	if (!p)
		return (NULL);
	res = p;
	while (*str)
		*p++ = *str++;
	*p = '\0';
	return (res);
}
