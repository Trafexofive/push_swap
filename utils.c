
#include "push_swap.h"

// Define a structure for a node in the linked list

// Function to create a new node with the given data
t_node* createNode(int data)
{
    t_node* newNode = (t_node*)malloc(sizeof(t_node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at the end of the linked list
void insertAtEnd(t_node** head, int data)
{
    t_node* newNode = createNode(data);
    if (*head == NULL)
        *head = newNode;
	else
	{
        t_node* current = *head;
        while (current->next != NULL)
            current = current->next;
        current->next = newNode;
    }
}

// Function to traverse and print the linked list
void traverseLinkedList(t_node* head)
{
    t_node* current = head;
    while (current != NULL)	{
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Function to free the memory used by the linked list
void free_stack(t_node* head)
{
    t_node* current = head;
    while (current != NULL)
	{
        t_node* temp = current;
        current = current->next;
        free(temp);
    }
}



size_t	ft_strlen_int(int *c)
{
	size_t	i;

	i = 0;
	while (c[i])
		i++;
	return (i);
}

int put_intarr(int *tab)
{
    int i;

    i = 0;
    if (!tab)
        return (0);
    while (tab[i++])
    {
        if (!tab[i])
            break;
        ft_printf("Index = %d | %d\n", i, tab[i]);

    }
    return (i);
}

int ft_puttab(char **tab)
{
    int i;

    i = -1;
    if (!tab)
        return (0);
    while (tab[++i])
        ft_printf("Index = %d | %s\n", i, tab[i]);
    return (i);
}

//function to auto_print sizeof;
int *strdup_int(int *arr)
{
    int i;
    int *dupe;

    i = -1;
    if (!arr)
        return (NULL);
    dupe = (int *)malloc(sizeof(arr)); 
    if (!dupe)
        return (NULL);
    while (arr[++i])
        dupe[i] = arr[i];
    return (dupe);
}

bool    is_duped(int *arr)
{
    int i;
    int j;
    int *tmp_str;

    i = 0;
    j = 0;
    tmp_str = strdup_int(arr);
    while (arr[i] && tmp_str)
    {
        while (tmp_str[j])
        {
            if (tmp_str[j] == arr[i])
                return (0);
            j++;
        }
        j = 0;
        i++;
    }
    return (0);
}
