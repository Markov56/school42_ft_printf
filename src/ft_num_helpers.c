/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num_helpers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarkov <rmarkov@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 14:25:17 by rmarkov           #+#    #+#             */
/*   Updated: 2025/06/26 16:03:06 by rmarkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_numlen(unsigned int num, unsigned int base)
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

void	ft_count_num_padding(t_format fmt, int num_len, int prefix_len,
	t_padding *padding)
{
	int	total_content;

	padding->zero = 0;
	padding->space = 0;
	if (fmt.precision >= 0)
		padding->zero = fmt.precision - num_len;
	if (padding->zero < 0)
		padding->zero = 0;
	total_content = num_len + padding->zero + prefix_len;
	if ((fmt.type == 'd' || fmt.type == 'i') && fmt.plus)
		total_content++;
	if ((fmt.type == 'd' || fmt.type == 'i') && fmt.space && !fmt.plus)
		total_content++;
	padding->space = fmt.width - total_content;
	if (padding->space < 0)
		padding->space = 0;
}

