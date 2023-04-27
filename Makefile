# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fgeorgea <fgeorgea@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/08 16:13:35 by fgeorgea          #+#    #+#              #
#    Updated: 2023/04/27 15:25:02 by fgeorgea         ###   ########.fr        #
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

CFLAGS = -Wall -Wextra -Werror

REMOVE = rm -f

COMPILE = gcc $(CFLAGS) -o $(NAME) -Iincludes -Linclude/libft -lft

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(COMPILE) $(OBJ)

clean:
	$(REMOVE) $(OBJ)
	make -C include/libft clean

fclean:	clean
	$(REMOVE) $(NAME)
	make -C include/libft fclean
	
re: fclean all

$(LIBFT): 
	$(DEPENDS)

.PHONY: all clean fclean re libft
