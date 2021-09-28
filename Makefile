# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lverkart <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/03 14:23:41 by lverkart          #+#    #+#              #
#    Updated: 2021/05/03 14:23:43 by lverkart         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

RM		=	rm -f

SRC		=	ft_printf.c		ft_lists.c		ft_printf_utils.c \
			ft_int_type.c	ft_char_type.c	ft_hex_type.c \
			ft_pointer_type.c	ft_parse.c

HEADER	=	printfft.h

OBJ		=	$(patsubst %.c,%.o,$(SRC))


all		:	$(NAME)

$(NAME)	:	$(OBJ) $(HEADER)
	ar rsc $(NAME) $?

%.o		: 	%.c $(HEADER)
	$(CC) $(CFLAGS) -o $@ -c $<

clean	:
	$(RM) $(OBJ)

fclean	:	clean
	$(RM) $(NAME)

re		:	fclean all

.PHONY	:	all clean fclean re 
