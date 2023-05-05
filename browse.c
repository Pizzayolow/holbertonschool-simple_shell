#include "main.h"
/**
 * browse - The function takes a path and a list of strings.
 * @path: A string containing multiple directories separated by colons.
 * @list: The parameter "list" is a pointer to a char pointer.
 * @head: the first node
 * Return: The function `browse` returns a `char**`.
 * If the function successfully finds an executable file in one of.
 * the directories specified in the `path` argument, it returns.
 * the modified `list` argument with the path to the executable file.
 * If it does not find an executable file, it returns `NULL`.
 */
int browse(char *path, char **list, node_t **first_node)
{
	char *dir = NULL;
	char *prog = NULL;
	int ret = 0;

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
			free(list[0]);
			list[0] = NULL;
			list[0] = malloc((strlen(prog) + 1) * sizeof(char));
			if (list[0] == NULL)
			{
				free(prog);
				return (-1);
			}
			strcpy(list[0], prog);
			list[0][strlen(prog)] = '\0';
			(*first_node)->str = list[0];
			free(prog);
			return (1);
		}
		free(prog);
		dir = strtok(NULL, ":");
	}
	return (0);
}
