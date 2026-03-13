# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xingchen <xingchen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/19 16:00:15 by xingchen          #+#    #+#              #
#    Updated: 2026/03/13 21:39:54 by xingchen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra -Ilibft
NAME = push_swap
SRC = create_stack.c sort_stack.c find_best_node.c ft_atol.c ft_parsing.c ft_split_tokens.c push.c push_swap.c reverse_rotate.c rotate.c rotate_moves.c set_cost.c set_position.c set_target.c ft_sort_numbers.c sort_small_stack.c stack_utils.c swap.c 
OBJS = $(SRC:.c=.o)
LIBFT_DIR = libft
LIBFT = libft/libft.a
all: $(NAME)
$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJS)
fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)
	
re: fclean all
.PHONY: all clean fclean re

	