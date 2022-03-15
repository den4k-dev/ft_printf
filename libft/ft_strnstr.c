#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, int len)
{
	size_t	len_src;

	len_src = ft_strlen(s2);
	if (len < 0)
		len = ft_strlen(s1);
	len = len - len_src + 1;
	if (len_src == 0)
		return ((char *)s1);
	while (len-- > 0)
	{
		if (ft_strncmp(s1++, s2, len_src) == 0)
			return ((char *)--s1);
	}
	return (NULL);
}
