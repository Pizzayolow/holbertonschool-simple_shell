#include "main.h"


int main(void)
{
	int input = 0;

	while (input != -1)
	{
		char *buffer = NULL;
		size_t size = 0;
		input = 0;

		fprintf(stdout,"$ ");
		input = getline(&buffer, &size, stdin);
		
		if (buffer[input - 1] == '\n')
		{
			buffer[input - 1] = '\0';
		}
		parse(buffer);
		free(buffer);
	}
	
	return (0);
}
