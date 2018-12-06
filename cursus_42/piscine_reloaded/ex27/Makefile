# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: efischer <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 18:13:59 by efischer          #+#    #+#              #
#    Updated: 2018/11/06 18:24:03 by efischer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_display_file
SRC = ft_display_file.c
OBJ = ft_display_file.o

all: $(NAME) clean

$(OBJ):
	@gcc -c -Wall -Wextra -Werror $(SRC)

$(NAME): $(OBJ)
	@gcc $(OBJ) -o $(NAME)

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)
