#include "main.h"

char *_getenv(char *name) {
  int i = 0;
  size_t size_len = strlen(name);

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
