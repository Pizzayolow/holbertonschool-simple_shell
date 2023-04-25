#include "main.h"

int parse(char *chaine)
{		
	char **list = NULL;
	int i = 0;
	char *token = NULL;
	int nb_arg = 0;

	int ret = 0;
	char *path = NULL;
	char *s1 = NULL;
	char *path_tmp = NULL;
	char *new_prog = NULL;
	

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
	list[i] = NULL; // c'est pour EXEC

	ret = access(list[0], X_OK);
	if (ret != 0)
	{
		
		path_tmp = _getenv("PATH");
		printf("path tmp = [%s]\n", path_tmp);
		path = _strdup(path_tmp);
		printf("path = [%s]\n", path);
		s1 = strtok(path, ":");
		printf("apres strtok, que vaut path = %s \n", path);
		while (path != NULL)
		{
			new_prog = malloc((_strlen(s1) + 1 + _strlen(list[0])) * sizeof(char));
			if (new_prog == NULL)
			{
				return (-1);
			}
			new_prog = _strcat(new_prog, s1);
			new_prog = _strcat(new_prog, "/");
			new_prog = _strcat(new_prog, list[0]);
			printf("new_prog = %s\n", new_prog);
			ret = access(new_prog, X_OK);
			if (ret == 0)
			{
				print("YOUPI : %s\n", new_prog);
				list[0] = new_prog;
				break;
			}
			path = strtok(NULL, ":");
			s1 = strtok(NULL, ":");
		}
		//free(path);
	}

	printf("list[0] = %s \n", list[0]);
	printf("list[1] = %s \n", list[1]);

	exec(list);

	
	//printf("avant free s : %p, valeur : [%s]\n", s, s);
	//free(s);
	free(list);
	free_nodes(head);
	

	return (0);
}
