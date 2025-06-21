/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarkov <rmarkov@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 18:34:00 by rmarkov           #+#    #+#             */
/*   Updated: 2025/06/21 18:48:57 by rmarkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char	*ft_get_sign_and_string(t_format fmt,
int num, char *sign)
{
	char			*num_str;
	unsigned int	n_to_print;

	*sign = 0;
	if (num < 0)
	{
		*sign = '-';
		n_to_print = (unsigned int)(-(long)num);
	}
	else
	{
		n_to_print = (unsigned int)num;
		if (fmt.plus)
			*sign = '+';
		else if (fmt.space)
			*sign = ' ';
	}
	if (n_to_print == 0 && fmt.precision == 0)
		num_str = ft_strdup("");
	else
		num_str = ft_utoa(n_to_print);
	return (num_str);
}

int	ft_print_num(t_format fmt, int num)
{
	char			sign;
	char			*num_str;
	int				num_len;
	int				zero_padding;
	int				space_padding;

	num_str = ft_get_sign_and_string(fmt, num, &sign);
	if (num == 0 && fmt.precision == 0)
		num_len = 0;
	else
		num_len = ft_strlen(num_str);
	if (sign != 0)
		num_len++;
	ft_count_num_padding(fmt, num_len, 0, &zero_padding, &space_padding);
	ft_output_formatted(fmt, num_str, sign, zero_padding, space_padding);
	free(num_str);
	return (num_len + zero_padding + space_padding);
}
