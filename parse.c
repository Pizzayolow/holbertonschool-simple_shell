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
	int flag = 0;
	char *path1 = NULL;

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
		if (path_env == NULL || is_empty(path_env) != 0)
		{
			path1 = _getenv("PATH1");
			if (path1 != NULL)
			{
				path_env = path1;
			}
			else
			{
				free(chaine);
				fprintf(stderr, "%s: 1: %s: not found\n", exe, list[0]);
				free(list);
				free_nodes(head);
				exit(127);
			}
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
					flag = 1;
					break;
				}
				free(prog);
				dir = strtok(NULL, ":");
		}
		free(path);
		if (flag == 0)
		{
			fprintf(stderr, "%s: 1: %s: not found\n", exe, list[0]);
			free(chaine);
			free(list);
			free_nodes(head);
			exit(127);
		}
	}
	else
	{
		flag = 1;
	}


	if (flag == 1)
	{
		exec(list);
		free(prog);
	}
	
	free(list);
	free_nodes(head);
	

	return (0);
}
