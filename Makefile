# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rfleritt <rfleritt@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/15 19:49:52 by rfleritt          #+#    #+#              #
#    Updated: 2025/04/08 21:05:39 by rfleritt         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

LIBFT = libft/libft.a

CC = gcc
CFLAGS = -Wall -Werror -Wextra -g3 
RM = rm

SRC = src/pipex.c src/utils.c
OBJ = $(SRC:.c=.o)

all: ${LIBFT} ${NAME}

${NAME}: ${OBJ}
	${CC} ${SRC} ${LIBFT} ${CFLAGS} -o ${NAME}

${LIBFT}:
	make -C libft/

clean: 
		make clean -C libft/
		${RM} ${OBJ}

fclean: clean
		${RM} ${NAME}
		make fclean -C libft/

re: fclean all

.PHONY: all clean fclean re