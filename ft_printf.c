/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarkov <rmarkov@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 14:43:33 by rmarkov           #+#    #+#             */
/*   Updated: 2025/06/06 14:43:35 by rmarkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_printf_output(t_format fmt, va_list *args)
{
	if (fmt.type == 'c')
		return (ft_putchar_format(fmt, args));
	else if (fmt.type == 's')
		return (ft_putstr_format(fmt, args));
	else
		return (0);
}

int	ft_printf(const char *str, ...)
{
	int			printed_count;
	int			i;
	t_format	fmt;
	va_list		args;

	printed_count = 0;
	i = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			fmt = ft_parse_format(str, &i);
			// printf("minus: %d\n", fmt.minus);
			// printf("zero: %d\n", fmt.zero);
			// printf("plus: %d\n", fmt.plus);
			// printf("space: %d\n", fmt.space);
			// printf("hash: %d\n", fmt.hash);
			// printf("width: %d\n", fmt.width);
			// printf("precision: %d\n", fmt.precision);
			// printf("type: %c\n", fmt.type);
			printed_count += ft_printf_output(fmt, &args);
		}
		else
		{
			printed_count += write(1, &str[i], 1);
			i++;
		}
	}
	va_end(args);
	return (printed_count);
}

#include <stdio.h>
int	main(void)
{
	// int my_return = ft_printf("%10c\n", 'M');
	// int c_return = printf("%10c\n", 'M');
	int my_return = ft_printf("%.3s\n", "abcd");
	int c_return = printf("%.3s\n", "abcd");
	printf("my_return: %d, c_return: %d\n", my_return, c_return);
	// printf("c_return: %d\n", c_return);
	// printf("my_return: %d\n", my_return);

	// printf("minus: %d\n", fmt.minus);
	// printf("zero: %d\n", fmt.zero);
	// printf("plus: %d\n", fmt.plus);
	// printf("space: %d\n", fmt.space);
	// printf("hash: %d\n", fmt.hash);
	// printf("width: %d\n", fmt.width);
	// printf("precision: %d\n", fmt.precision);
	// printf("type: %c\n", fmt.type);

	return 0;
}