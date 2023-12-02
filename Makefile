
CC := cc

NAME	:= push_swap

CFLAGS	:= -Wextra -Wall -Werror -fsanitize=address

SRCS	:= parse.c sort.c push_swap.c utils.c stack_operations.c

LIBFT := libft/libft.a

PRINTF := printf/libftprintf.a

OBJS	:= ${SRCS:.c=.o}

all: $(NAME)
	./push_swap  -111 1 -3 3 45454 5 11 32   35 1113     -200 -540 1666 12000

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(LIBFT) $(PRINTF) -o $(NAME)

lib : 
	make -C ./libft && make -C ./printf

push:
	git add .
	git commit -m "Lazy_push"
	git push
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
