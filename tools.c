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


int _strcmp(char *s1, char *s2)
{
	int i = 0;
	int c1 = 0;
	int c2 = 0;
	int cmax = 0;
	int result = 0;

	while (s1[c1] != '\0')
	{
		c1++;
	}
	while (s2[c2] != '\0')
	{
		c2++;
	}
	cmax = (c1 > c2) ? c1 : c2;

	while (i <= cmax)
	{
		while (s1[i] == s2[i])
		{
			if (s1[i] == '\0' && s2[i] == '\0')
			{
				return (0);
			}
			else
			{
				i++;
			}
		}
		if (s1[i] != s2[i])
		{
			result = s1[i] - s2[i];
			return (result);
		}
		i++;
	}
	return (result);
}

char *_strcat(char *dest, char *src)
{
	int i = 0;
	int j = 0;

	while (dest[i] != '\0')
	{
		i++;
	}

	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	 dest[i + 1]  = '\0';

	return (dest);
}

int _strlen(char *s)
{
	int i = 0;

	while (s[i] != '\0')
	{
		i++;
	}

	return (i);
}


void *_strcpy(char *dest, char *src)
{
	int i = 0;

	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}




int _strncmp(const char *s1, const char *s2, size_t size)
{
  size_t i = 0;

  while (i < size) {
    if (s1[i] != s2[i] || s1[i] == '\0') {
      return (s1[i] - s2[i]);
    }
    i++;
  }
  return 0;
}