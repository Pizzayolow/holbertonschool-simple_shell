#include "main.h"


int main(void)
{
	int input = 0;
	int is_interactive = isatty(STDIN_FILENO);

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
			break;
		}


		if (buffer[input - 1] == '\n')
		{
			buffer[input - 1] = '\0';
		}
		parse(buffer);
		free(buffer);
	}
	
	return (0);
}
