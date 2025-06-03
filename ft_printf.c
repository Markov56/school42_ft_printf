#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int		printed_count;
	int		i;
	va_list	args;

	printed_count = 0;
	i = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
		}
		else
			printed_count += write(1, &str[i], 1);
		i++;
	}
	va_end(args);
	return (printed_count);
}

#include <stdio.h>
int	main()
{
	int result = ft_printf("Hello%d\n");
	// int result = printf("hello%d\n",);
	printf("result: %d\n", result);
	return (0);
}