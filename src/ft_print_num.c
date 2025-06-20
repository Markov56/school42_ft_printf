/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarkov <rmarkov@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 18:34:00 by rmarkov           #+#    #+#             */
/*   Updated: 2025/06/19 19:53:10 by rmarkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	ft_get_sign_and_unsigned(t_format fmt,
int num, char *sign, unsigned int *n_to_print)
{
	*sign = 0;
	*n_to_print = num;
	if (num < 0)
	{
		*sign = '-';
		*n_to_print = (unsigned int)(-num);
	}
	else if (num >= 0 && fmt.plus)
		*sign = '+';
	else if (num >= 0 && !fmt.plus && fmt.space)
		*sign = ' ';
}

void	ft_output_num_format(t_format fmt, char sign,
unsigned int n_to_print, int zero_padding, int space_padding, int num_len)
{
	char	*num_str;

	if (num_len > 0)
		num_str = ft_itoa((int)n_to_print);
	else
		num_str = NULL;
	if (fmt.minus)
	{
		if (sign != 0)
			write(1, &sign, 1);
		while (zero_padding--)
			write(1, "0", 1);
		if (num_len > 0)
			write(1, num_str, ft_strlen(num_str));
		while(space_padding--)
			write(1, " ", 1);
	}
	else
	{
		while (space_padding--)
			write(1, " ", 1);
		if (sign != 0)
			write(1, &sign, 1);
		while (zero_padding--)
			write(1, "0", 1);
		if (num_len > 0)
			write(1, num_str, ft_strlen(num_str));
	}
	free(num_str);
}

int	ft_print_num(t_format fmt, int num)
{
	char			sign;
	unsigned int	n_to_print;
	int				num_len;
	int				zero_padding;
	int				space_padding;
	int				total_count;

	ft_get_sign_and_unsigned(fmt, num, &sign, &n_to_print);
	num_len = ft_numlen(n_to_print, 10);
	if (n_to_print == 0 && fmt.precision == 0)
		num_len = 0;
	ft_count_zero_padding(fmt.precision, num_len, &zero_padding);
	ft_count_space_padding(fmt.width, num_len + zero_padding,
		sign, &space_padding);
	ft_output_num_format(fmt, sign, n_to_print, zero_padding, space_padding, num_len);
	total_count = num_len + zero_padding + space_padding;
	if (sign != 0)
		total_count++;
	return (total_count);
}
