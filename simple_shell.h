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
#define SHELL "#cisfun$ "

/**
 * struct split_cmd - split_cmd
 * @all_cmd_buf: all_cmd_buf
 * @number_cmd: a number_cmd
 * @flag: flag
 */
typedef struct split_cmd
{
	char **all_cmd_buf;
	int number_cmd;
	int flag;
} split_cmd;

extern char **environ;
void print_prompt(void);
void han_func(int sig);
int _putchar(char c);
char **splt(char *raw_cmd, char *limit);
char *splt_env(char *buf);
char *_getenv(char **tk);
char *_strdup(char *str);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
void pn(int count);
int _strlen(char *s);
char *spltarr(char *nr, char *c, char **arr);
void check_mn(int pid, char **cmd, char **av, int f);
unsigned int _strcspn(char *s, char *pre);
char *_strchr(char *s, char b);
char *_strtok(char *s, char *deli);
int _strcmp(char *s1, char *s2);
int execute_cmd(char *buf, char **argv, int f);
split_cmd check_split(char *buf);
int check_built(char *src);
void execd(char **cmdbuilt);
char *_gethome(char **tk);
char *_getoldpwd(char **tk);
#endif
