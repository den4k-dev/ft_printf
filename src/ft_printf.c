#include "ft_printf.h"

static void	free_fmt(t_fmt *fmt)
{
	if (fmt->type != CHAR && fmt->type != PERCENT && fmt->type != NOT_EXISTS)
		free(fmt->str);
	free(fmt);
}

static int	print_str(t_fmt *fmt)
{
	int	cnt;

	cnt = 0;
	if (fmt->type == CHAR || fmt->type == PERCENT)
		return (ft_putcharn(fmt->ch, 1));
	if (fmt->type == POINTER)
		cnt += ft_put_str("0x");
	cnt += ft_put_str(fmt->str);
	return (cnt);
}

static void	convert_data(va_list *raw_data, t_fmt *fmt)
{
	if (fmt->type == CHAR)
		fmt->ch = va_arg(*raw_data, int);
	else if (fmt->type == PERCENT)
		fmt->ch = '%';
	else if (fmt->type == STRING)
		fmt->str = ft_strdup(va_arg(*raw_data, char *));
	else if (fmt->type == DECIMAL)
		fmt->str = ft_itoa(va_arg(*raw_data, int));
	else if (fmt->type == UNSIGNED)
		fmt->str = ft_itoa(va_arg(*raw_data, unsigned int));
	else if (fmt->type == HEX)
		fmt->str = ft_hextoa(va_arg(*raw_data, unsigned int));
	else if (fmt->type == POINTER)
		fmt->str = ft_hextoa(va_arg(*raw_data, unsigned long long));
	else
		fmt->str = NULL;
}

static t_fmt	*process_format(const char *format, va_list *raw_data)
{
	t_fmt	*fmt;

	fmt = parse_format(format);
	if (!fmt)
		return (NULL);
	convert_data(raw_data, fmt);
	if (!fmt->str && fmt->type == STRING)
		fmt->str = ft_strdup("(null)");
	else if (fmt->id == 'X')
		fmt->str = ft_str_toupper(&fmt->str);
	return (fmt);
}

int	ft_printf(const char *format, ...)
{
	va_list	raw_data;
	t_fmt	*fmt;
	int		cnt;

	cnt = 0;
	if (!*format)
		return (0);
	va_start(raw_data, format);
	while (*format)
	{
		if (*format == '%')
		{
			fmt = process_format(++format, &raw_data);
			if (!fmt)
				return (-1);
			cnt += print_str(fmt);
			format = fmt->new_format_pos;
			free_fmt(fmt);
			continue ;
		}
		cnt += ft_putcharn(*format++, 1);
	}
	va_end(raw_data);
	return (cnt);
}
