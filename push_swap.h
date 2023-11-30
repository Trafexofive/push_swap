
#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "./libft/libft.h"
#include "./printf/ft_printf.h"

/***************** Macros ***************/


# define TRUE 1
# define FALSE 2



/***************** Structs **************/

typedef struct node 
{
	int				data;
    struct node     *prev;
	struct node     *next;
}t_node;

typedef struct s_head
{
    struct node     *top;
    struct node     *current;
    struct node     *bottom;
    unsigned int    *stack_len;
}t_head;



/**************** Declaration ***************/

void free_stack(t_head *head);
void    rotate(t_head *stack);
int put_intarr(int *tab);
void print_stacks(t_head* stack_a, t_head *stack_b);
size_t	ft_strlen_int(int *c);
void    swap(t_head *stack);
t_node  *fill_node(int data, t_head *head);
void    pop(t_head *stack, unsigned int index);
void    pop_last(t_head *stack);
void    push(t_head *stack_a, t_head *stack_b, char option);

/*-------------- Parsing --------------------*/
int *parse_multi(int ac, char **av, int *data);
int *parse_string(int ac, char **av, int *data);
int *ft_parse(int ac, char **av, int *data);
bool    is_duped(int *arr);

/*-------------- mandatory --------------------*/
t_node* create_node(int data);
#endif
