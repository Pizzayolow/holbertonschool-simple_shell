#Projet SIMPLE SHELL d'Holberton School

Ce projet consite à créer un Shell en utilisant le language C.

##Prérequis:

Clone repository using HTTPS :

https://github.com/Pizzayolow/holbertonschool-simple_shell.git

##Pour compiler et exécuter ce programme, vous devez disposer des éléments suivants : 

- Un compilateur : (GCC, ...)
- La bibliothèque <string.h>

##Compilation:

Installed gcc (GNU Compiler Collection) version 9.4.0 or newer

gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

##Pour executer le programme, tapez simplement :

./hsh

##Comme pour le Shell original vous pouvez spécifier des arguments en ligne de commande pour modifier le comportement du programme.

par ex : "ls -la"

##Pour effectuer ce projet nous avons utilisé les fonctions et appels systèmes suivants : 

all functions from strings.h
access (man 2 access)
chdir (man 2 chdir)
close (man 2 close)
closedir (man 3 closedir)
execve (man 2 execve)
exit (man 3 exit)
_exit (man 2 _exit)
fflush (man 3 fflush)
fork (man 2 fork)
free (man 3 free)
getcwd (man 3 getcwd)
getline (man 3 getline)
getpid (man 2 getpid)
isatty (man 3 isatty)
kill (man 2 kill)
malloc (man 3 malloc)
open (man 2 open)
opendir (man 3 opendir)
perror (man 3 perror)
printf (man 3 printf)
fprintf (man 3 fprintf)
vfprintf (man 3 vfprintf)
sprintf (man 3 sprintf)
putchar (man 3 putchar)
read (man 2 read)
readdir (man 3 readdir)
signal (man 2 signal)
stat (__xstat) (man 2 stat)
lstat (__lxstat) (man 2 lstat)
fstat (__fxstat) (man 2 fstat)
strtok (man 3 strtok)
wait (man 2 wait)
waitpid (man 2 waitpid)
wait3 (man 2 wait3)
wait4 (man 2 wait4)
write (man 2 write)

##Vous pouvez également Valgrind :

root@bd6c50b5f513:/holbertonschool-simple_shell# valgrind ./hsh
==2705== Memcheck, a memory error detector
==2705== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==2705== Using Valgrind-3.15.0 and LibVEX; rerun with -h for copyright info
==2705== Command: ./hsh
==2705==
$ ls -la
total 4808
drwxr-xr-x 4 root root     212 Apr 26 10:53 .
drwxr-xr-x 1 root root    4096 Apr 19 03:02 ..
-rw-r--r-- 1 root root     358 Apr 26 10:17 exec.c
drwxr-xr-x 8 root root     220 Apr 26 10:53 .git
-rwxr-xr-x 1 root root   29152 Apr 26 10:52 hsh
-rw-r--r-- 1 root root     548 Apr 26 10:00 main.c
-rw-r--r-- 1 root root     509 Apr 26 07:55 main.h
-rw-r--r-- 1 root root     638 Apr 26 09:16 nodes.c
-rw-r--r-- 1 root root    1831 Apr 26 10:52 parse.c
-rw-r--r-- 1 root root    1452 Apr 26 04:27 path.txt
-rw-r--r-- 1 root root     141 Apr 19 03:06 README.md
-rw-r--r-- 1 root root     452 Apr 26 10:53 tools.c

$ ==2705==
==2705== HEAP SUMMARY:
==2705==     in use at exit: 0 bytes in 0 blocks
==2705==   total heap usage: 14 allocs, 14 frees, 2,474 bytes allocated
==2705==
==2705== All heap blocks were freed -- no leaks are possible
==2705==
==2705== For lists of detected and suppressed errors, rerun with: -s
==2705== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

Fonctionalités : 

Notre programme effectue les taches basiques du Shell, comme l'executable 'ls'.

Ce projet a été réalisé par Simon Descombes et Valentin Ralliard.