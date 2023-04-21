#include "main.h"

char *_strdup(char *str)
{
	char *ar;
	int i;
	int size = 0;

	if (str == NULL)
	{
		return (NULL);
	}
	for (i = 0; str[i] != '\0'; i++)
	{
		size++;
	}
	ar = malloc(size * sizeof(char) + 1);
	if (ar == NULL)
	{
		return (NULL);
	}
	for (i = 0; i < size; i++)
	{
		ar[i] = str[i];
	}
	ar[size] = '\0';

	return (ar);
}
