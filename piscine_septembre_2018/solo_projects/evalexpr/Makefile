# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: efischer <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/16 21:08:22 by efischer          #+#    #+#              #
#    Updated: 2018/09/16 21:40:09 by efischer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = eval_expr
SRC = main.c ft_do_op.c io.c
OBJ =  main.o ft_do_op.o io.o

$(NAME): all

all:
	gcc -Wall -Wextra -Werror -c $(SRC)
	gcc -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
