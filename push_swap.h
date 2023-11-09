
#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H


#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct node 
{
	int				data;
	struct node *next;
}t_node;

typedef struct stack_data
{
	int	*sa_data;
	int	*sb_data;
}t_data;


void freeLinkedList(t_node *head);

#endif
