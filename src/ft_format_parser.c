/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_parser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarkov <rmarkov@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 15:02:38 by rmarkov           #+#    #+#             */
/*   Updated: 2025/06/06 15:02:39 by rmarkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h>

void	ft_set_flags(t_format *fmt, char c)
{
	if (c == '-' )
		fmt->minus = 1;
	else if (c == '0')
		fmt->zero = 1;
	else if (c == '+')
		fmt->plus = 1;
	else if (c == ' ')
		fmt->space = 1;
	else if (c == '#')
		fmt->hash = 1;
}

void	ft_parse_precision(t_format *fmt, const char *fmt_str, int *i)
{
	(*i)++;
	fmt->precision = 0;
	while (fmt_str[*i] >= '0' && fmt_str[*i] <= '9')
	{
		fmt->precision = fmt->precision * 10 + (fmt_str[*i] - '0');
		(*i)++;
	}
}

void	ft_parse_width(t_format *fmt, const char *fmt_str, int *i)
{
	while (fmt_str[*i] >= '0' && fmt_str[*i] <= '9')
	{
		fmt->width = fmt->width * 10 + (fmt_str[*i] - '0');
		(*i)++;
	}
}

t_format	ft_parse_format(const char *fmt_str, int *i)
{
	t_format	fmt;

	(*i)++;
	ft_fmt_init(&fmt);
	while (fmt_str[*i] && !ft_is_end(fmt_str[*i]))
	{
		if (ft_is_flag(fmt_str[*i]))
			ft_set_flags(&fmt, fmt_str[*i]);
		else if (fmt_str[*i] >= '0' && fmt_str[*i] <= '9')
		{
			ft_parse_width(&fmt, fmt_str, i);
			continue ;
		}
		else if (fmt_str[*i] == '.')
		{
			ft_parse_precision(&fmt, fmt_str, i);
			continue ;
		}
		(*i)++;
	}
	if (fmt_str[*i] && ft_is_end(fmt_str[*i]))
		fmt.type = fmt_str[*i];
	(*i)++;
	return (fmt);
}
/*
#include <stdio.h>
int	main(void)
{
	char *test1 = "-0+ #123.45d";
	int i = 0;
	t_format fmt = ft_parse_format(test1, &i);

	printf("minus: %d\n", fmt.minus);
	printf("zero: %d\n", fmt.zero);
	printf("plus: %d\n", fmt.plus);
	printf("space: %d\n", fmt.space);
	printf("hash: %d\n", fmt.hash);
	printf("width: %d\n", fmt.width);
	printf("precision: %d\n", fmt.precision);
	printf("type: %c\n", fmt.type);
	return 0;
}
*/