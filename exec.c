#include "main.h"

int exec(char **list)
{
	int i = 0;
	int status = 0;
	int error = 0;
	pid_t child;
	char **env_copy;

	env_copy = copy_environ();
	if (!env_copy)
	{
		perror("Error copying environment");
		return 1;
	}

	child = fork();
	if (child == -1)
	{
		perror("Error:");
		return (1);
	}
	if (child == 0)
	{
		error = execve(list[0], list, env_copy);
		if (error == -1)
		{
			fprintf(stderr, "exceve = %s\n", strerror(errno));
		}
	}
	else
	{
		wait(&status);
	}

	for (i = 0; env_copy[i]; i++)
	{
		free(env_copy[i]);
	}
	free(env_copy);

	return (0);
}
