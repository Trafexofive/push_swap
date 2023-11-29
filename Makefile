
CC := cc

NAME	:= push_swap

CFLAGS	:= -Wextra -Wall -Werror 

SRCS	:= ./parse.c push_swap.c ./utils.c ./stack_operations.c

LIBFT := libft/libft.a

PRINTF := printf/libftprintf.a

OBJS	:= ${SRCS:.c=.o}

all: $(NAME)
	./push_swap 11 32 35 -888 1 200 540 1 002 -5 1666 -200 12000 200000

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(LIBFT) $(PRINTF) -o $(NAME)

lib : 
	make -C ./libft && make -C ./printf

%.o: %.c $(HEADERS) | lib
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make clean -C ./libft
	make clean -C ./printf
	rm -rf $(OBJS)

fclean: clean
	make fclean -C ./libft
	make fclean -C ./printf
	rm -rf $(NAME)

re: fclean all

.PHONY: all, lib, clean, fclean, re
