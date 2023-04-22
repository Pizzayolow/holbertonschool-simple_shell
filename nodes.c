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

	new_node->str = _strdup(str);
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
