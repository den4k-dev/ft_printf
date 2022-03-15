#include "libft.h"

char	*ft_strrchr(const char	*str, int ch)
{
	const char	*pos = NULL;

	if (!ft_isascii(ch))
		return ((char *)str);
	if (ch == 0)
		return ((char *)(str + ft_strlen(str)));
	while (*str)
	{
		if (*str == ch)
			pos = str;
		str++;
	}
	return ((char *)pos);
}
