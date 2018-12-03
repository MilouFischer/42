# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: efischer <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/05 19:38:36 by efischer          #+#    #+#              #
#    Updated: 2018/11/06 19:00:28 by efischer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC = srcs/ft_putchar.c srcs/ft_putstr.c srcs/ft_strcmp.c srcs/ft_strlen.c srcs/ft_swap.c
HEAD = includes/libft.h
OBJ = ft_putchar.o ft_putstr.o ft_strcmp.o ft_strlen.o ft_swap.o

all: $(NAME) clean

$(OBJ):
	gcc -c $(SRC)

$(NAME): $(OBJ)
	ar -rcs $(NAME) $(OBJ)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
