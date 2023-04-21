#include "main.h"

int parse(char *chaine)
{
	
	
	char **list = NULL;
	int i = 0;
	int ret = 0;
	char *token = NULL;
	int nb_arg = 0;

	node_t *head = NULL;
	node_t *temp = NULL;
	

	char *program = _strdup(chaine);
	if (program == NULL)
	{
		return (-1);
	}

	token = strtok(program, " ");
	ret = access(program, X_OK);
	if (ret == -1)
	{
		return (0);
	}

	
	while (token)
	{
		add_node_end(&head, token);
		nb_arg++;
		token = strtok(NULL, " ");
	}	

	list = malloc(sizeof(char *) * nb_arg + 1);
	if (list == NULL)
	{
		free(program);
		free_nodes(head);
		return (-1);
	}

	
	temp = head;
	
	while (i < nb_arg)
	{
		list[i] = temp->str;
		temp = temp->next;
		i++;
	}
	i++;
	list[i] = NULL;
	temp = NULL;


	exec(list);
	
	
	free(list);
	free_nodes(head);

	free(program);
	return (0);
}
