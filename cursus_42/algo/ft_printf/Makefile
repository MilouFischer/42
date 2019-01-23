NAME = libftprintf.a
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
ft_strcasestr ft_strcapitalize get_next_line ft_print_matrix ft_printf \
ft_manage_conv ft_itoa_base ft_util
SRCS = $(patsubst %,%.c,$(FILES))
OBJS = $(SRCS:.c=.o) 
HEAD = libft.h ft_printf.h
CC = gcc
CFLAGS = -Wall -Wextra -Werror
DEBUG = -Wall -Wextra -Werror -fsanitize=address,undefined -g3

all: $(NAME)

%.o: %.c $(HEAD)
	@echo "Creating libft's objects..."
	@$(CC) $(DEBUG) -c $<

$(NAME): $(OBJS)
	@echo "Creating libftprintf.a..."
	@ar -rcs $(NAME) $(OBJS)

clean:
	@echo "Deleting libft's objects..."
	@rm -rf $(OBJS)

fclean: clean
	@echo "Deleting libftprintf.a..."
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
