#include "libft.h"

static char	*get_position(char *s, const char c, char stop)
{
	while (*s && (*s == c) ^ stop)
		s++;
	return (s);
}

static int	get_size(char *s, char c)
{
	int		size;
	char	*start;

	size = 0;
	start = get_position(s, c, 0);
	s = get_position(start, c, 1);
	while (start != s)
	{
		size++;
		start = get_position(s, c, 0);
		s = get_position(start, c, 1);
	}
	return (size);
}

static char	*get_str(char *start, char *stop)
{
	char	*str;
	char	*tmp;

	str = malloc(sizeof(char) * (stop - start) + 1);
	tmp = str;
	if (tmp)
	{
		while (start != stop)
			*tmp++ = *start++;
		*tmp = '\0';
	}
	return (str);
}

static char	**get_strs(char **arr, char *str, const char c, int len)
{
	char	*start;
	char	*tmp;
	char	**tmp_arr;

	tmp_arr = arr;
	while (len--)
	{
		start = get_position(str, c, 0);
		str = get_position(start, c, 1);
		tmp = get_str(start, str);
		if (tmp)
			*tmp_arr++ = tmp;
		else
		{
			while (**arr)
				free(*arr++);
			return (NULL);
		}
	}
	*tmp_arr = NULL;
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		len;

	if (!s)
		return (NULL);
	len = get_size((char *)s, c);
	res = malloc(sizeof(char *) * (len + 1));
	if (res)
		res = get_strs(res, (char *)s, c, len);
	return (res);
}
