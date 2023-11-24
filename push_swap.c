
// clone intra libft
#include "push_swap.h"

//function that will fill the stack a from argv
//


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



int main(int ac, char **av)
{
	t_node	*head;
	t_node	*top_sa;
	t_node	*top_sb;
	char	*buffer;
	int		*arr;
	size_t	buffer_len;

	buffer = buffer_args(ac, av);
	buffer_len = ft_strlen(buffer);
	printf("buffer len --> %zu\n", buffer_len);
	arr = arr_buffer(buffer, buffer_len);
	printf("buffer --> %s\n", buffer);
	free(buffer);



	top_sa = init_stack();
	top_sa = create_stack(buffer_len - count_white_space(buffer), top_sa, 1, arr);
	free(arr);
	freeLinkedList(top_sa);
	


	
	return EXIT_SUCCESS;
}
