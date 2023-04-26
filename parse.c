#include "main.h"

int parse(char *chaine, char *exe)
{		
	char **list = NULL;
	int i = 0;
	char *token = NULL;
	int nb_arg = 0;

	int ret = 0;
	char *path = NULL;
	char *path_env = NULL;
	char *dir = NULL;
	char *prog = NULL;

	node_t *head = NULL;
	node_t *temp = NULL;

	token = strtok(chaine, " ");
	while (token)
	{
		add_node_end(&head, token);
		nb_arg++;
		token = strtok(NULL, " ");
	}	

	list = malloc(sizeof(char *) * (nb_arg + 1));
	if (list == NULL)
	{
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
	list[i] = NULL;

	ret = access(list[0], X_OK);
	if (ret != 0)
	{
		path_env = _getenv("PATH");
		if (path_env == NULL)
		{
			fprintf(stderr, "%s 1: ls: not found\n", exe);
			return (-1);
		}

		path = strdup(path_env);
		if (path == NULL)
		{
			return (-1);
		}

		

		dir = strtok(path, ":");
		while (dir != NULL)
		{
			prog = malloc((strlen(dir) + strlen(list[0]) + 2) * sizeof(char));
			if (prog == NULL)
			{
				free(path);
				return (-1);
			}

				strcpy(prog, dir);
				strcat(prog, "/");
				strcat(prog, list[0]);
				ret = access(prog, X_OK);
				if (ret == 0)
				{
					list[0] = prog;
					free(path);
					break;
				}
				/* printf("[DEBUG] dir = %s | prog = %s \n", dir, prog); */
				free(prog);
				dir = strtok(NULL, ":");
		}
		
	}

	exec(list);
	if (prog != NULL)
	{
		free(prog);
	}
	free(list);
	free_nodes(head);
	

	return (0);
}
