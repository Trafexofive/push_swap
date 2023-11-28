// fill the stack from the arr,

#include "push_swap.h"

//void	print_node(int index, node_t head)


t_node  *fill_node(t_node *prev_node, int data, t_node *head)
{
    t_node  *new_node;
    
    if (prev_node == NULL)
        return (NULL);
    if (head == NULL)
        head = prev_node; // aka the adress of the first node
    else
    {
        new_node = create_node(data);
        prev_node->next = new_node;
        new_node->prev = prev_node;
    }
    return (new_node);
}

t_node	*create_stack(int len, int *arr,t_node *head)
{
    t_node  *cursor;
    t_node  *first_node;
	int i = 1;

    first_node = create_node(arr[0]);
	while (i != len)
	{
		cursor = fill_node(first_node, arr[i], head); 
		i++;
	}
	return (head);
    //return the last node aka, always the tail
}




int main(int ac, char **av)
{
	// t_node	*top_sa;
	// t_node	*top_sb;

    static t_node  *head;
	int		*data;

    data = 0;
	head = NULL;
	data = ft_parse(ac, av, data);
    head = create_stack(ac - 2, data, head);

    traverseLinkedList(head);
	free(data);
	


	
	return EXIT_SUCCESS;
}
