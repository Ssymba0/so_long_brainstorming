# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: isabri <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/02 17:53:29 by isabri            #+#    #+#              #
#    Updated: 2021/12/02 18:10:37 by isabri           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_printf.c\
	ft_putaddr.c\
	ft_putchar.c\
	ft_putnbr_d.c\
	ft_putnbr_hexl.c\
	ft_putnbr_hexu.c\
	ft_putnbr_i.c\
	ft_putnbr_u.c\
	ft_putstr.c\
	ft_strlen.c

OBJS = $(SRCS:%.c=%.o)

CFLAGS = -Wall -Werror -Wextra

CC = gcc

all : $(NAME)

$(NAME) : $(OBJS)
	ar rc $(NAME) $(OBJS)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all
