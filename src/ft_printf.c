/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarkov <rmarkov@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 14:43:33 by rmarkov           #+#    #+#             */
/*   Updated: 2025/06/20 23:05:51 by rmarkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>

int	ft_printf_output(t_format fmt, va_list *args)
{
	if (fmt.type == 'c')
		return (ft_putchar_format(fmt, (char)va_arg(*args, int)));
	else if (fmt.type == 's')
		return (ft_putstr_format(fmt, (char *)va_arg(*args, char *)));
	else if (fmt.type == 'd' || fmt.type == 'i')
		return (ft_print_num(fmt, (int)va_arg(*args, int)));
	else if (fmt.type == 'x' || fmt.type == 'X')
		return (ft_print_hex(fmt, va_arg(*args, unsigned int)));
	//TODO check flags
	else if (fmt.type == '%')
		return (ft_putstr_format(fmt, "%"));
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
	int my_return, c_return;
	//my_return = ft_printf("%10c\n", 'M');
	//c_return = printf("%10c\n", 'M');

	//my_return = ft_printf("%10s\n", "abcd");
	//c_return = printf("%10s\n", "abcd");

	//my_return = ft_printf("%-+0 10.6d\n", -3425234);
	//c_return = printf("%-+0 10.6d\n", -3425234);
	
	my_return = ft_printf("%#10.5x\n", 255);
    c_return = printf("%#10.5x\n", 255);
    printf("my_return 1: %d, c_return: %d\n\n", my_return, c_return);

    my_return = ft_printf("%#10.5X\n", 255);
    c_return = printf("%#10.5X\n", 255);
    printf("my_return 2: %d, c_return: %d\n\n", my_return, c_return);

    my_return = ft_printf("%#8x\n", 4095);
    c_return = printf("%#8x\n", 4095);
    printf("my_return 3: %d, c_return: %d\n\n", my_return, c_return);

    my_return = ft_printf("%#08x\n", 4095);
    c_return = printf("%#08x\n", 4095);
    printf("my_return 4: %d, c_return: %d\n\n", my_return, c_return);

    my_return = ft_printf("%#x\n", 0);
    c_return = printf("%#x\n", 0);
    printf("my_return 5: %d, c_return: %d\n\n", my_return, c_return);

	//TODO
    my_return = ft_printf("%#5.0x\n", 0);
    c_return = printf("%#5.0x\n", 0);
    printf("my_return 6: %d, c_return: %d\n\n", my_return, c_return);

    my_return = ft_printf("%#-10.5x\n", 1234);
    c_return = printf("%#-10.5x\n", 1234);
    printf("my_return 7: %d, c_return: %d\n\n", my_return, c_return);

    my_return = ft_printf("%#10x\n", 1234);
    c_return = printf("%#10x\n", 1234);
    printf("my_return 8: %d, c_return: %d\n\n", my_return, c_return);
	
	// printf("my_return: %d, c_return: %d\n", my_return, c_return);
	return (0);
}
