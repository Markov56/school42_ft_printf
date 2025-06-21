#include "../includes/ft_printf.h"

static char	*ft_ultoa_base_pointer(unsigned long num)
{
	char	*base = "0123456789abcdef";
	char	buffer[17];
	int		i;

	if (num == 0)
		return (ft_strdup("0"));

	buffer[16] = '\0';
	i = 15;
	while (num > 0)
	{
		buffer[i--] = base[num % 16];
		num /= 16;
	}
	return (ft_strdup(&buffer[i + 1]));
}

int	ft_print_pointer(t_format fmt, unsigned long ptr)
{
	char	*num_str;
	int		num_len;
	int		zero_padding;
	int		space_padding;
	int		printed;

	if (ptr == 0 && fmt.precision == 0)
		num_str = ft_strdup("");
	else
		num_str = ft_ultoa_base_pointer(ptr);
	if (!num_str)
		return (0);
	num_len = ft_strlen(num_str);

	ft_count_num_padding(fmt, num_len, 2, &zero_padding, &space_padding);
	ft_output_formatted(fmt, num_str, 0, zero_padding, space_padding);

	printed = space_padding + zero_padding + num_len + 2;
	free(num_str);
	return (printed);
}