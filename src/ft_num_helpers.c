/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num_helpers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarkov <rmarkov@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 14:25:17 by rmarkov           #+#    #+#             */
/*   Updated: 2025/06/23 14:25:20 by rmarkov          ###   ########.fr       */
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

// void	ft_output_formatted(t_format fmt, const char *str,
// 	char sign, t_padding padding)
// {
// 	int			len;
// 	int			prefix_len;
// 	const char	*prefix;

// 	len = (int)ft_strlen(str);
// 	prefix_len = 0;
// 	prefix = NULL;
// 	if (fmt.hash && str[0] != '\0' && str[0] != '0'
// 		&& (fmt.type == 'x' || fmt.type == 'X'))
// 	{
// 		if (fmt.type == 'X')
// 			prefix = "0X";
// 		else
// 			prefix = "0x";
// 		prefix_len = 2;
// 	}
// 	if (fmt.zero && !fmt.minus && fmt.precision < 0)
// 	{
// 		if (sign != 0)
// 			write(1, &sign, 1);
// 		if (prefix)
// 			write(1, prefix, prefix_len);
// 		while (padding.space--)
// 			write(1, "0", 1);
// 		write(1, str, len);
// 		return ;
// 	}
// 	if (fmt.minus)
// 	{
// 		if (sign != 0)
// 			write(1, &sign, 1);
// 		if (prefix)
// 			write(1, prefix, prefix_len);
// 		while (padding.zero--)
// 			write(1, "0", 1);
// 		write(1, str, len);
// 		while (padding.space--)
// 			write(1, " ", 1);
// 	}
// 	else
// 	{
// 		while (padding.space--)
// 			write(1, " ", 1);
// 		if (sign != 0)
// 			write(1, &sign, 1);
// 		if (prefix)
// 			write(1, prefix, prefix_len);
// 		while (padding.zero--)
// 			write(1, "0", 1);
// 		write(1, str, len);
// 	}
// }
