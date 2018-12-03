# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: efischer <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/07 17:59:56 by efischer          #+#    #+#              #
#    Updated: 2018/11/30 15:44:01 by efischer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
FILES = ft_atoi ft_isalnum ft_isascii ft_isprint ft_strchr ft_strcpy ft_strlen ft_strncmp ft_strnstr ft_strstr ft_toupper ft_bzero ft_isalpha ft_isdigit ft_strcat ft_strcmp ft_strdup ft_strncat ft_strncpy ft_strrchr ft_tolower ft_memset ft_memchr ft_memcpy ft_memcmp ft_memccpy ft_putchar ft_putstr ft_putendl ft_putchar_fd ft_putstr_fd ft_putendl_fd ft_putnbr ft_putnbr_fd ft_itoa ft_memalloc ft_memdel ft_strclr ft_strdel ft_strnew ft_strsub ft_strjoin ft_strequ ft_strnequ ft_striter ft_striteri ft_strtrim ft_strmap ft_strmapi ft_strsplit ft_memmove ft_strlcat ft_lstnew ft_lstdelone ft_lstdel ft_lstadd ft_lstiter ft_lstmap
SRC = $(patsubst %,%.c,$(FILES))
OBJ = $(patsubst %,%.o,$(FILES))
FLAG = -Wall -Wextra -Werror

all: $(NAME)

$(OBJ): $(SRC)
	@gcc -c $(FLAG) $(SRC)

$(NAME): $(OBJ)
	@ar -rcs $(NAME) $(OBJ)

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all
