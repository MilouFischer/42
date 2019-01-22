# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: efischer <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/17 13:50:41 by efischer          #+#    #+#              #
#    Updated: 2019/01/15 13:47:39 by efischer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DEBUG = no
NAME = fdf
FILE = color event event2 main  create_window matrix print_image print_line rotation init
SRCS = $(patsubst %,%.c,$(FILE))
OBJ = $(SRCS:.c=.o)
INCLUDES = -I /usr/local/include
FRAMEWORK = -lmlx -framework OpenGL -framework AppKit
LIB = libft/libft.a
CC = gcc
ifeq ($(DEBUG), yes)
	FLAG = -Wall -Wextra -Werror -fsanitize=address,undefined -g3 -g
else
	FLAG = -Wall -Wextra -Werror
endif

.PHONY: libft libclean clean fclean re

all: $(NAME)
ifeq ($(DEBUG), yes)
	@echo "Debug mode"
else
	@echo "Release mode"
endif


%.o: %.c $(LIB) fdf.h
	@echo "Creating fdf's objects..."
	@$(CC) $(FLAG) -c $< $(INCLUDES)

$(LIB): 
	@make -C libft

$(NAME): $(OBJ)
	@echo "Creating fdf.exe..."
	@$(CC) $(FLAG) $(FRAMEWORK) $(OBJ) libft/libft.a -o $(NAME) $(INCLUDES)

libclean:
	@make clean -C libft

libfclean:
	@make fclean -C libft

clean: libclean
	@echo "Deleting fdf's objects..."
	@rm -rf $(OBJ)

fclean: clean libfclean
	@echo "Deleting fdf.exe..."
	@rm -rf $(NAME)

re: fclean all
