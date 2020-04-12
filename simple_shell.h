#ifndef SIMPLE_SHELL
#define SIMPLE_SHELL

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <signal.h>
#include <stdbool.h>
#include <linux/limits.h>
#include <pwd.h>
#include <sys/types.h>
#include <sys/stat.h>

extern char **environ;
void print_prompt(void);
void han_func(int sig);
char **splt(char *raw_cmd, char *limit);
char *rec_env(char *buf);
void check_mn(int pid, char **cmd);
char *_getenv(char **tk);
char *_strdup(char *str);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
char *spltarr(char *nr, char *c, char **arr);
unsigned int _strcspn(char *s, char *pre);
char *_strchr(char *s, char b);
char *_strtok(char *s, char *deli);
int _strcmp(char *s1, char *s2);
#endif
