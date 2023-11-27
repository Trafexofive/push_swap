

#include "push_swap.h"



t_node	*init_stack(void)
{
	t_node	*head;

	head = (t_node *)malloc(sizeof(t_node));
	if (!head)
		return (NULL);
	head->data = 0;
	head->next = NULL;
	return (head);
}

t_node	*link_node(t_node *node, int value)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	node->next = new_node;
	new_node->data = value;
	new_node->next = NULL;
	return(new_node);
}

//void	print_node(int index, node_t head)

t_node	*create_stack(int size, t_node *head, int debug, int *arr_args)
{
	int i = 0;
	t_node	*current_node;

	current_node = NULL;
	head = init_stack();
	if (head == NULL)
		return NULL;
	
	while (i < size)
	{
		current_node = link_node(head, arr_args[i]); 
		if (debug == 1)
			printf("%d\n", current_node->data);
		i++;
	}
	return (head);

}



int *ft_parse(int ac, char **av)
{
    int *data;

    data = 0;
    if (ac == 2)
        data = parse_string(ac, av, data);
    else if (ac > 2)
        data = parse_multi(ac, av, data);
    else
     return (NULL);

    put_intarr(data);
    return (data);
    return EXIT_SUCCESS;
}

int main(int ac, char **av)
{
	// t_node	*head;
	// t_node	*top_sa;
	// t_node	*top_sb;
	int		*arr;

	arr = ft_parse(ac, av);


	// top_sa = init_stack();
	// top_sa = create_stack(buffer_len - count_white_space(buffer), top_sa, 1, arr);
	free(arr);
	// freeLinkedList(top_sa);
	


	
	return EXIT_SUCCESS;
}
