# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xingchen <xingchen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/11 14:50:30 by xingchen          #+#    #+#              #
#    Updated: 2026/03/13 15:55:46 by xingchen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a

SRC = ft_isalnum.c ft_isdigit.c ft_memcmp.c ft_memset.c ft_strlcpy.c ft_strnstr.c ft_toupper.c ft_atoi.c ft_isalpha.c ft_isprint.c ft_memcpy.c ft_strchr.c ft_strlen.c ft_strrchr.c ft_bzero.c ft_isascii.c ft_memchr.c ft_memmove.c ft_strlcat.c ft_strncmp.c ft_tolower.c ft_strdup.c ft_calloc.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
BONUS_SRC = ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c ft_lstiter.c ft_lstdelone.c ft_lstclear.c ft_lstadd_front.c ft_lstadd_back.c

OBJS = $(SRC:.c=.o)
BONUS_OBJS = $(BONUS_SRC:.c=.o)

RM = rm -rf

all: $(NAME)
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)
bonus: $(NAME) $(BONUS_OBJS)
	ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)

clean: 
	$(RM) $(OBJS) $(BONUS_OBJS)
fclean: clean
	$(RM) $(NAME) 
re: fclean all
.PHONY: all clean fclean re bonus
