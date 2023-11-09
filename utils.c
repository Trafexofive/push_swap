
#include <stdio.h>
#include <stdlib.h>
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
void freeLinkedList(t_node* head)
{
    t_node* current = head;
    while (current != NULL)
	{
        t_node* temp = current;
        current = current->next;
        free(temp);
    }
}

