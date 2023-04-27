#include "main.h"

int exec(char **list, char **environ)
{
	int status = 0;
	int error = 0;
	pid_t child;
	char **envp = environ;

	child = fork();
	
	if (child == -1)
	{
		perror("Error:");
		return (1);
	}
	if (child == 0)
	{
		
		error = execve(list[0], list, envp);
		if (error == -1)
		{
			fprintf(stderr, "%s\n", strerror(errno));
		}
		
	}
	else
	{
		wait(&status);
	}
	

	return (0);
}
