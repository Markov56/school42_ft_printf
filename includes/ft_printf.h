/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarkov <rmarkov@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 14:43:19 by rmarkov           #+#    #+#             */
/*   Updated: 2025/06/21 21:42:57 by rmarkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include "libft.h"

typedef struct s_flags
{
	int		width;
	int		precision;
	int		minus;
	int		zero;
	int		plus;
	int		space;
	int		hash;
	char	type;
}	t_format;

typedef struct s_padding
{
	int		zero;
	int		space;
	char	sign;
}	t_padding;

int			ft_printf(const char *str, ...);
int			ft_is_end(char c);
void		ft_fmt_init(t_format *fmt);
int			ft_is_flag(char c);
t_format	ft_parse_format(const char *fmt_str, int *i);
int			ft_putchar_format(t_format fmt, char c);
int			ft_putstr_format(t_format fmt, char	*str);
int			ft_print_num(t_format fmt, int num);
int			ft_print_hex(t_format fmt, unsigned int num);
int			ft_numlen(unsigned int num, unsigned int base);
void		ft_output_formatted(t_format fmt, const char *str, char sign, int zero_padding, int space_padding);
void		ft_count_num_padding(t_format fmt, int num_len, int prefix_len, int *zero_padding, int *space_padding);
int			ft_print_unsigned(t_format fmt, unsigned int num);
int			ft_print_pointer(t_format fmt, unsigned long ptr);
char		*ft_utoa(unsigned int n);

#endif
