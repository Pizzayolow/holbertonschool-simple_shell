#include "main.h"

char *shortcut(char *token)
{

    char *s1 = NULL;
    char *s = NULL;
    char *path = _getenv("PATH");
    int ret_path = 0;

    s1 = _strdup(strtok(path, ":"));
    while (s1 != NULL)
    {
        if (s1 == NULL) 
        {
            free(path);
            return (NULL);
        }

        s = malloc((_strlen(s1) + 1 + _strlen(token)) * sizeof(char));
        if (s == NULL)
        {
            free(path);
            free(s1);
            return (NULL);
        }

        s = _strcat(s, s1);
        s = _strcat(s, "/");
        s = _strcat(s, token);

	

	ret_path = access(s, X_OK);
        if (ret_path == 0)
        {
	    return (s);
        }
        path = strtok(NULL, ":");
        s1 = strtok(NULL, ":");
    }
    printf("free party\n");
    free(s);
    free(s1);
    free(path);
    return (0);
}
