#include "ft_printf.h"

int	ft_numlen(unsigned int num, unsigned int base)
{
	int	count;

	count = 0;
	if (num == 0)
		return (1);
	while (num)
	{
		count++;
		num /= base;
	}
	return count;
}

int	ft_print_num(t_format fmt, int num)
{
	char			sign;
	unsigned int	n_to_print;
	int				num_len;

	sign = 0;
	n_to_print = num;
	if (num < 0)
	{
		sign = '-';
		n_to_print = (unsigned int)(-num);
	}
	else if (num > 0 && fmt.plus)
		sign = '+';
	else if (num >= 0 && !fmt.plus && fmt.space)
		sign = ' ';
	num_len = ft_numlen(n_to_print, 10);
	if (n_to_print == 0 && fmt.precision == 0)
		num_len = 0;
	printf("num_len: %d\n", num_len);
	return (0);
}