# Holberton School's Simple Shell Project

This project consists in creating a Shell using the C language.

### Requirements:

Clone repository using HTTPS :

https://github.com/Pizzayolow/holbertonschool-simple_shell.git

### To run this program, you need the following libraries:
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

## To run the program, simply type :

./hsh

## As with the original Shell you can specify command line arguments to change the behavior of the program.

par ex : "ls -la"

### To carry out this project we used the following functions and system calls:
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
````
root@bd6c50b5f513:/holbertonschool-simple_shell# valgrind ./hsh
==2707== Memcheck, a memory error detector
==2707== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==2707== Using Valgrind-3.15.0 and LibVEX; rerun with -h for copyright info
==2707== Command: ./hsh
==2707==
$ /bin/ls
exec.c  hsh  main.c  main.h  nodes.c  parse.c  path.txt  README.md  test  tools.c  vgcore.161  vgcore.162
$ ==2707==
==2707== HEAP SUMMARY:
==2707==     in use at exit: 0 bytes in 0 blocks
==2707==   total heap usage: 7 allocs, 7 frees, 2,328 bytes allocated
==2707==
==2707== All heap blocks were freed -- no leaks are possible
==2707==
==2707== For lists of detected and suppressed errors, rerun with: -s
==2707== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
````
## Features :

Our program performs basic Shell tasks, like the 'ls' executable.

### Flowchart
![Flowchart](https://lh3.googleusercontent.com/u/2/drive-viewer/AFGJ81r-WOY2hyoi7ySgKPlvb2aPYMidJtPL0SQLgMpcGqP_81Ky2azakyPM8ElTxitNnSyjO5NKP_QlA_3gcRDTni6QjjmM9A=w3440-h1279)

### Usage of the man page , type this command :
groff -man -Tutf8 man_1_simple_shell.1 | less

Project by [Valentin Ralliard](https://github.com/Pizzayolow) and [Simon Descombes](https://github.com/SimonDesc)
