/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_format.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarkov <rmarkov@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 16:36:04 by rmarkov           #+#    #+#             */
/*   Updated: 2025/06/08 16:36:07 by rmarkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	ft_putstr_padding(int minus, char *str,
	int str_len, int padding)
{
	if (minus)
	{
		write(1, str, str_len);
		while (padding--)
			write(1, " ", 1);
	}
	else
	{
		while (padding--)
			write(1, " ", 1);
		write(1, str, str_len);
	}
}

static int	ft_count_printed(int width, int str_len, int precision)
{
	int	printed_count;

	if (width > str_len)
		printed_count = width;
	else if (precision >= 0 && precision < str_len)
		printed_count = precision;
	else
		printed_count = str_len;
	return (printed_count);
}

int	ft_putstr_format(t_format fmt, char	*str)
{
	size_t	str_len;
	int		padding;

	if (!str)
	{
		if (fmt.precision >= 0 && fmt.precision < 6)
			str = "";
		else
			str = "(null)";
	}
	str_len = ft_strlen(str);
	if (fmt.precision >= 0 && fmt.precision < (int)str_len)
		str_len = fmt.precision;
	if (fmt.width > (int)str_len)
		padding = fmt.width - str_len;
	else
		padding = 0;
	ft_putstr_padding(fmt.minus, str, (int)str_len, padding);
	return (ft_count_printed(fmt.width, (int)str_len, fmt.precision));
}
