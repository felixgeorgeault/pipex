# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fgeorgea <fgeorgea@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/08 16:13:35 by fgeorgea          #+#    #+#              #
#    Updated: 2023/04/17 15:53:43 by fgeorgea         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

DIR = srcs/

DIR_BONUS = srcs_bonus/

LIBFT = ar rcs $(NAME) ./include/libft/libft.a

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

SRC_BONUS = $(DIR_BONUS)pipex_bonus.c \
			$(DIR_BONUS)init_bonus.c \
			$(DIR_BONUS)error_bonus.c \
			$(DIR_BONUS)parsing_bonus.c \
			$(DIR_BONUS)utils_bonus.c \
			$(DIR_BONUS)chained_list_bonus.c \
			$(DIR_BONUS)fork_bonus.c \
			$(DIR_BONUS)pipe_bonus.c \
			$(DIR_BONUS)exec_bonus.c \
			$(DIR_BONUS)fork_utils_bonus.c \
			$(DIR_BONUS)init_utils_bonus.c \
			$(DIR_BONUS)here_doc_bonus.c \
			$(DIR_BONUS)get_next_line_bonus.c \
			$(DIR_BONUS)get_next_line_utils_bonus.c \
			$(DIR_BONUS)free_bonus.c \

%.o: %.c
	$(CC) $(FLAGS) -o $@ -c $<
		
OBJ = ${SRC:.c=.o}
OBJ_BONUS = ${SRC_BONUS:.c=.o}

CFLAGS = -Wall -Wextra -Werror

REMOVE = rm -f

COMPILE = gcc $(CFLAGS) -o $(NAME) -Iincludes -Linclude/libft -lft

all: $(NAME)

$(NAME): libft $(OBJ)
	@$(COMPILE) $(OBJ)

bonus: libft $(OBJ_BONUS)
	@$(COMPILE) $(OBJ_BONUS)

clean:
	@$(REMOVE) $(OBJ) $(OBJ_BONUS)
	@make -C include/libft clean

fclean:	clean
	@$(REMOVE) $(NAME)
	@make -C include/libft fclean

clean_bonus:
	@$(REMOVE) $(OBJ_BONUS)
	@make -C include/libft clean

fclean_bonus: clean_bonus
	@$(REMOVE) $(NAME)
	@make -C include/libft fclean
	
re: fclean all

libft: 
	@$(DEPENDS)

.PHONY: all clean fclean re libft bonus clean_bonus fclean_bonus