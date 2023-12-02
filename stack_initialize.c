
#include "push_swap.h"


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
		(*stack)->bottom = new_node;
		sort_index(*stack, new_node);
	}
}
t_node *create_stack(int len, int *arr,t_head *stack)
{
	int i = 0;
	while (arr && i < len)
	{
		fill_node(arr[i], &stack);
		stack->stack_len++;
		i++;
	}
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
