
#include "push_swap.h"

//function that will fill the stack a from argv
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

t_node	*create_stack(int size, t_node *head, int *elements, int debug)
{
	int i = 0;
	t_node	*current_node;

	current_node = NULL;
	head = init_stack();
	if (head == NULL)
		return NULL;
	
	while (i < size)
	{
		current_node = link_node(head, elements[i]);
		if (debug == 1)
			printf("%d\n", current_node->data);
		current_node = current_node->next;
		i++;
	}
	return (head);

}
//int	*ft_parse(int argc, char **argv)

void	fill_t(int *arr)
{
	int i = 0;

	while (arr[i])
	{
		arr[i] = i;
		i++;
	}
}

int main(int ac, char **av)
{
	t_node	*head;
	int elements[10];

	(void)ac;
	(void)av;

	fill_t(elements);
	head = init_stack();
	head = create_stack(10, head, elements, 1);
	freeLinkedList(head);
	


	
	return EXIT_SUCCESS;
}
