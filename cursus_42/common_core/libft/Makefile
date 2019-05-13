# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: efischer <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/07 17:59:56 by efischer          #+#    #+#              #
#    Updated: 2019/05/13 17:01:32 by efischer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

#=====================================HEAD======================================

INCLUDES = includes/
HEAD += libft.h
HEAD += struct.h
IFLAGS = -I

#=====================================PATH======================================

PATHS += srcs/
PATHO += objs/
PATHI += includes/

#====================================COMPILE====================================

CC = clang
CFLAGS += -Wall
CFLAGS += -Wextra
CFLAGS += -Werror
COMPILE += $(CC) -c

#=====================================SRCS======================================

SRCS += ft_atoi.c
SRCS += ft_isalnum.c
SRCS += ft_isascii.c
SRCS += ft_isprint.c
SRCS += ft_strchr.c
SRCS += ft_strcpy.c
SRCS += ft_strlen.c
SRCS += ft_strncmp.c
SRCS += ft_strnstr.c
SRCS += ft_strstr.c
SRCS += ft_toupper.c
SRCS += ft_bzero.c
SRCS += ft_isalpha.c
SRCS += ft_isdigit.c
SRCS += ft_strcat.c
SRCS += ft_strcmp.c
SRCS += ft_strdup.c
SRCS += ft_strncat.c
SRCS += ft_strncpy.c
SRCS += ft_strrchr.c
SRCS += ft_tolower.c
SRCS += ft_memset.c
SRCS += ft_memchr.c
SRCS += ft_memcpy.c
SRCS += ft_memcmp.c
SRCS += ft_memccpy.c
SRCS += ft_putchar.c
SRCS += ft_putstr.c
SRCS += ft_putendl.c
SRCS += ft_putchar_fd.c
SRCS += ft_putstr_fd.c
SRCS += ft_putendl_fd.c
SRCS += ft_putnbr.c
SRCS += ft_putnbr_fd.c
SRCS += ft_itoa.c
SRCS += ft_memalloc.c
SRCS += ft_memdel.c
SRCS += ft_strclr.c
SRCS += ft_strdel.c
SRCS += ft_strnew.c
SRCS += ft_strsub.c
SRCS += ft_strjoin.c
SRCS += ft_strequ.c
SRCS += ft_strnequ.c
SRCS += ft_striter.c
SRCS += ft_striteri.c
SRCS += ft_strtrim.c
SRCS += ft_strmap.c
SRCS += ft_strmapi.c
SRCS += ft_strsplit.c
SRCS += ft_memmove.c
SRCS += ft_strlcat.c
SRCS += ft_lstnew.c
SRCS += ft_lstdelone.c
SRCS += ft_lstdel.c
SRCS += ft_lstadd.c
SRCS += ft_lstiter.c
SRCS += ft_lstmap.c
SRCS += ft_factorial.c
SRCS += ft_power.c
SRCS += ft_isblank.c
SRCS += ft_iscntrl.c
SRCS += ft_isgraph.c
SRCS += ft_islower.c
SRCS += ft_isspace.c
SRCS += ft_isupper.c
SRCS += ft_isxdigit.c
SRCS += ft_str_is_alpha.c
SRCS += ft_str_is_lowercase.c
SRCS += ft_str_is_numeric.c
SRCS += ft_str_is_printable.c
SRCS += ft_str_is_uppercase.c
SRCS += ft_strlowcase.c
SRCS += ft_strupcase.c
SRCS += ft_strndup.c
SRCS += ft_strcasecmp.c
SRCS += ft_strncasecmp.c
SRCS += ft_strcasestr.c
SRCS += ft_strcapitalize.c
SRCS += ft_atoi_base.c
SRCS += ft_intlen.c
SRCS += ft_intlen_u.c
SRCS += ft_itoa_base.c
SRCS += ft_itoa_base_u.c
SRCS += ft_join_free.c
SRCS += ft_lstfree.c
SRCS += ft_lstnew_str.c
SRCS += ft_lstnew_void.c
SRCS += ft_lstprint.c
SRCS += ft_memjoin.c
SRCS += ft_print_matrix.c
SRCS += ft_strndup_free.c
SRCS += get_next_line.c

OBJS = $(patsubst %.c, $(PATHO)%.o, $(SRCS))

vpath %.c $(PATHS)
vpath %.h $(PATHI)

all: $(NAME)

$(NAME): $(PATHO) $(OBJS) $(HEAD)
	ar -rcs $(NAME) $(OBJS)

$(OBJS): $(PATHO)%.o: %.c
	$(COMPILE) $(CFLAGS) $< $(IFLAGS) $(INCLUDES) -o $@

$(PATHO):
	mkdir $@

clean:
	$(RM) $(OBJS)
	$(RM) -R $(PATHO)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean
