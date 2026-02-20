# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xingchen < xingchen@student.42.fr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/10 14:46:11 by xingchen          #+#    #+#              #
#    Updated: 2026/01/22 16:35:08 by xingchen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
SRC = ft_print_hex.c ft_printf.c ft_putchar.c ft_putnbr.c ft_putposition.c ft_putstr.c ft_putunbr.c
OBJS = $(SRC:.c=.o)

all: $(NAME)
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
$(NAME):$(OBJS)
	ar rcs $(NAME) $(OBJS)

clean: 
	$(RM) $(OBJS)
fclean: clean
	$(RM) $(NAME)
re: fclean all
.PHONY: all clean fclean re
