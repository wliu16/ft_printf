# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wliu <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/29 14:26:26 by wliu              #+#    #+#              #
#    Updated: 2017/01/23 15:56:28 by wliu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_atoi.c ft_is.c \
		ft_itoa_j.c \
		ft_uns_int.c  \
		ft_printf.c ft_putchar.c ft_putstr.c ft_strdup.c ft_strlen.c \
		ft_strncpy.c ft_strnew.c store1.c store2.c store_str.c \
		str_char_wchar.c str_sig_int.c \
		str_sp_zero.c str_str_wstr.c str_uns_int.c

O_FILES = ft_atoi.o ft_is.o \
		ft_itoa_j.o \
		ft_uns_int.o  \
		ft_printf.o ft_putchar.o ft_putstr.o ft_strdup.o ft_strlen.o \
		ft_strncpy.o ft_strnew.o store1.o store2.o store_str.o \
		str_char_wchar.o str_sig_int.o  \
		str_sp_zero.o str_str_wstr.o str_uns_int.o 

FLAGS = -c -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
		gcc $(FLAGS) $(SRC)
		ar rc $(NAME) $(O_FILES)
		ranlib $(NAME)

clean:
		/bin/rm -f $(O_FILES)

fclean: clean
		/bin/rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
