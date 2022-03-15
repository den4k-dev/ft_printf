#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*tmp;
	char	*res;

	if (start > ft_strlen(s))
		len = 0;
	else if (start + len > ft_strlen(s))
		len = ft_strlen(s) - start;
	res = malloc(sizeof(char) * (len) + 1);
	tmp = res;
	if (tmp)
	{
		s += start;
		while (len--)
			*tmp++ = *s++;
	}
	*tmp = '\0';
	return (res);
}
