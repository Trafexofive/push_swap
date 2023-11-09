
#include "includes/push_swap.h"

void	insert_node(node *head, int val)
{
	node *new_node = malloc(sizeof(node));
	new_node->data = val;
	new_node->next =
	
}
void print_list_forward(struct node *head) {
  while (head != NULL) {
    printf("%d ", head->data);
    head = head->next;
  }
  printf("\n");
}


void print_list_backward(struct node *head) {
  struct node *current = head;
  while (current->next != NULL) {
    current = current->next;
  }

  while (current != NULL) {
    printf("%d ", current->data);
    current = current->prev;
  }
  printf("\n");
}


