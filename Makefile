
CC := cc

NAME	:= push_swap.c

CFLAGS	:= -Wextra -Wall -Werror 

SRCS	:= ./parse.c ./utils.c ./stack_operations.c

LIBFT := libft/libft.a

PRINTF := printf/libftprinf.a

OBJS	:= ${SRCS:.c=.o}

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(LIBFT) $(PRINTF) -o $(NAME)

lib : 
	make -C ./libft && make -C ./printf

%.o: %.c $(HEADERS) | lib
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make clean -C ./libft
	rm -rf $(OBJS)

fclean: clean
	make fclean -C ./libft
	rm -rf $(NAME)

re: fclean all

.PHONY: all, lib, clean, fclean, re
