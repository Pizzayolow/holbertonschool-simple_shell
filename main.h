#ifndef _MAIN_
#define _MAIN_
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <fcntl.h>

extern char **environ;


typedef struct node_s
{
	char *str;
	struct node_s *next;
} node_t;
void free_nodes(node_t *head);
node_t *add_node_end(node_t **head, char *str);


int parse(char *argv);
char *_strdup(char *str);
int exec(char **list);
int _strcmp(char *s1, char *s2);
char *_strcat(char *dest, char *src);
int _strlen(char *s);
char *_getenv(char *name);
void *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *shortcut(char *token);
int _strncmp(const char *s1, const char *s2, size_t size);

#endif
