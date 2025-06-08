/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_helpers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarkov <rmarkov@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 14:43:45 by rmarkov           #+#    #+#             */
/*   Updated: 2025/06/06 14:43:46 by rmarkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h>

int	ft_is_end(char c)
{
	if (c == 's' || c == 'p' || c == 'd' 
		|| c == 'i' || c == 'u' || c == 'x' 
		|| c == 'X' || c == '%' || c == 'c')
		return (1);
	return (0);
}

void	ft_fmt_init(t_format *fmt)
{
	fmt->minus = 0;
	fmt->zero = 0;
	fmt->precision = -1;
	fmt->width = 0;
	fmt->plus = 0;
	fmt->space = 0;
	fmt->hash = 0;
	fmt->type = 0;
}

int	ft_is_flag(char c)
{
	if (c == '-' || c == '0' || c == '+' || c == ' ' || c == '#')
		return (1);
	else
		return (0);
}
