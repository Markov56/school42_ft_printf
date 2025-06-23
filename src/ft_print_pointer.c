/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarkov <rmarkov@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 14:25:55 by rmarkov           #+#    #+#             */
/*   Updated: 2025/06/23 14:25:58 by rmarkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char	*ft_ultoa_base_pointer(unsigned long num)
{
	char	*base;
	char	buffer[17];
	int		i;

	base = "0123456789abcdef";
	if (num == 0)
		return (ft_strdup("0"));
	buffer[16] = '\0';
	i = 15;
	while (num > 0)
	{
		buffer[i--] = base[num % 16];
		num /= 16;
	}
	return (ft_strdup(&buffer[i + 1]));
}

static void	ft_output_pointer(t_format fmt, const char *str,
	int str_len, int space_padding)
{
	const char	*prefix;

	prefix = NULL;
	if (ft_strncmp(str, "(nil)", 5) != 0)
		prefix = "0x";
	if (fmt.minus)
	{
		if (prefix)
			write(1, prefix, 2);
		write(1, str, str_len);
		while (space_padding--)
			write(1, " ", 1);
	}
	else
	{
		while (space_padding--)
			write(1, " ", 1);
		if (prefix)
			write(1, prefix, 2);
		write(1, str, str_len);
	}
}

int	ft_print_pointer(t_format fmt, unsigned long ptr)
{
	char	*num_str;
	int		num_len;
	int		space_padding;
	int		prefix_len;

	if (ptr == 0)
	{
		num_str = ft_strdup("(nil)");
		num_len = 5;
		prefix_len = 0;
	}
	else
	{
		num_str = ft_ultoa_base_pointer(ptr);
		if (!num_str)
			return (0);
		num_len = ft_strlen(num_str);
		prefix_len = 2;
	}
	space_padding = fmt.width - num_len - prefix_len;
	if (space_padding < 0)
		space_padding = 0;
	ft_output_pointer(fmt, num_str, num_len, space_padding);
	free(num_str);
	return (space_padding + num_len + prefix_len);
}
