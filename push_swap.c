
#include "push_swap.h"

//function that will fill the stack a from argv

node_t	*link_node(node_t *node, int value)
{
	int i =0;
	node_t	new_node;

	new_node = (node_t)malloc(sizeof(struct node_t));
	node->next = &new_node;
	new_node->data = value;
	new_node->next = NULL;
	return (node);
}

void	print_node(int index, node_t head)

//node	*create_stack(int size)
void	ft_errors(int error)
{
	printf("%s", "error\n");
}

//int	*ft_parse(int argc, char **argv)


int main(int ac, char **av)
{
	node_t	head;

	head = malloc(sizeof(node_t));
	head->data = 30;
	head->next = NULL;
	link_node(head, 2);
	printf("%d\n", head->data);
	free (&head);



	
	return EXIT_SUCCESS;
}
