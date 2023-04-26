#include "main.h"


int main(int argc, char **argv)
{
	int input = 0;
	int is_interactive = isatty(STDIN_FILENO);
	(void)argc;
	char *exe = argv[0];

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
		
		parse(buffer, exe);
		free(buffer);
	}
	
	return (0);
}
