#include "main.h"

/**
* is_empty - Checks if a string is empty or contains only whitespace
* @str: The string to check
*
* Return: 1 if the string is empty or contains only whitespace, 0 otherwise
*/
int is_empty(const char *str) {
    while (*str != '\0') {
        if (!isspace(*str))
            return 0;
        str++;
    }
    return 1;
}

/**
* _getenv - Gets the value of an environment variable
* @name: The name of the environment variable
* @envp: An array of strings containing the environment variables
*
* Return: A pointer to the value of the environment variable, or NULL if the
* variable is not found
*/
char *_getenv(char *name, char **envp) {
  int i = 0;
  size_t size_len = strlen(name);
  char **environ = envp;

  if (name == NULL)
  {
	  return (NULL);
  }

  for (i = 0; environ[i] != NULL; i++) {
    if (strncmp(name, environ[i], size_len) == 0) {
      return environ[i] + size_len + 1;
    }
  }
  return (NULL);
}
