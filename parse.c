/**
* parse - Parses a command and executes it
* @input: input given
* @chaine: The command string to parse
* @exe: The name of the executable file
* @environp: An array of strings containing the environment variables
*
* Return: 0 on success, -1 on failure
*/
#include "main.h"

int parse(char *chaine, int input, char *exe, char **environp)
{
	char **list = NULL;
	int i = 0, nb_arg = 0;
	char *token = NULL;
	node_t *head = NULL, *temp = NULL;

	(chaine[input - 1] == '\n') ? (chaine[input - 1] = '\0') : 0;
	token = strtok(chaine, " ");
	for (; token; nb_arg++)
	{
		add_node_end(&head, token);
		token = strtok(NULL, " ");
	}
	list = malloc(sizeof(char *) * (nb_arg + 1));
	if (list == NULL)
	{
		free_nodes(head);
		return (-1);
	}
	temp = head;
	for (i = 0; i < nb_arg; i++)
	{
		list[i] = temp->str;
		temp = temp->next;
	}
	list[i] = NULL;
	entry(list, exe, environp, head);
	free_nodes(head);
	return (0);
}
