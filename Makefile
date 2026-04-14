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
INC = push_swap.h
SRC = create_stack.c \
	  find_best_node.c \
	  sort_stack.c \
	  ft_atol.c \
	  ft_parsing.c \
	  ft_sort_numbers.c \
	  ft_split_tokens.c \
	  push_swap.c \
	  push.c \
	  reverse_rotate.c \
	  rotate_moves.c rotate.c \
	  set_cost.c \
	  set_position.c \
	  set_target.c \
	  sort_small_stack.c \
	  stack_utils.c swap.c

# 将 .c 文件名替换为 .o / Conversion des noms .c en .o
OBJS = $(SRC:.c=.o)

# Libft 的路径与库文件 / Chemin et fichier de la bibliothèque Libft
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

# 默认目标 / Cible principale
all: $(LIBFT) $(NAME)

# ------------------------------------------------------------------------------
# 编译规则 / Règles de Compilation
# ------------------------------------------------------------------------------

# 编译 libft / Compiler la libft
# -C 表示切换到目录执行 make / -C pour exécuter make dans le dossier libft
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

# 链接程序 / Lien du programme final
# 依赖 OBJS 和 LIBFT / Dépend de OBJS et LIBFT
$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

# 编译 .o 对象文件 / Compilation des fichiers objets (.o)
# $< 表示源文件，$@ 表示目标文件 / $< source, $@ cible
%.o: %.c $(INC)
	$(CC) $(CFLAGS) -c $< -o $@

# ------------------------------------------------------------------------------
# 清理规则 / Règles de Nettoyage
# ------------------------------------------------------------------------------

# 清理对象文件 / Supprimer les fichiers objets
clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJS)

# 彻底清理（包括可执行文件） / Nettoyage complet (incluant l'exécutable)
fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

# 重新编译 / Recompiler tout	
re: fclean all

# 伪目标声明，防止文件名冲突 / Déclarer les cibles bidon pour éviter les conflits
.PHONY: all clean fclean re

#有空格：$(OBJS) $(LIBFT) 代表两个独立的文件。
#没空格：$(OBJS)$(LIBFT) 会被 make 看作是一个长字符串。
#就像法语中 pomme de terre（土豆）如果写成 pommedeterre，词义就混淆了。

	
