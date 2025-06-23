/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarkov <rmarkov@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 14:26:16 by rmarkov           #+#    #+#             */
/*   Updated: 2025/06/23 14:26:18 by rmarkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_utoa(unsigned int n)
{
	int		len;
	char	*str;

	len = ft_numlen(n, 10);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (len--)
	{
		str[len] = '0' + (n % 10);
		n /= 10;
	}
	return (str);
}

int	ft_print_unsigned(t_format fmt, unsigned int num)
{
	t_padding	padding;
	char		*num_str;
	int			num_len;
	int			printed;

	if (num == 0 && fmt.precision == 0)
		num_str = ft_strdup("");
	else
		num_str = ft_utoa(num);
	if (!num_str)
		return (0);
	num_len = ft_strlen(num_str);
	ft_count_num_padding(fmt, num_len, 0, &padding);
	ft_output_formatted(fmt, num_str, 0, padding);
	printed = padding.space + padding.zero + num_len;
	free(num_str);
	return (printed);
}
