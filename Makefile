# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmarkov <rmarkov@student.42berlin.de>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/08 20:29:48 by rmarkov           #+#    #+#              #
#    Updated: 2025/06/08 20:29:50 by rmarkov          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a
INCLUDE	=	includes
LIBFT	=	libft
SRC_DIR	=	src/

SRC		=	ft_print.c ft_format_helpers.c ft_format_parser.c ft_putchar_format.c \
			ft_putstr_format.c

OBJS	=	${SRC:.c=.o}

CFLAGS	=	-Wall -Wextra -Werror
RM		=	rm -f

${NAME}:	${OBJ}
			@make -C ${LIBFT}
			@cp

.c.o:
	cc -Wall -Wextra -Werror -c $< -o $@