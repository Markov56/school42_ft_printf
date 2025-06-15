/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarkov <rmarkov@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 18:34:00 by rmarkov           #+#    #+#             */
/*   Updated: 2025/06/15 18:34:02 by rmarkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_numlen(unsigned int num, unsigned int base)
{
	int	count;

	count = 0;
	if (num == 0)
		return (1);
	while (num)
	{
		count++;
		num /= base;
	}
	return (count);
}

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
	else if (num > 0 && fmt.plus)
		*sign = '+';
	else if (num >= 0 && !fmt.plus && fmt.space)
		*sign = ' ';
}

static void	ft_count_zero_padding(int precision, int num_len, int *zero_padding)
{
	*zero_padding = 0;
	if (precision >= 0)
		*zero_padding = precision - num_len;
	if (*zero_padding < 0)
		*zero_padding = 0;
}

static void	ft_count_space_padding(int width,
int zero_and_num_len, char sign, int *space_padding)
{
	*space_padding = width - zero_and_num_len;
	if (sign != 0)
		*space_padding -= 1;
	if (*space_padding < 0)
		*space_padding = 0;
}

static void	ft_output_num_format(t_format fmt, )
{

}

int	ft_print_num(t_format fmt, int num)
{
	char			sign;
	unsigned int	n_to_print;
	int				num_len;
	int				zero_padding;
	int				space_padding;

	ft_get_sign_and_unsigned(fmt, num, &sign, &n_to_print);
	num_len = ft_numlen(n_to_print, 10);
	if (n_to_print == 0 && fmt.precision == 0)
		num_len = 0;
	ft_count_zero_padding(fmt.precision, num_len, &zero_padding);
	ft_count_space_padding(fmt.width, num_len + zero_padding,
		sign, &space_padding);
	return (0);
}
