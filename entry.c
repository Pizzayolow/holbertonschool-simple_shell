#include "main.h"
/**
 * entry - The function checks if a given
 * executable file exists and is executable
 * and if not, searches for it
 * in the directories listed in the PATH environment variable and executes it.
 * @list: A pointer to an array of strings, where the first element is
 * the command to be executed and the rest are its arguments.
 * @exe: The name of the executable file being executed.
 * @environp: environp is a pointer to an array of strings
 * @head: the first node
 * Return: an integer value, which could be either 0.
 * or 127 depending on the execution of the code.
 */
int entry(char **list, char *exe, char **environp, node_t *head)
{
	int ret = 0;
	char *path = NULL;

	ret = access(list[0], X_OK);
	if (ret != 0)
	{
		path = _getenvdup("PATH=", environp);
		printf("path = [%s]\n", path);
		if (path == NULL || browse(path, list, &head) == 0)
		{
			fprintf(stderr, "%s: 1: %s: not found\n", exe, list[0]);
			free(path);
			free(list);
			free_nodes(head);
			exit (127);
		}
		free(path);
	}
	exec(list, environp);
	free(list);
	return (0);
}
