# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fgeorgea <fgeorgea@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/08 16:13:35 by fgeorgea          #+#    #+#              #
#    Updated: 2023/05/31 01:11:37 by fgeorgea         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

DIR = srcs/

DEPENDS = make -C include/libft

SRC = $(DIR)pipex.c \
		$(DIR)init.c \
		$(DIR)error.c \
		$(DIR)parsing.c \
		$(DIR)utils.c \
		$(DIR)chained_list.c \
		$(DIR)fork.c \
		$(DIR)pipe.c \
		$(DIR)exec.c \
		$(DIR)fork_utils.c \
		$(DIR)init_utils.c \
		$(DIR)free.c \
		$(DIR)here_doc.c \

OBJ = ${SRC:.c=.o}

CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g

REMOVE = rm -f

COMPILE = gcc $(CFLAGS) -o $(NAME)

all: $(NAME)

$(NAME): $(OBJ)
	make -C include/libft
	$(COMPILE) $(OBJ) -Iinclude -Linclude/libft -lft

clean:
	$(REMOVE) $(OBJ)
	make -C include/libft clean

fclean:	clean
	$(REMOVE) $(NAME)
	make -C include/libft fclean
	
re: fclean all

.PHONY: all clean fclean re
