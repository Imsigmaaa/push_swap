# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xingchen <xingchen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/19 16:00:15 by xingchen          #+#    #+#              #
#    Updated: 2026/03/13 15:56:39 by xingchen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra -Ilibft
NAME = push_swap
SRC = create_stack.c sort_stack.c find_best_node.c ft_atol.c ft_parsing.c ft_split_tokens.c push_ab.c push_swap.c reverse_rotate_ab.c rotate_ab.c rotate_moves.c set_cost.c set_position.c set_target.c sort_numbers.c sort_small_stack.c stack_utils.c swap_ab.c 
OBJS = $(SRC:.c=.o)
LIBFT_DIR = libft
FT_PRINTF_DIR = ft_printf
LIBFT = libft/libft.a
FT_PRINTF = ft_printf/libftprintf.a
all: $(NAME)
$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFT_DIR)
	$(MAKE) -C $(FT_PRINTF_DIR)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(FT_PRINTF) -o $(NAME)
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(FT_PRINTF_DIR) clean
	rm -f $(OBJS)
fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(FT_PRINTF_DIR) fclean
	rm -f $(NAME)
	
re: fclean all
.PHONY: all clean fclean re

	