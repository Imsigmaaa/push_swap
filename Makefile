# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xingchen <xingchen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/19 16:00:15 by xingchen          #+#    #+#              #
#    Updated: 2026/02/28 16:51:43 by xingchen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra -Ilibft -Ift_printf 
NAME = push_swap
SRC = main.c ft_parsing.c change_to_list.c ft_free_arr.c push_ab.c stackadd_front.c stackadd_back.c stacklast.c stackswap.c swap_ab.c rotate_ab.c reverse_rotate_ab.c
OBJS = $(SRC:.c=.o)
#LIBFT_DIR = libfts
LIBFT_DIR = libft
FT_PRINTF_DIR = ft_printf
LIBFT = libft/libft.a
FT_PRINTF = ft_printf/libftprintf.a
#当执行make的时候 默认执行all all；依赖NAME
all: $(NAME)
#要生成NAME 要先生成OBJS
$(NAME): $(OBJS)
#生成NAME的方式 -C就是CD 进入到目录 MAKE是Makefile的内置变量指代当前使用的make命令
	$(MAKE) -C $(LIBFT_DIR)
	$(MAKE) -C $(FT_PRINTF_DIR)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(FT_PRINTF) -o $(NAME)
#任何.o文件都可以用由同名文件.c编译得到
#（$<）第一个依赖文件（.c）   （$@）目标文件（.o）
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
clean:
#进入到自己的文件夹执行自己的clean
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(FT_PRINTF_DIR) clean
	rm -f $(OBJS)
fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(FT_PRINTF_DIR) fclean
	rm -f $(NAME)
	
re: fclean all
.PHONY: all clean fclean re

	