
#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "./libft/libft.h"
#include "./printf/ft_printf.h"

/***************** Macros ***************/





/***************** Structs **************/

typedef struct node 
{
	int				data;
    unsigned int    last;
    struct node     *top;
	struct node *next;
}t_node;

typedef struct stack_data
{
	t_node  *sa_data;
	t_node  *sb_data;
}t_data;

typedef t_node head;

/**************** Declaration ***************/

void fr(t_node *head);
int put_intarr(int *tab);
void traverseLinkedList(t_node* head);

/*-------------- Parsing --------------------*/
int *parse_multi(int ac, char **av, int *data);
int *parse_string(int ac, char **av, int *data);
int *ft_parse(int ac, char **av, int *data);
bool    is_duped(int *arr);

/*-------------- mandatory --------------------*/
t_node* create_node(int data);
#endif
