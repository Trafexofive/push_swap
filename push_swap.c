
#include "push_swap.h"

//function that will fill the stack a from argv
Node	*init_stack(void)
{
	Node	*head;

	head = (Node *)malloc(sizeof(Node));
	head->next = NULL;
	head->data = NULL;
	return (head);
}

Node	*link_node(Node *node, int value)
{
	node	*new_node;

	new_node = (Node *)malloc(sizeof(Node));
	node->next = new_node;
	new_node->data = value;
	new_node->next = NULL;
	return(new_node);
}

//void	print_node(int index, node_t head)

//node	*create_stack(int size)
void	ft_errors(int error)
{
	printf("%s", "error\n");
}

//int	*ft_parse(int argc, char **argv)


int main(int ac, char **av)
{
	int	i;
	Node	*head;

	i = 0;
	head = (Node *)malloc(sizeof(Node));
	if (!head)
		return (1);
	head->data = NULL;
	head->next = NULL;

	link_node(head, NULL);
	while (i < 10)
	{
		link_node(head->next, i);
		i++;
	}
	free (head);



	
	return EXIT_SUCCESS;
}
