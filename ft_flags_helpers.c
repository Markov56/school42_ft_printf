#include "ft_printf.h"

#include <stdio.h>

int	ft_is_end(char c)
{
	if (c == 's' || c == 'p' || c == 'd' 
		|| c == 'i' || c == 'u' || c == 'x' 
		|| c == 'X' || c == '%')
		return (1);
	return (0);
}

void	ft_fmt_init(t_format *fmt)
{
	fmt->minus = 0;
	fmt->zero = 0;
	fmt->precision = -1;
	fmt->width = 0;
	fmt->plus = 0;
	fmt->space = 0;
	fmt->hash = 0;
	fmt->type = 0;
}

int	ft_is_flag (char c)
{
	if (c == '-' || c == '0' || c == '+' || c == ' ' || c == '#')
		return (1);
	else
		return (0);
}

void	ft_set_flags(t_format *fmt, char c)
{
	if (c == '-' )
			fmt->minus = 1;
		else if (c == '0')
			fmt->zero = 1;
		else if (c == '+')
			fmt->plus = 1;
		else if (c == ' ')
			fmt->space = 1;
		else if (c == '#')
			fmt->hash = 1;
}

int	ft_parse_precision(t_format *fmt, char *fmt_str, int i)
{
	i++;
	fmt->precision = 0;
	while (fmt_str[i] >= '0' && fmt_str[i] <= '9')
	{
		fmt->precision = fmt->precision * 10 + (fmt_str[i] - '0');
		i++;
	}
	return (i - 1);
}

int	ft_parse_width(t_format *fmt, char *fmt_str, int i)
{
	while (fmt_str[i] >= '0' && fmt_str[i] <= '9')
	{
		fmt->width = fmt->width * 10 + (fmt_str[i] - '0');
		i++;
	}
	return (i - 1);
}

t_format	ft_parse_format(char *fmt_str)
{
	int			i;
	t_format	fmt;

	i = 0;
	ft_fmt_init(&fmt);
	while (fmt_str[i] && !ft_is_end(fmt_str[i]))
	{
		if (ft_is_flag(fmt_str[i]))
			ft_set_flags(&fmt, fmt_str[i]);
		else if (fmt_str[i] == '.')
			i = ft_parse_precision(&fmt, fmt_str, i);
		else if (fmt_str[i] >= '0' && fmt_str[i] <= '9')
			i = ft_parse_width(&fmt, fmt_str, i);
		i++;
	}
	if (fmt_str[i])
		fmt.type = fmt_str[i];
	return (fmt);
}
/*
int main(void)
{
    char *test1 = "-0+ #123.45d";
    t_format fmt = ft_parse_format(test1);

    printf("minus: %d\n", fmt.minus);
    printf("zero: %d\n", fmt.zero);
    printf("plus: %d\n", fmt.plus);
    printf("space: %d\n", fmt.space);
    printf("hash: %d\n", fmt.hash);
    printf("width: %d\n", fmt.width);
    printf("precision: %d\n", fmt.precision);
    printf("type: %c\n", fmt.type);
    return 0;
}
*/