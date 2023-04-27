# Project SIMPLE SHELL d'Holberton School

Ce projet consiste à créer un Shell en utilisant le language C.

### Prérequis:

Clone repository using HTTPS :

https://github.com/Pizzayolow/holbertonschool-simple_shell.git

### Pour exécuter ce programme, vous devez disposer des bibliothèques suivantes :
```
- <stdio.h>
- <stdlib.h>
- <unistd.h>
- <sys/wait.h>
- <errno.h>
- <string.h>
- <sys/types.h>
- <ctype.h>
```
### Compilation:

For compile this program you need a compiler like GCC.

Installed gcc (GNU Compiler Collection) version 9.4.0 or newer

#### The command line for compile:

gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

## Pour executer le programme, tapez simplement :

./hsh

## Comme pour le Shell original vous pouvez spécifier des arguments en ligne de commande pour modifier le comportement du programme.

par ex : "ls -la"

### Pour effectuer ce projet nous avons utilisé les fonctions et appels systèmes suivants :
```
-   all functions from strings.h
-   `access`  (man 2 access)
-   `chdir`  (man 2 chdir)
-   `close`  (man 2 close)
-   `closedir`  (man 3 closedir)
-   `execve`  (man 2 execve)
-   `exit`  (man 3 exit)
-   `_exit`  (man 2 _exit)
-   `fflush`  (man 3 fflush)
-   `fork`  (man 2 fork)
-   `free`  (man 3 free)
-   `getcwd`  (man 3 getcwd)
-   `getline`  (man 3 getline)
-   `getpid`  (man 2 getpid)
-   `isatty`  (man 3 isatty)
-   `kill`  (man 2 kill)
-   `malloc`  (man 3 malloc)
-   `open`  (man 2 open)
-   `opendir`  (man 3 opendir)
-   `perror`  (man 3 perror)
-   `printf`  (man 3 printf)
-   `fprintf`  (man 3 fprintf)
-   `vfprintf`  (man 3 vfprintf)
-   `sprintf`  (man 3 sprintf)
-   `putchar`  (man 3 putchar)
-   `read`  (man 2 read)
-   `readdir`  (man 3 readdir)
-   `signal`  (man 2 signal)
-   `stat`  (__xstat) (man 2 stat)
-   `lstat`  (__lxstat) (man 2 lstat)
-   `fstat`  (__fxstat) (man 2 fstat)
-   `strtok`  (man 3 strtok)
-   `wait`  (man 2 wait)
-   `waitpid`  (man 2 waitpid)
-   `wait3`  (man 2 wait3)
-   `wait4`  (man 2 wait4)
-   `write`  (man 2 write)

---


````
### Valgrind
    root@id:/holbertonschool-simple_shell# valgrind ./hsh
    ==19647== Memcheck, a memory error detector
    ==19647== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
    ==19647== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
    ==19647== Command: ./hsh
    ==19647==
    /bin/ls
	README.md  _getline.c  _strtok.c          hsh     path_values.c   
	simple_shell.h
	_free.c    _strfunc.c  execute_command.c  main.c  search_path1.c
    ==19647==
    ==19647== HEAP SUMMARY:
    ==19647== in use at exit: 0 bytes in 0 blocks
    ==19647== total heap usage: 142 allocs, 142 frees, 18,486 bytes allocated
    ==19647==
    ==19647== All heap blocks were freed -- no leaks are possible
    ==19647==
    ==19647== For lists of detected and suppressed errors, rerun with: -s
    ==19647== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
    root@id:/holbertonschool-simple_shell#
    
---
## Fonctionalités :

Notre programme effectue les taches basiques du Shell, comme l'exécutable 'ls'.

### Flowchart
<iframe src="https://drive.google.com/file/d/156306HsiKn8xKdQN5oSsalINcAQZTZ5q/preview" width="900" height="800" allow="autoplay"></iframe>

Project by [Valentin Ralliard](https://github.com/Pizzayolow) and [Simon Descombes](https://github.com/SimonDesc)