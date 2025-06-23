/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarkov <rmarkov@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 14:25:40 by rmarkov           #+#    #+#             */
/*   Updated: 2025/06/23 14:25:42 by rmarkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char	*ft_itoa_base(unsigned int num, int is_upper)
{
	int		num_len;
	char	*base;
	char	*num_str;

	num_len = ft_numlen(num, 16);
	num_str = (char *)malloc(num_len + 1);
	if (!num_str)
		return (NULL);
	if (is_upper)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	num_str[num_len] = '\0';
	while (num_len--)
	{
		num_str[num_len] = base[num % 16];
		num /= 16;
	}
	return (num_str);
}

int	ft_print_hex(t_format fmt, unsigned int num)
{
	char		*hex_str;
	int			num_len;
	int			prefix_length;
	t_padding	padding;

	if (fmt.hash && num != 0)
		prefix_length = 2;
	else
		prefix_length = 0;
	num_len = ft_numlen(num, 16);
	if (num == 0 && fmt.precision == 0)
		num_len = 0;
	ft_count_num_padding(fmt, num_len, prefix_length, &padding);
	if (num == 0 && fmt.precision == 0)
		hex_str = ft_strdup("");
	else
		hex_str = ft_itoa_base(num, fmt.type == 'X');
	if (!hex_str)
		return (0);
	ft_output_formatted(fmt, hex_str, 0, padding);
	free(hex_str);
	return (num_len + padding.zero + padding.space + prefix_length);
}
