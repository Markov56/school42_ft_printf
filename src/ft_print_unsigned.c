#include "../includes/ft_printf.h"

char	*ft_utoa(unsigned int n)
{
	int		len;
	char	*str;

	len = ft_numlen(n, 10);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (len--)
	{
		str[len] = '0' + (n % 10);
		n /= 10;
	}
	return (str);
}

int	ft_print_unsigned(t_format fmt, unsigned int num)
{
	char	*num_str;
	int		num_len;
	int		zero_padding;
	int		space_padding;
	int		printed;

	if (num == 0 && fmt.precision == 0)
		num_str = ft_strdup("");
	else
		num_str = ft_utoa(num);
	if (!num_str)
		return (0);
	num_len = ft_strlen(num_str);
	ft_count_num_padding(fmt, num_len, 0, &zero_padding, &space_padding);
	ft_output_formatted(fmt, num_str, 0, zero_padding, space_padding);

	printed = space_padding + zero_padding + num_len;
	free(num_str);
	return (printed);
}