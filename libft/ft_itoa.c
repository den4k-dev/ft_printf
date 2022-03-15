#include "libft.h"

char	*ft_itoa(long long num)
{
	char	res[21];
	char	*tmp;
	char	sign;

	tmp = &res[20];
	*tmp = '\0';
	sign = 1 - 2 * (num < 0);
	if (num == 0)
		*(--tmp) = '0';
	while (num)
	{
		*(--tmp) = (num % 10) * sign + '0';
		num /= 10;
	}
	if (sign == -1)
		*(--tmp) = '-';
	return (ft_strdup(tmp));
}
