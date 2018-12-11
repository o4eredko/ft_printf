# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yochered <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/30 13:05:07 by yochered          #+#    #+#              #
#    Updated: 2018/11/30 13:22:18 by yochered         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
FLAGS = -c -Wall -W -Werror
SRCDIR = ./src/
INCDIR = ./includes/
SRC = convert_to_str.c ft_printf.c handlers.c function_array.c print_int.c\
	print_pointer.c print_str.c str_functions.c mem_funcs.c int_funcs.c\
	allowed_symbols.c print_uint.c print_float.c bonus_types.c print_funcs.c
OBJ = $(addprefix $(SRCDIR), $(SRC:.c=.o))

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

$(SRCDIR)%.o: $(SRCDIR)%.c
	gcc $(FLAGS) -o $@ $< -I $(INCDIR)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

run: fclean all
	gcc src/main.c -L. -lftprintf
	clear
	./a.out
	@make clean --silent
