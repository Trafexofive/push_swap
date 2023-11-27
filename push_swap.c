// fill the stack from the arr,

#include "push_swap.h"

//void	print_node(int index, node_t head)

t_node  *fill_node(t_node *head, int data)
{
    t_node  *new_node;
    t_node  *last_node;
    
    new_node = create_node(data);
    last_node = head->next;
    if (head == NULL)
        head->next = new_node;// last-node
    else
        last_node->next = new_node;
    head->next = new_node;



    return (new_node);
}

t_node	*create_stack(int len, int debug, int *arr)
{
    t_node  *head;
	int i = 0;

	head = NULL;
	while (i != len)
	{
		head = fill_node(head, arr[i]); 
		if (debug == 1)
			printf("%d\n", head->data);
		i++;
	}
	return (head);
}




int main(int ac, char **av)
{
	t_node	*head;
	// t_node	*top_sa;
	// t_node	*top_sb;
	int		*data;

    data = 0;
    head = create_stack(ac - 2, 0, data);
	data = ft_parse(ac, av, data);

    traverseLinkedList(head);
	free(data);
	freeLinkedList(head);
	


	
	return EXIT_SUCCESS;
}
