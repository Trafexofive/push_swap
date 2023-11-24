
#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H


#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include "./libft/libft.h"

typedef struct node 
{
	int				data;
    unsigned int    cursor;
    unsigned int    tail;
	struct node *next;
}t_node;

typedef struct s_parse_data
{
    int     ac;
    int     *parse_arr;
}t_parse;

typedef struct stack_data
{
	int	*sa_data;
	int	*sb_data;
}t_data;


void freeLinkedList(t_node *head);

#endif
