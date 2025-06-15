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

SRC		=	src/ft_printf.c src/ft_format_helpers.c src/ft_format_parser.c src/ft_putchar_format.c \
			src/ft_putstr_format.c

OBJ	=	${SRC:.c=.o}

CFLAGS	=	-Wall -Wextra -Werror
RM		=	rm -f

${NAME}:	${OBJ}
			@make bonus -C ${LIBFT}
			@cp libft/libft.a .
			@mv libft.a ${NAME}
			ar rcs ${NAME} ${OBJ}

.c.o:
	cc -Wall -Wextra -Werror -c $< -o $@

all:			${NAME}

clean:
	rm -rf	${OBJ}
	@make clean -C ${LIBFT}

fclean: clean
	rm -rf ${NAME}
	@make fclean -C ${LIBFT}

re:	fclean all

.PHONY:	all bonus clean fclean re