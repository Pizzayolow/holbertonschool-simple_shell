#include "main.h"
/**
 * browse - The function takes a path and a list of strings.
 * @path: A string containing multiple directories separated by colons.
 * @list: The parameter "list" is a pointer to a char pointer.
 * Return: The function `browse` returns a `char**`.
 * If the function successfully finds an executable file in one of.
 * the directories specified in the `path` argument, it returns.
 * the modified `list` argument with the path to the executable file.
 * If it does not find an executable file, it returns `NULL`.
 */
char **browse(char *path, char **list)
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
			return (NULL);
		}
		strcpy(prog, dir);
		strcat(prog, "/");
		strcat(prog, list[0]);
		ret = access(prog, X_OK);
		if (ret == 0)
		{
			list[0] = prog;
			free(prog);
			return (list);
		}
		free(prog);
		dir = strtok(NULL, ":");
	}
	return (NULL);
}
