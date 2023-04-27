#include "main.h"

int main(int argc, char **argv, char **envp)
{
	int input = 0;
	int is_interactive = isatty(STDIN_FILENO);
	char *exe = argv[0];
	char **environ = envp;

	(void)argc;
	while (input != -1)
	{		
		char *buffer = NULL;
		size_t size = 0;
		input = 0;
		

		if (is_interactive)
		{
			printf("$ ");
		}
		
		input = getline(&buffer, &size, stdin);
		if (input == -1)
		{
			free(buffer);
			break;
		}

		if (buffer[input - 1] == '\n')
		{
			buffer[input - 1] = '\0';
		}
		
		if (is_empty(buffer)== 0)
		{
			if (strcmp(buffer,"exit") == 0)
			{
				free(buffer);
				exit(0);
			}
			if (strcmp(buffer,"env") == 0)
			{
					for (; *environ; environ++)
					{
						printf("%s\n", *environ);
					}
			}
			else
			{
				parse(buffer, exe, environ);
			}
		}
		free(buffer);
	}
	
	return (0);
}


