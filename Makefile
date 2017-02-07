# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmitriuc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/27 13:50:20 by mmitriuc          #+#    #+#              #
#    Updated: 2017/02/06 16:15:34 by mmitriuc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem_in
SRC = src/main.c \
	  src/ft_djikistra.c \
	  src/fillit.h
SRC = src/main.c \
	  src/ft_info.c \
	  src/ft_verf.c \
	  src/ft_read.c \
	  src/ft_verfificare.c \

 OBJ = $(SRC:.c=.o)
  FLAGS = -Wall -Wextra -Werror
  LIB = -Llib -lft
  INCLUDE = -Ilib
  EXTRAFLAGS = $(LIB) $(INCLUDE)
  LIB = lib/libft.a
  INCLUDE = -Ilib -Isrc
   all: $(NAME)

 $(NAME): $(OBJ)
     @gcc $(FLAGS) -o $(NAME) $(SRC) $(EXTRAFLAGS)
	     gcc $(FLAGS) $(INCLUDE) -o $(NAME) $(OBJ) $(LIB)

 $(OBJ): libft
 	@gcc $(FLAGS) $*.c -o $@ $(EXTRAFLAGS)
		gcc $(FLAGS) $*.c -o $@ -c $(INCLUDE)

 libft:
  	@make -C lib

 clean :
      	@rm -rf $(OBJ)%    
