/**
* add_node_end - Adds a new node at the end of a linked list
* @head: A pointer to a pointer to the head of the linked list
* @str: The string to be stored in the new node
*
* Return: A pointer to the head of the linked list
*/
#include "main.h"
node_t *add_node_end(node_t **head, char *str)
{
	node_t *last_node = *head;
	node_t *new_node = NULL;

	new_node = malloc(sizeof(node_t));
	if (new_node == NULL)
	{
		return (NULL);
	}

	new_node->str = strdup(str);
	new_node->next = NULL;

	if (*head == NULL)
	{
		*head = new_node;
		return (*head);
	}

	while (last_node->next != NULL)
	{
		last_node = last_node->next;
	}
	last_node->next = new_node;
	

	return (*head);
}

/**
* free_nodes - Frees memory allocated for each node in a linked list
* @head: A pointer to the head of the linked list
*/
void free_nodes(node_t *head)
{
    node_t *temp = NULL;

    while (head != NULL) 
    {
        temp = head;
        head = head->next;
        free(temp->str);
        free(temp);
    }
}
