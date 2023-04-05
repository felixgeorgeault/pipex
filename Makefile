# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fgeorgea <fgeorgea@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/08 16:13:35 by fgeorgea          #+#    #+#              #
#    Updated: 2023/04/05 13:46:11 by fgeorgea         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

DIR = srcs/

LIBFT = ar rcs $(NAME) ./include/libft/libft.a

DEPENDS = make -C include/libft

SRC =	$(DIR)pipex.c \
		$(DIR)init.c \
		$(DIR)error.c \
		$(DIR)debug.c \
		$(DIR)parsing.c \
		$(DIR)utils.c \
		$(DIR)pipe.c \
		$(DIR)chained_list.c \
		$(DIR)fork.c \
		
OBJ = ${SRC:.c=.o}

CFLAGS =  -Werror -Wextra -Wall

REMOVE = rm -f

COMPILE = gcc $(CFLAGS) -o $(NAME) -Iincludes -Linclude/libft -lft

all: $(NAME)

$(NAME): libft $(OBJ)
	@$(COMPILE) $(OBJ)

clean:
	@$(REMOVE) $(OBJ)
	@make -C include/libft clean

fclean:	clean
	@$(REMOVE) $(NAME)
	@make -C include/libft fclean
	
re: fclean all

libft: 
	@$(DEPENDS)

.PHONY: all clean fclean re libft
