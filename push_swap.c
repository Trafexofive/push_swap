// fill the stack from the arr,

#include "push_swap.h"
#include "printf/ft_printf.h"
#include <stdbool.h>
#include <stdio.h>

//put the int *data in a struct

// bool    free_atexit(t_head *stack_a,t_head *stack_b)
// {
//
// }

// more like node_linker

void    free_stack_2(t_head *stack)
{
	t_node  *tmp;
	t_node  *tmp2;

	tmp = stack->top;
	while (tmp)
	{
		tmp2 = tmp->next;
		free(tmp);
		tmp = tmp2;
	}
	free(stack);
}
// Function to create a new node with the given data
t_node  *create_node(int data, int index)
{
    t_node* new_node;

    new_node = (t_node*)ft_calloc(1, sizeof(t_node));
    if (!new_node)
        return (NULL);
    new_node->index = index;
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev= NULL;
    return new_node;
}

void fill_node(int data, t_head **stack)
{
	t_node *new_node;

	if ((*stack)->top == NULL)
	{
		new_node = create_node(data, 0);
		if (!new_node)
			return ;
		(*stack)->top = new_node;
		(*stack)->current = new_node;
	}
	else
	{
		new_node = create_node(data, 0);
		if (!new_node)
			return ;
		new_node->next = NULL;
		new_node->prev = (*stack)->current;
		(*stack)->current->next = new_node;
		(*stack)->current = new_node;
		(*stack)->stack_len = (*stack)->stack_len + 1;
		(*stack)->bottom = new_node;
		sort_index(*stack, new_node);
	}
}

// t_node  *fill_node(int data, t_head *stack)
// {
//     t_node  *new_node;
// 	t_node  *tmp;
    
//     if (stack->top == NULL)
//     {
//         new_node = create_node(data, 0);
//
//         if (new_node == NULL)
//         {
//             free_stack(stack);
//             return (NULL);
//         }
//         stack->top = new_node;
//         tmp = new_node;
//     }
//     else
//     {
//         new_node = create_node(data, 0);
//         if (new_node == NULL)
//         {
//             free_stack(stack);
//             return (NULL);
//         }
//         new_node->prev = stack->current;
//         tmp->next = new_node;
//         tmp = new_node;
//         stack->stack_len = stack->stack_len + 1;
//         if (stack->name == 'a')
//             sort_index(stack, new_node);
//     }
//     return (new_node);
// }

t_node *create_stack(int len, int *arr,t_head *stack)
{
	int i = 0;
	while (arr && i < len)
	{
		fill_node(arr[i], &stack);
        // if (tmp == NULL)
        // {
        //     free_stack(stack);
        //     return (NULL);
        // }
		i++;
	}
		// printf("stack->bottom->data = %d\n", stack->bottom->data);
	return (stack->bottom);
}


t_head  *stack_init(t_head *stack, char c)
{
    stack = (t_head *) ft_calloc(1, sizeof(t_head));
    if (stack == NULL)
        return (NULL);
    stack->name = c;
    stack->stack_len = 0;
	stack->top = NULL;
	stack->bottom = NULL;
    return (stack);
}


int main(int ac, char **av)
{
    t_head      *stack_a;
    t_head      *stack_b;
	int	        *data;
    size_t      len;

    data = 0;
	data = ft_parse(ac, av, data);
    len = ft_strlen_int(data);
    stack_a = NULL;
    stack_b = NULL;
    stack_a = stack_init(stack_a, 'a');
    stack_b = stack_init(stack_b, 'b');
    stack_a->bottom = create_stack(len, data, stack_a);
    // rotate(stack_a);
    
    // sa(stack_a);
    rotate(stack_a);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
	// reverse_rotate(stack_a);
    // printf("sort ===%d\n", issort);
    // ft_putnbr_fd(sort, 1);
    // pa(stack_a, stack_b);
	// pa(stack_a, stack_b);
	// pa(stack_a, stack_b);
    // sort(stack_a);
    // ft_printf("node data ====>%d\n", stack_a->bottom->prev->data);

    print_stacks(stack_a, stack_b);
    free_stack(stack_a);
    free_stack(stack_b);
	free(data);
	
	return EXIT_SUCCESS;
}
