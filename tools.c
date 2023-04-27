#include "main.h"

int is_empty(const char *str) {
    while (*str != '\0') {
        if (!isspace(*str))
            return 0;
        str++;
    }
    return 1;
}

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
