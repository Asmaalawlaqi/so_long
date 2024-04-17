# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: almedetb <almedetb@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/28 11:06:32 by almedetb          #+#    #+#              #
#    Updated: 2024/01/28 14:47:32 by almedetb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

OBJS = ${SRCS:.c=.o}

RM = rm -f

CCF = gcc -Wall -Wextra -Werror

LIB = ar -rcs

SRCS = ft_printf.c conversions_1.c conversions_2.c

all: ${NAME}

$(NAME): ${OBJS}
		@${LIB} ${NAME} ${OBJS}

%.o : %.c ft_printf.h
	@${CCF} -c $< -o $@

clean:
		@${RM} ${OBJS}

fclean:	clean
		@${RM} ${NAME}

re:	fclean all

.PHONY: all clean fclean re