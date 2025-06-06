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
	{
		printf("c\n");
		printf("c\n");
	}
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
			printed_count += write(1, &str[i], 1);
		i++;
	}
	va_end(args);
	return (printed_count);
}

#include <stdio.h>
int	main(void)
{
	// char *test1 = "-0+ #123.45d";
	int i = 0;
	ft_printf("hello %-0+ #123.45c world\n");

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