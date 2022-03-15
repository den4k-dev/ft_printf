#include "libft.h"

char	*ft_strchr(const char *str, int ch)
{
	if (!ft_isascii(ch))
		return ((char *)str);
	if (ch == 0)
		return ((char *)(str + ft_strlen(str)));
	while (*str)
	{
		if (*str == ch)
			return ((char *)str);
		str++;
	}
	return (NULL);
}
