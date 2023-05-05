#ifndef _MAIN_
#define _MAIN_
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <ctype.h>

typedef struct node_s
{
	char *str;
	struct node_s *next;
} node_t;
void free_nodes(node_t *head);
node_t *add_node_end(node_t **head, char *str);
int entry(char **list, char *exe, char **environp, node_t *head);
char *_getenvdup(char *name, char **envp);
int browse(char *path, char **list, node_t **first_node);
int is_empty(const char *str);
int parse(char *chaine, int input, char *exe, char **environ);
int exec(char **list, char **envp);

#endif
