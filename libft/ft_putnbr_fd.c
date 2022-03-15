#include "libft.h"

static int	len_number(int n)
{
	char	len;

	len = 1;
	n /= 10;
	while (n)
	{
		len++;
		n /= 10;
	}
	return (len);
}

static void	f_itoa(int n, char *num)
{
	char	sign;
	char	len;

	sign = 1 - 2 * (n < 0);
	len = len_number(n);
	num += len + (n < 0);
	*num = '\0';
	while (len--)
	{
		*(--num) = sign * (n % 10) + '0';
		n /= 10;
	}
	if (sign == -1)
		*(--num) = '-';
}

void	ft_putnbr_fd(int n, int fd)
{
	size_t	len;
	char	res[12];

	len = len_number(n) + (n < 0);
	f_itoa(n, res);
	write(fd, res, len);
}
