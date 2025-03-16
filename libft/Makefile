# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/25 12:38:40 by rfleritt          #+#    #+#              #
#    Updated: 2024/12/03 11:40:46 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC = ft_atoi.c ft_isascii.c ft_memcpy.c ft_strlcpy.c ft_tolower.c ft_strtrim.c \
ft_bzero.c ft_isdigit.c ft_memmove.c ft_strlen.c ft_toupper.c ft_split.c \
ft_calloc.c ft_isprint.c ft_memset.c ft_strncmp.c ft_strdup.c ft_itoa.c \
ft_isalnum.c ft_memchr.c ft_strchr.c ft_strnstr.c ft_substr.c ft_strmapi.c \
ft_isalpha.c ft_memcmp.c ft_strlcat.c ft_strrchr.c ft_strjoin.c ft_striteri.c \
ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c get_next_line.c \
ft_printf.c ft_print_char.c ft_print_hex.c ft_print_mem.c ft_print_nbr.c \
ft_print_str.c ft_print_unsig.c 

OBJ = $(SRC:.c=.o)

AR = ar -rcs

RM = rm -f

INCLUDE = -I .

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

%.o: %.c 
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	$(RM) $(OBJ) 

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
