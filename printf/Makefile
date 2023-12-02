# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlamkadm <mlamkadm@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/14 22:13:31 by mlamkadm          #+#    #+#              #
#    Updated: 2023/12/02 03:24:11 by mlamkadm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror
CC = cc

NAME = libftprintf.a

SRC = ft_printf.c ft_putchar.c ft_putstr.c ft_putnbr.c ft_putnbr_unsigned.c ft_puthexa.c ft_puthexa_caps.c\

OBJ = $(SRC:.c=.o)

HEADER = ft_printf.h

AR = ar -rcs

RM = rm -rf

all : $(NAME)

$(NAME) : $(OBJ)
	$(AR) $(NAME) $(OBJ)

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)
	
re : fclean all

.PHONY : clean fclean re all
