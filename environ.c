#include "main.h"

char **copy_environ(void)
{
    int i, count = 0;
    char **copy;

    while (environ[count])
    {
        count++;
    }

    copy = (char **)malloc((count + 1) * sizeof(char *));
    if (!copy)
    {
        return NULL;
    }

    for (i = 0; i < count; i++)
    {
        copy[i] = _strdup(environ[i]);
    }
    copy[count] = NULL;

    return copy;
}
