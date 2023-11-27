
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
	int	*sa_data;
	int	*sb_data;
}t_data;

/**************** Declaration ***************/

void freeLinkedList(t_node *head);

#endif
