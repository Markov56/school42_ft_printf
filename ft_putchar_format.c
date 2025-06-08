/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_format.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarkov <rmarkov@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 14:59:25 by rmarkov           #+#    #+#             */
/*   Updated: 2025/06/08 14:59:27 by rmarkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_format(t_format fmt, va_list *args)
{
	int		padding;
	int		printed_count;
	char	c;

	c = (char)va_arg(*args, int);
	if (fmt.width)
		padding = fmt.width - 1;
	else
		padding = 0;
	printed_count = padding + 1;
	if (fmt.minus)
	{
		write(1, &c, 1);
		while (padding--)
			write(1, " ", 1);
	}
	else
	{
		while (padding--)
			write(1, " ", 1);
		write(1, &c, 1);
	}
	return (printed_count);
}
