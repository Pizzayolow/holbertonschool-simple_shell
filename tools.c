#include "main.h"

/**
 * is_empty - Checks if a string is empty or contains only whitespace
 * @str: The string to check
 *
 * Return: 1 if the string is empty or contains only whitespace, 0 otherwise
 */
int is_empty(const char *str)
{
	while (*str != '\0')
	{
		if (!isspace(*str))
			return (0);
		str++;
	}
	return (1);
}

/**
 * _getenvdup - Gets the value of an environment variable
 * @name: The name of the environment variable
 * @environp: An array of strings containing the environment variables
 *
 * Return: A duplicate pointer to the value of the environment variable,
 * or NULL if the variable is not found
 */
char *_getenvdup(char *name, char **environp)
{
	int i = 0;
	size_t size_len = strlen(name);
	char *path_env = NULL;
	char *path = NULL;

	if (name == NULL)
		return (NULL);

	for (i = 0; environp[i] != NULL; i++)
	{
		if (strncmp(name, environp[i], size_len) == 0)
		{
			if (strlen(environp[i]) == 0)
			{
				return (NULL);
			}
			path_env = environp[i] + size_len + 1;
			path = strdup(path_env);
			if (path == NULL)
			{
				free(path);
				return (NULL);
			}
			return (path);
		}
	}
	return (NULL);
}
