// fill the stack from the arr,

#include "push_swap.h"
#include "printf/ft_printf.h"

//void	print_node(int index, node_t head)


t_node  *fill_node(int data, t_head *stack)
{
    t_node  *new_node;
    
    if (stack->top == NULL)
    {
        new_node = create_node(data);
        if (new_node == NULL)
        {
            free_stack(stack);
            return (NULL);
        }
        new_node->index = 0;
        stack->stack_len = 0;
        stack->top = new_node;
        stack->current = new_node;
    }
    else
    {
        new_node = create_node(data);
        if (new_node == NULL)
        {
            free_stack(stack);
            return (NULL);
        }
        new_node->prev = stack->current;
        stack->current->next = new_node;
        stack->current = new_node;
        stack->stack_len++;
        new_node->index = stack->stack_len;
    }
    return (new_node);
}

t_node *create_stack(int len, int *arr,t_head *head)
{
    t_node  *tmp; 
	int i = 0;

    tmp = 0;
	while (arr)
	{
        if (i == len)
            break;
		tmp = fill_node(arr[i], head); 
        if (tmp == NULL)
		i++;
	}
    tmp = tmp->prev;
	tmp->next = NULL;
    head->bottom = tmp;
	return (tmp);
    //return the last node aka, always the tail
}


// t_head  *stack_init(t_head *stack)
// {
//
//
//     stack = (t_head *) ft_calloc(1, sizeof(t_head));
//     stack->name = 'a';
//     stack->name = 'b';
//     stack->stack_len = 0;
// }


// int main(int ac, char **av)
// {
//
//     t_head      *stack_a;
//     t_head      *stack_b;
// 	int	        *data;
//     int         arr[3] = {1, 4, 6};
//     int         sort;
//
//     data = 0;
// 	data = ft_parse(ac, av, data);
//
//
//     stack_b->stack_len = 0;
//
// 	stack_a->top = NULL;
// 	stack_b->top = NULL;
//
//     stack_a->bottom = create_stack(ac , data, stack_a);
//     stack_b->bottom = create_stack(4, arr, stack_b);
// 	free(data);
//
//
//     // rotate(stack_a);
//     
//     // ft_printf("node data ====>%d\n", stack_a->bottom->data);
//     // reverse_rotate(stack_a);
//     // pop_last(stack_a);
//     swap(stack_a);
//
//     sort = is_sort(stack_a);
//     ft_putnbr_fd(sort, 1);
//     // push(stack_a, stack_b, 'a');
//     // push(stack_a, stack_b, 'a');
//
//     print_stacks(stack_a, stack_b);
//     free_stack(stack_a);
//     free_stack(stack_b);
// 	
//
//
// 	
// 	return EXIT_SUCCESS;
// }
