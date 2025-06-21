/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarkov <rmarkov@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 14:43:33 by rmarkov           #+#    #+#             */
/*   Updated: 2025/06/21 21:45:45 by rmarkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>

static int	ft_printf_output(t_format fmt, va_list *args)
{
	if (fmt.type == 'c')
		return (ft_putchar_format(fmt, (char)va_arg(*args, int)));
	else if (fmt.type == 's')
		return (ft_putstr_format(fmt, (char *)va_arg(*args, char *)));
	else if (fmt.type == 'd' || fmt.type == 'i')
		return (ft_print_num(fmt, (int)va_arg(*args, int)));
	else if (fmt.type == 'x' || fmt.type == 'X')
		return (ft_print_hex(fmt, va_arg(*args, unsigned int)));
	else if (fmt.type == 'u')
		return (ft_print_unsigned(fmt, va_arg(*args, unsigned int)));
	else if (fmt.type == 'p')
		return (ft_print_pointer(fmt, va_arg(*args, void * )));
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

/*
#include <stdio.h>
#include <limits.h>
int	main(void)
{
	int my_return, c_return;

	//TYPE c
	my_return = ft_printf("%c\n", 'A');
	c_return = printf("%c\n", 'A');
	printf("1: my_return: %d, c_return: %d\n\n", my_return, c_return);

	my_return = ft_printf("%5c\n", 'A');
	c_return = printf("%5c\n", 'A');
	printf("2: my_return: %d, c_return: %d\n\n", my_return, c_return);

	my_return = ft_printf("%-5c\n", 'A');
	c_return = printf("%-5c\n", 'A');
	printf("3: my_return: %d, c_return: %d\n\n", my_return, c_return);

	my_return = ft_printf("%c\n", '\0');
	c_return = printf("%c\n", '\0');
	printf("4: my_return: %d, c_return: %d\n\n", my_return, c_return);

	my_return = ft_printf("%05c\n", 'A');
	c_return = printf("%05c\n", 'A');
	printf("5: my_return: %d, c_return: %d\n\n", my_return, c_return);

	//-----
	
	//TYPE s
	my_return = ft_printf("%s\n", "hello");
	c_return = printf("%s\n", "hello");
	printf("1: my_return: %d, c_return: %d\n\n", my_return, c_return);

	my_return = ft_printf("%10s\n", "hello");
	c_return = printf("%10s\n", "hello");
	printf("2: my_return: %d, c_return: %d\n\n", my_return, c_return);

	my_return = ft_printf("%-10s\n", "hello");
	c_return = printf("%-10s\n", "hello");
	printf("3: my_return: %d, c_return: %d\n\n", my_return, c_return);

	my_return = ft_printf("%.3s\n", "hello");
	c_return = printf("%.3s\n", "hello");
	printf("4: my_return: %d, c_return: %d\n\n", my_return, c_return);

	my_return = ft_printf("%.10s\n", "hi");
	c_return = printf("%.10s\n", "hi");
	printf("5: my_return: %d, c_return: %d\n\n", my_return, c_return);

	my_return = ft_printf("%10.3s\n", "hello");
	c_return = printf("%10.3s\n", "hello");
	printf("6: my_return: %d, c_return: %d\n\n", my_return, c_return);

	my_return = ft_printf("%010s\n", "hello");
	c_return = printf("%010s\n", "hello");
	printf("7: my_return: %d, c_return: %d\n\n", my_return, c_return);

	my_return = ft_printf("%s\n", (char *)NULL);
	c_return = printf("%s\n", (char *)NULL);
	printf("8: my_return: %d, c_return: %d\n\n", my_return, c_return);

	my_return = ft_printf("%.3s\n", (char *)NULL);
	c_return = printf("%.3s\n", (char *)NULL);
	printf("9: my_return: %d, c_return: %d\n\n", my_return, c_return);

	//------

	//TYPE d i
	my_return = ft_printf("%d\n", 42);
	c_return = printf("%d\n", 42);
	printf("1: my_return: %d, c_return: %d\n\n", my_return, c_return);

	my_return = ft_printf("%i\n", -42);
	c_return = printf("%i\n", -42);
	printf("2: my_return: %d, c_return: %d\n\n", my_return, c_return);

	my_return = ft_printf("%10d\n", 42);
	c_return = printf("%10d\n", 42);
	printf("3: my_return: %d, c_return: %d\n\n", my_return, c_return);

	my_return = ft_printf("%-10i\n", 42);
	c_return = printf("%-10i\n", 42);
	printf("4: my_return: %d, c_return: %d\n\n", my_return, c_return);

	my_return = ft_printf("%010d\n", 42);
	c_return = printf("%010d\n", 42);
	printf("5: my_return: %d, c_return: %d\n\n", my_return, c_return);

	my_return = ft_printf("%010i\n", -42);
	c_return = printf("%010i\n", -42);
	printf("6: my_return: %d, c_return: %d\n\n", my_return, c_return);

	my_return = ft_printf("%.5d\n", 42);
	c_return = printf("%.5d\n", 42);
	printf("7: my_return: %d, c_return: %d\n\n", my_return, c_return);

	my_return = ft_printf("%10.5d\n", 42);
	c_return = printf("%10.5d\n", 42);
	printf("8: my_return: %d, c_return: %d\n\n", my_return, c_return);

	my_return = ft_printf("%010.5d\n", 42);
	c_return = printf("%010.5d\n", 42);
	printf("9: my_return: %d, c_return: %d\n\n", my_return, c_return);

	my_return = ft_printf("%+d\n", 42);
	c_return = printf("%+d\n", 42);
	printf("10: my_return: %d, c_return: %d\n\n", my_return, c_return);

	my_return = ft_printf("% d\n", 42);
	c_return = printf("% d\n", 42);
	printf("11: my_return: %d, c_return: %d\n\n", my_return, c_return);

	my_return = ft_printf("%+ d\n", 42);
	c_return = printf("%+ d\n", 42);
	printf("12: my_return: %d, c_return: %d\n\n", my_return, c_return);

	my_return = ft_printf("%.0d\n", 0);
	c_return = printf("%.0d\n", 0);
	printf("13: my_return: %d, c_return: %d\n\n", my_return, c_return);

	my_return = ft_printf("%5.0d\n", 0);
	c_return = printf("%5.0d\n", 0);
	printf("14: my_return: %d, c_return: %d\n\n", my_return, c_return);

	my_return = ft_printf("%020d\n", INT_MIN);
	c_return = printf("%020d\n", INT_MIN);
	printf("15: my_return: %d, c_return: %d\n\n", my_return, c_return);

	//-----

	//TYPE X/x
	my_return = ft_printf("%#10.5x\n", 255);
    c_return = printf("%#10.5x\n", 255);
    printf("my_return 1: %d, c_return: %d\n", my_return, c_return);

    my_return = ft_printf("%#10.5X\n", 255);
    c_return = printf("%#10.5X\n", 255);
    printf("my_return 2: %d, c_return: %d\n", my_return, c_return);

    my_return = ft_printf("%#8x\n", 4095);
    c_return = printf("%#8x\n", 4095);
    printf("my_return 3: %d, c_return: %d\n", my_return, c_return);

    my_return = ft_printf("%#08x\n", 4095);
    c_return = printf("%#08x\n", 4095);
    printf("my_return 4: %d, c_return: %d\n", my_return, c_return);

    my_return = ft_printf("%#x\n", 0);
    c_return = printf("%#x\n", 0);
    printf("my_return 5: %d, c_return: %d\n", my_return, c_return);

    my_return = ft_printf("%#5.0x\n", 0);
    c_return = printf("%#5.0x\n", 0);
    printf("my_return 6: %d, c_return: %d\n", my_return, c_return);

    my_return = ft_printf("%#-10.5x\n", 1234);
    c_return = printf("%#-10.5x\n", 1234);
    printf("my_return 7: %d, c_return: %d\n", my_return, c_return);

    my_return = ft_printf("%#10x\n", 1234);
    c_return = printf("%#10x\n", 1234);
    printf("my_return 8: %d, c_return: %d\n", my_return, c_return);

	//--------

	// TYPE u
	my_return = ft_printf("%u\n", 12345);
	c_return = printf("%u\n", 12345);
	printf("my_return 1: %d, c_return: %d\n", my_return, c_return);

	my_return = ft_printf("%10u\n", 12345);
	c_return = printf("%10u\n", 12345);
	printf("my_return 2: %d, c_return: %d\n", my_return, c_return);

	my_return = ft_printf("%.8u\n", 12345);
	c_return = printf("%.8u\n", 12345);
	printf("my_return 3: %d, c_return: %d\n", my_return, c_return);

	my_return = ft_printf("%10.8u\n", 12345);
	c_return = printf("%10.8u\n", 12345);
	printf("my_return 4: %d, c_return: %d\n", my_return, c_return);

	my_return = ft_printf("%010u\n", 12345);
	c_return = printf("%010u\n", 12345);
	printf("my_return 5: %d, c_return: %d\n", my_return, c_return);

	my_return = ft_printf("%-10u\n", 12345);
	c_return = printf("%-10u\n", 12345);
	printf("my_return 6: %d, c_return: %d\n", my_return, c_return);

	my_return = ft_printf("%-010u\n", 12345);
	c_return = printf("%-010u\n", 12345);
	printf("my_return 7: %d, c_return: %d\n", my_return, c_return);

	my_return = ft_printf("%010.5u\n", 12345);
	c_return = printf("%010.5u\n", 12345);
	printf("my_return 8: %d, c_return: %d\n", my_return, c_return);

	my_return = ft_printf("%.0u\n", 0);
	c_return = printf("%.0u\n", 0);
	printf("my_return 9: %d, c_return: %d\n", my_return, c_return);

	my_return = ft_printf("%5.0u\n", 0);
	c_return = printf("%5.0u\n", 0);
	printf("my_return 10: %d, c_return: %d\n", my_return, c_return);

	//-------

	//TYPE p
	void *ptr = (void *)0x1234;
	void *null_ptr = NULL;

	my_return = ft_printf("%p\n", ptr);
	c_return = printf("%p\n", ptr);
	printf("1: my_return : %d, c_return: %d\n", my_return, c_return);

	my_return = ft_printf("%20p\n", ptr);
	c_return = printf("%20p\n", ptr);
	printf("2: my_return : %d, c_return: %d\n", my_return, c_return);

	my_return = ft_printf("%-20p\n", ptr);
	c_return = printf("%-20p\n", ptr);
	printf("3: my_return : %d, c_return: %d\n", my_return, c_return);

	my_return = ft_printf("%.0p\n", null_ptr);
	c_return = printf("%.0p\n", null_ptr);
	printf("4: my_return : %d, c_return: %d\n", my_return, c_return);

	my_return = ft_printf("%10.0p\n", null_ptr);
	c_return = printf("%10.0p\n", null_ptr);
	printf("5: my_return : %d, c_return: %d\n", my_return, c_return);

	my_return = ft_printf("%#p\n", ptr);
	c_return = printf("%#p\n", ptr);
	printf("6: my_return : %d, c_return: %d\n", my_return, c_return);
	
	//-----

	//TYPE %
	my_return = ft_printf("%%\n");
	c_return = printf("%%\n");
	printf("1: my_return: %d, c_return: %d\n\n", my_return, c_return);

	my_return = ft_printf("%5%\n");
	c_return = printf("%5%\n");
	printf("2: my_return: %d, c_return: %d\n\n", my_return, c_return);

	my_return = ft_printf("%-5%\n");
	c_return = printf("%-5%\n");
	printf("3: my_return: %d, c_return: %d\n\n", my_return, c_return);

	my_return = ft_printf("%05%\n");
	c_return = printf("%05%\n");
	printf("4: my_return: %d, c_return: %d\n\n", my_return, c_return);

	my_return = ft_printf("%0%\n");
	c_return = printf("%0%\n");
	printf("5: my_return: %d, c_return: %d\n\n", my_return, c_return);

	my_return = ft_printf("%-0%\n");
	c_return = printf("%-0%\n");
	printf("6: my_return: %d, c_return: %d\n\n", my_return, c_return);
	
	return (0);
}
*/