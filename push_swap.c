// fill the stack from the arr,

#include "push_swap.h"
#include "printf/ft_printf.h"
#include <stdbool.h>
#include <stdio.h>

//void	print_node(int index, node_t head)

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

t_node  *fill_node(int data, t_head *stack)
{
    t_node  *new_node;
    
    if (stack->top == NULL)
    {
        new_node = create_node(data, 0);
        if (new_node == NULL)
        {
            free_stack(stack);
            return (NULL);
        }
        stack->top = new_node;
        stack->current = new_node;
    }
    else
    {
        new_node = create_node(data, 0);
        if (new_node == NULL)
        {
            free_stack(stack);
            return (NULL);
        }
        new_node->prev = stack->current;
        stack->current->next = new_node;
        stack->current = new_node;
        stack->stack_len = stack->stack_len + 1;
        if (stack->name == 'a')
            sort_index(stack, new_node);
    }
    return (new_node);
}

t_node *create_stack(int len, int *arr,t_head *stack)
{
    t_node  *tmp; 
	int i = 0;

    tmp = 0;
	while (arr)
	{
        if (i == len)
            break;
		tmp = fill_node(arr[i], stack); 
        if (tmp == NULL)
        {
            free_stack(stack);
            return (NULL);
        }
		i++;
	}
    tmp = tmp->prev;
	tmp->next = NULL;
    stack->bottom = tmp;
	return (tmp);
}


t_head  *stack_init(t_head *stack)
{
    stack = (t_head *) ft_calloc(1, sizeof(t_head));
    if (stack == NULL)
        return (NULL);
    if (stack->name)
	{
        stack->name = 'b';
		stack->bottom = NULL;
	}
    stack->name = 'a';
    stack->stack_len = 0;
	stack->top = NULL;
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
    stack_a = stack_init(stack_a);
    stack_b = stack_init(stack_b);

    stack_a->bottom = create_stack(len, data, stack_a);



    // rotate(stack_a);
    
    // ft_printf("node data ====>%d\n", stack_a->bottom->data);
    // reverse_rotate(stack_a);
    // pop_last(stack_a);
    // swap(stack_a);

    // issort = is_sort(stack_a);
    // printf("sort ===%d\n", issort);

    // ft_putnbr_fd(sort, 1);
    pa(stack_a, stack_b);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
    // pb(stack_a, stack_b);
	// pb(stack_a, stack_b);
	// pb(stack_a, stack_b);
    sort(stack_b);
    printf("%d ===== stack_len", stack_b->stack_len);


    print_stacks(stack_a, stack_b);
    free_stack(stack_a);
    free_stack(stack_b);
	free(data);
	
	return EXIT_SUCCESS;
}
