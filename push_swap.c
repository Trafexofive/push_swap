// fill the stack from the arr,

#include "push_swap.h"
#include "printf/ft_printf.h"

//void	print_node(int index, node_t head)


t_node  *fill_node(int data, t_head *head)
{
    t_node  *new_node;
    
    if (head->top == NULL)
    {
        new_node = create_node(data);
        head->top = new_node;
        head->current = new_node;
    }
    else
    {
        new_node = create_node(data);
        new_node->prev = head->current;
        head->current->next = new_node;
        head->current = new_node;
    }
    return (new_node);
}

t_node *create_stack(int len, int *arr,t_head *head)
{
    t_node  *first_node; //tmp node
	int i = 0;

    first_node = 0;
	while (arr)
	{
        if (i == len)
            break;
		first_node = fill_node(arr[i], head); 
		i++;
	}
	first_node->next = NULL;
	return (first_node);
    //return the last node aka, always the tail
}




int main(int ac, char **av)
{

    t_head      *stack_a;
    t_head      *stack_b;
	int	        *data;
    int         arr[3] = {1, 4, 6};

    data = 0;
	data = ft_parse(ac, av, data);
    stack_a = (t_head *) ft_calloc(1, sizeof(t_head));
    stack_b = (t_head *) ft_calloc(1, sizeof(t_head));

	stack_a->top = NULL;
	stack_b->top = NULL;

    stack_a->bottom = create_stack(ac , data, stack_a);
    stack_b->bottom = create_stack(4, arr, stack_b);
    // pop_last(stack_b);
    // pop_last(stack_a);
    // swap(stack_a);

    push(stack_a, stack_b, 'a');
    push(stack_a, stack_b, 'a');

    print_stacks(stack_a, stack_b);
	free(data);
	


	
	return EXIT_SUCCESS;
}
