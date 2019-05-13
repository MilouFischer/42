# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: efischer <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/07 17:59:56 by efischer          #+#    #+#              #
#    Updated: 2019/05/13 17:09:28 by efischer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

#=====================================HEAD======================================

INCLUDES = includes/
HEAD += ft_printf.h
IFLAGS = -I

#=====================================PATH======================================

PATHS += srcs/
PATHO += objs/
PATHI += includes/
PATHLIB += libft/

#====================================COMPILE====================================

CC = clang
CFLAGS += -Wall
CFLAGS += -Wextra
CFLAGS += -Werror
COMPILE = $(CC) -c

#=====================================SRCS======================================

SRCS += ft_printf.c
SRCS += ft_manage_conv.c
SRCS += ft_util.c
SRCS += ft_flag.c
SRCS += ft_printfloat.c
SRCS += ft_manage_str.c
SRCS += ft_diouxx.c
SRCS += ft_long_diouxx.c
SRCS += ft_manage_p.c
SRCS += ft_width_precision.c
SRCS += ft_process_flag.c
SRCS += ft_printfloat.c
SRCS += ft_putunicode.c
SRCS += ft_check_unicode.c
SRCS += ft_convert_to_unicode.c
SRCS += ft_manage_unicode.c
SRCS += ft_round.c

#=====================================OBJS======================================

OBJS = $(patsubst %.c, $(PATHO)%.o, $(SRCS))

LIBFT = libft.a

vpath %.c $(PATHS)
vpath %.h $(PATHI)
vpath libft.a $(PATHLIB)

all: $(NAME)

$(NAME): $(LIBFT) $(PATHO) $(OBJS) $(HEAD)
	ar -rcs $(NAME) $(OBJS)

$(OBJS): $(PATHO)%.o: %.c
	$(COMPILE) $(CFLAGS) $< $(IFLAGS) $(INCLUDES) -o $@

$(LIBFT):
	make -C $(PATHLIB)

$(PATHO):
	mkdir $@

clean:
	$(RM) $(OBJS)
	$(RM) -R $(PATHO)
	make clean -C $(PATHLIB)

fclean: clean
	$(RM) $(NAME)
	make fclean -C $(PATHLIB)

re: fclean all

up:
	git add -A
	git status
	git commit -m"up"
	git push

.PHONY: all clean fclean re up
