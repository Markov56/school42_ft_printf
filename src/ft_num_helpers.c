#include "../includes/ft_printf.h"

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
	return (count);
}

void	ft_count_num_padding(t_format fmt, int num_len, int prefix_len,
	int *zero_padding, int *space_padding)
{
	*zero_padding = 0;
	if (fmt.precision >= 0)
		*zero_padding = fmt.precision - num_len;
	if (*zero_padding < 0)
		*zero_padding = 0;

	int total_content = num_len + *zero_padding + prefix_len;

	if ((fmt.type == 'd' || fmt.type == 'i') && fmt.plus)
		total_content++;
	if ((fmt.type == 'd' || fmt.type == 'i') && fmt.space && !fmt.plus)
		total_content++;

	*space_padding = fmt.width - total_content;
	if (*space_padding < 0)
		*space_padding = 0;
}

void	ft_output_formatted(t_format fmt, const char *str, char sign, int zero_padding, int space_padding)
{
	int			len;
	int			prefix_len;
	const char	*prefix;

	len = (int)ft_strlen(str);
	prefix_len = 0;
	prefix = NULL;
	if (fmt.hash && str[0] != '\0' && str[0] != '0' && (fmt.type == 'x' || fmt.type == 'X'))
	{
		if (fmt.type == 'X')
			prefix = "0X";
		else
			prefix = "0x";
		prefix_len = 2;
	}
	if (fmt.type == 'p')
	{
		prefix = "0x";
		prefix_len = 2;
	}
	if (fmt.zero && !fmt.minus && fmt.precision < 0)
	{
		if (sign != 0)
			write(1, &sign, 1);
		if (prefix)
			write(1, prefix, prefix_len);
		while (space_padding--)
			write(1, "0", 1);
		write(1, str, len);
		return ;
	}
	if (fmt.minus)
	{
		if (sign != 0)
			write(1, &sign, 1);
		if (prefix)
			write(1, prefix, prefix_len);
		while (zero_padding--)
			write(1, "0", 1);
		write(1, str, len);
		while(space_padding--)
			write(1, " ", 1);
	}
	else
	{
		while (space_padding--)
			write(1, " ", 1);
		if (sign != 0)
			write(1, &sign, 1);
		if (prefix)
			write(1, prefix, prefix_len);
		while (zero_padding--)
			write(1, "0", 1);
		write(1, str, len);
	}
}