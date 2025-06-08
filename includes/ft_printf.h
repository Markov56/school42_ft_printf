/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarkov <rmarkov@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 14:43:19 by rmarkov           #+#    #+#             */
/*   Updated: 2025/06/06 14:43:22 by rmarkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>

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

int			ft_printf(const char *str, ...);
int			ft_is_end(char c);
void		ft_fmt_init(t_format *fmt);
int			ft_is_flag(char c);
void		ft_set_flags(t_format *fmt, char c);
void		ft_parse_precision(t_format *fmt, const char *fmt_str, int *i);
void		ft_parse_width(t_format *fmt, const char *fmt_str, int *i);
t_format	ft_parse_format(const char *fmt_str, int *i);
int			ft_putchar_format(t_format fmt, char c);
int			ft_putstr_format(t_format fmt, char	*str);

#endif
