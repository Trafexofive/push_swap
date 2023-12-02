
CC := cc

NAME	:= push_swap

CFLAGS	:= -Wextra -Wall -Werror -g -fsanitize=address,undefined

SRCS	:= parse.c sort.c push_swap.c utils.c stack_operations.c stack_initialize.c

LIBFT := libft/libft.a

PRINTF := printf/libftprintf.a

OBJS	:= ${SRCS:.c=.o}

all: $(NAME)
	./push_swap  3 1555 2 4 5 6 7 85 93 10 11 1255 13 14 15 16 17 183 19 20 

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(PRINTF) -o $(NAME)

lib : 
	@make -C ./libft && make -C ./printf

push:
	git add .
	git commit -m "Lazy_push"
	git push
%.o: %.c $(HEADERS) | lib
	@$(CC) $(CFLAGS) -c $< -o $@

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
