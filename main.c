/**
* main - Entry point of the program
* @argc: The number of arguments passed to the program
* @argv: An array of strings containing the arguments passed to the program
* @envp: An array of strings containing the program's environment variables
*
* Return: 0 on success, non-zero value on failure
*/
#include "main.h"

int main(int argc, char **argv, char **envp)
{
	int input = 0;
	char *exe = argv[0];
	char **environ = envp;

	(void)argc;
	while (input != -1)
	{
		char *buffer = NULL;
		size_t size = 0;

		input = 0;

		if (isatty(STDIN_FILENO))
		{
			printf("$ ");
		}

		input = getline(&buffer, &size, stdin);
		if (input && is_empty(buffer) == 0)
		{
			parse(buffer, input, exe, environ);
		}
		free(buffer);
	}
	return (0);
}
