
CFLAGS := -Wall -Wextra -Werror
NAME := push_swap
SRC := ./push_swap.c ./utils.c
OBJ := $(SRC:.c=.o)
HEADERS := push_swap.h ./libft/libft.h
RM := rm -rf
CC := cc

all : $(NAME)

%.o : %.c 
	$(CC) $(CFLAGS) $^ -o $%
push :
	git add .
	git commit -m "fast commit"
	git push
clean : 
	$(RM) $(OBJ)
fclean :
	$(RM) $(NAME)
re : fclean all

.PHONY : clean fclean re all
