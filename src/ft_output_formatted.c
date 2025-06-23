/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_formatted.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarkov <rmarkov@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 17:58:46 by rmarkov           #+#    #+#             */
/*   Updated: 2025/06/23 17:58:49 by rmarkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	write_sign_and_prefix(char sign, const char *prefix, int prefix_len)
{
	if (sign)
		write(1, &sign, 1);
	if (prefix)
		write(1, prefix, prefix_len);
}

static void	write_zeros_and_str(int zero, const char *str, int len)
{
	while (zero--)
		write(1, "0", 1);
	write(1, str, len);
}

static void	ft_get_prefix(t_format fmt, const char *str,
	char **prefix, int *prefix_len)
{
	*prefix = NULL;
	*prefix_len = 0;
	if (fmt.hash && str[0] != '\0' && str[0] != '0'
		&& (fmt.type == 'x' || fmt.type == 'X'))
	{
		if (fmt.type == 'X')
			*prefix = "0X";
		else
			*prefix = "0x";
		*prefix_len = 2;
	}
}

void	ft_output_formatted(t_format fmt, const char *str,
		char sign, t_padding padding)
{
	int		len;
	int		prefix_len;
	char	*prefix;

	len = (int)ft_strlen(str);
	ft_get_prefix(fmt, str, &prefix, &prefix_len);
	if (fmt.zero && !fmt.minus && fmt.precision < 0)
		return (write_sign_and_prefix(sign, prefix, prefix_len),
			write_zeros_and_str(padding.space, str, len));
	if (fmt.minus)
	{
		write_sign_and_prefix(sign, prefix, prefix_len);
		write_zeros_and_str(padding.zero, str, len);
		while (padding.space--)
			write(1, " ", 1);
	}
	else
	{
		while (padding.space--)
			write(1, " ", 1);
		write_sign_and_prefix(sign, prefix, prefix_len);
		write_zeros_and_str(padding.zero, str, len);
	}
}
