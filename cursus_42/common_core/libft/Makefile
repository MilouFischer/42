# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: efischer <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/07 17:59:56 by efischer          #+#    #+#              #
#    Updated: 2018/12/03 18:39:31 by efischer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
HEAD = libft.h
FILES = ft_atoi ft_isalnum ft_isascii ft_isprint ft_strchr ft_strcpy ft_strlen \
ft_strncmp ft_strnstr ft_strstr ft_toupper ft_bzero ft_isalpha ft_isdigit \
ft_strcat ft_strcmp ft_strdup ft_strncat ft_strncpy ft_strrchr ft_tolower \
ft_memset ft_memchr ft_memcpy ft_memcmp ft_memccpy ft_putchar ft_putstr \
ft_putendl ft_putchar_fd ft_putstr_fd ft_putendl_fd ft_putnbr ft_putnbr_fd \
ft_itoa ft_memalloc ft_memdel ft_strclr ft_strdel ft_strnew ft_strsub \
ft_strjoin ft_strequ ft_strnequ ft_striter ft_striteri ft_strtrim ft_strmap \
ft_strmapi ft_strsplit ft_memmove ft_strlcat ft_lstnew ft_lstdelone ft_lstdel \
ft_lstadd ft_lstiter ft_lstmap ft_factorial ft_power ft_isblank ft_iscntrl \
ft_isgraph ft_islower ft_isspace ft_isupper ft_isxdigit ft_str_is_alpha \
ft_str_is_lowercase ft_str_is_numeric ft_str_is_printable ft_str_is_uppercase \
ft_strlowcase ft_strupcase ft_strndup ft_strcasecmp ft_strncasecmp \
ft_strcasestr ft_strcapitalize get_next_line ft_print_matrix ft_itoa_base \
ft_atoi_base ft_convert_to_unicode ft_putunicode ft_check_unicode \
ft_join_free ft_free_matrix ft_free_tab ft_itoa_base_u ft_intlen ft_intlen_u
SRCS = $(patsubst %,%.c,$(FILES))
OBJS = $(SRCS:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

%.o: %.c $(HEAD)
	$(CC) $(CFLAGS) -c $(SRCS)

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean re
