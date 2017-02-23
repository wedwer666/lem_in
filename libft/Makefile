# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmihalac <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/10/10 15:00:20 by nmihalac          #+#    #+#              #
#    Updated: 2017/02/19 20:59:07 by pcervac          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft.a

SRC=ft_wchar/ft_putwchar.c \
	ft_wchar/ft_putwchar_fd.c \
	ft_wchar/ft_putwstr.c \
	ft_wchar/ft_putwstr_fd.c \
	ft_wchar/ft_wbits.c \
	ft_wchar/ft_wstrcpy.c \
	ft_wchar/ft_wstrdel.c \
	ft_wchar/ft_wstrdup.c \
	ft_wchar/ft_wstrlen.c \
	ft_wchar/ft_wstrnew.c \
	\
	ft_string/ft_strcat.c \
	ft_string/ft_strchr.c \
	ft_string/ft_strclr.c \
	ft_string/ft_strcmp.c \
	ft_string/ft_strcpy.c \
	ft_string/ft_strdel.c \
	ft_string/ft_strdup.c \
	ft_string/ft_strequ.c \
	ft_string/ft_striter.c \
	ft_string/ft_striteri.c \
	ft_string/ft_strjoin.c \
	ft_string/ft_strlcat.c \
	ft_string/ft_strlen.c \
	ft_string/ft_strmap.c \
	ft_string/ft_strmapi.c \
	ft_string/ft_strncat.c \
	ft_string/ft_strncmp.c \
	ft_string/ft_strncpy.c \
	ft_string/ft_strnequ.c \
	ft_string/ft_strnew.c \
	ft_string/ft_strnstr.c \
	ft_string/ft_strrchr.c \
	ft_string/ft_strrev.c \
	ft_string/ft_strsplit.c \
	ft_string/ft_strstr.c \
	ft_string/ft_strsub.c \
	ft_string/ft_strtrim.c \
	ft_string/ft_isnbr.c \
	ft_string/ft_strtolower.c \
	\
	ft_stdlib/ft_abs.c \
	ft_stdlib/ft_atoi.c \
	ft_stdlib/ft_atoib.c \
	ft_stdlib/ft_atoibb.c \
	ft_stdlib/ft_atol.c \
	ft_stdlib/ft_atolb.c \
	ft_stdlib/ft_atolbb.c \
	ft_stdlib/ft_atoll.c \
	ft_stdlib/ft_atollb.c \
	ft_stdlib/ft_atollbb.c \
	ft_stdlib/ft_bzero.c \
	ft_stdlib/ft_itoa.c \
	ft_stdlib/ft_itoab.c \
	ft_stdlib/ft_memrealloc.c \
	ft_stdlib/ft_memalloc.c \
	ft_stdlib/ft_memccpy.c \
	ft_stdlib/ft_memchr.c \
	ft_stdlib/ft_memcmp.c \
	ft_stdlib/ft_memcpy.c \
	ft_stdlib/ft_memdel.c \
	ft_stdlib/ft_memmove.c \
	ft_stdlib/ft_memset.c \
	ft_stdlib/ft_utoa.c \
	ft_stdlib/ft_utoab.c \
	\
	ft_stdio/ft_get_next_line.c \
	ft_stdio/ft_putchar.c \
	ft_stdio/ft_putchar_fd.c \
	ft_stdio/ft_putendl.c \
	ft_stdio/ft_putendl_fd.c \
	ft_stdio/ft_putnbr.c \
	ft_stdio/ft_putnbr_fd.c \
	ft_stdio/ft_putnendl.c \
	ft_stdio/ft_putnendl_fd.c \
	ft_stdio/ft_putnstr.c \
	ft_stdio/ft_putnstr_fd.c \
	ft_stdio/ft_putstr.c \
	ft_stdio/ft_putstr_fd.c \
	\
	ft_printf/ft_printf.c \
	ft_printf/getfl.c \
	ft_printf/print_char.c \
	ft_printf/print_float.c \
	ft_printf/print_int.c \
	ft_printf/print_other.c \
	ft_printf/print_str.c \
	ft_printf/print_wchar.c \
	ft_printf/print_wstr.c \
	\
	ft_list/ft_lstadd.c \
	ft_list/ft_lstaddb.c \
	ft_list/ft_lstdel.c \
	ft_list/ft_lstdelone.c \
	ft_list/ft_lstiter.c \
	ft_list/ft_lstmap.c \
	ft_list/ft_lstnew.c \
	\
	ft_ctype/ft_isalnum.c \
	ft_ctype/ft_isalpha.c \
	ft_ctype/ft_isascii.c \
	ft_ctype/ft_isdigit.c \
	ft_ctype/ft_isprint.c \
	ft_ctype/ft_isspace.c \
	ft_ctype/ft_tolower.c \
	ft_ctype/ft_toupper.c \
	\
	ft_cllist/ft_lstc_add_l.c \
	ft_cllist/ft_lstc_add_r.c \
	ft_cllist/ft_lstc_del.c \
	ft_cllist/ft_lstc_delone.c \
	ft_cllist/ft_lstc_getsize.c \
	ft_cllist/ft_lstc_iter_l.c \
	ft_cllist/ft_lstc_iter_r.c \
	ft_cllist/ft_lstc_new.c \
	ft_cllist/ft_lstc_swap_l.c \
	ft_cllist/ft_lstc_swap_r.c


INC_PATH=./includes/
INC_FILES=ft_cllist.h ft_ctype.h ft_list.h ft_printf.h ft_stdio.h ft_stdlib.h \
			ft_string.h ft_wchar.h libft.h
INC=$(addprefix $(INC_PATH),$(INC_FILES))

OBJ_PATH=./obj/
OBJ=$(addprefix $(OBJ_PATH),$(notdir $(SRC:.c=.o)))

AUTHOR_FILE=auteur

CC=cc
CFLAGS=-Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	@echo -n 'Creating library ... '
	@ar rc $(NAME)  $(OBJ)
	@ranlib $(NAME)
	@echo '[done]'

$(OBJ):$(OBJ_PATH)
	@echo -n 'Compile files ... '
	@$(CC) $(CFLAGS) -c $(SRC) -I$(INC_PATH)
	@echo '[done]'
	@echo -n 'Move object files ... '
	@/bin/mv $(notdir $(OBJ)) $(OBJ_PATH) 
	@echo '[done]'

$(OBJ_PATH):
	@/bin/mkdir $(OBJ_PATH)

clean:
	@echo -n 'Removing objects ... '
	@/bin/rm -f $(OBJ)
	@echo '[done]'

fclean: clean
	@echo -n 'Removing library ... '
	@/bin/rm -f $(NAME)
	@echo '[done]'

re: fclean all

author:
	@/bin/cat/ $(AUTHOR_FILE)

n:
	@norminette $(SRC) $(INC)
.PHONY: clean
