#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "../libft/libft.h"

typedef enum s_types {
	CHAR,
	STRING,
	DECIMAL,
	PERCENT,
	UNSIGNED,
	HEX,
	POINTER,
	NOT_EXISTS
}	t_types;

typedef struct s_fmt {
	char		id;
	t_types		type;
	char		*str;
	char		ch;
	const char	*new_format_pos;
}	t_fmt;

int		ft_printf(const char *conv, ...);
t_fmt	*parse_format(const char *format);
int		ft_putcharn(char c, int n);
int		ft_put_str(char *str);
char	*ft_hextoa(unsigned long long num);
char	*ft_str_toupper(char **str);

#endif
