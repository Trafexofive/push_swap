
#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "./libft/libft.h"
#include "./printf/ft_printf.h"

/***************** Macros ***************/





/***************** Structs **************/

typedef struct node 
{
	int				data;
    unsigned int    cursor;
    unsigned int    tail;
	struct node *next;
}t_node;

typedef struct stack_data
{
	t_node  *sa_data;
	t_node  *sb_data;
}t_data;

/**************** Declaration ***************/

void freeLinkedList(t_node *head);
int put_intarr(int *tab);

/*-------------- Parsing --------------------*/
int *parse_multi(int ac, char **av, int *data);
int *parse_string(int ac, char **av, int *data);
int *ft_parse(int ac, char **av);
bool    is_duped(int *arr);

/*-------------- mandatory --------------------*/
#endif
