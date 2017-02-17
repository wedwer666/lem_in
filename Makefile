# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pcervac <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/06 19:12:39 by pcervac           #+#    #+#              #
#    Updated: 2017/02/17 19:06:42 by pcervac          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=lem_in

SRC_PATH=./srcs/
SRC_FILES=main.c		\
		  read_input.c	\
		  flags.c		\
		  error.c		\
		  rooms.c		\
		  array.c	 	\
		  dijkstra.c 
SRC=$(addprefix $(SRC_PATH),$(SRC_FILES))

INC_PATH=./includes/
INC_FILES=

OBJ_PATH=./obj/
OBJ=$(addprefix $(OBJ_PATH),$(notdir $(SRC:.c=.o)))

LIB_PATH=./libft/
LIB_INC=./libft/includes/
LIB=libft.a
LIB_LINK=-L$(LIB_PATH) $(subst lib,-lft,$(subst ft.a, ,$(LIB)))

CC=cc
CFLAGS=-Wall -Wextra

AUTHOR_FILE=./auteur

all: $(NAME) $(LIB_PATH)$(LIB)

$(NAME): $(LIB_PATH)$(LIB) $(OBJ)
	@/bin/echo -n 'Compile' $(NAME) 'executable ...'
	@$(CC) $(OBJ) $(LIB_LINK) -o $(NAME)
	@/bin/echo '[done]'

$(LIB_PATH)$(LIB):
	@make -C $(LIB_PATH) $(LIB)

$(OBJ): $(OBJ_PATH)
	@/bin/echo -n 'Compile' $(NAME) 'files ...'
	@$(CC) $(CFLAGS) -c $(SRC) -I$(INC_PATH) -I$(LIB_INC)
	@/bin/echo '[done]'
	@/bin/echo -n 'Move' $(NAME) 'objects files ...'
	@/bin/mv $(notdir $(OBJ)) $(OBJ_PATH)
	@/bin/echo '[done]'

$(OBJ_PATH):
	@/bin/mkdir $(OBJ_PATH)

clean:
	@/bin/echo -n 'Removing' $(NAME) 'objects ...'
	@/bin/rm -f $(OBJ)
	@/bin/echo '[done]'
	@make -C $(LIB_PATH) clean

fclean: clean
	@/bin/echo -n 'Removing' $(NAME) 'executable ...'
	@/bin/rm -f $(NAME)
	@/bin/echo '[done]'

ls:
	@make -C $(LIB_PATH) fclean

re: fclean all

author:
	@/bin/cat $(AUTHOR_FILE)
n:
	@norminette $(SRC) $(INC)

.PHONY: author clean fclean all n re
