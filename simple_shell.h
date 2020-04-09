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
void print_prompt ();
void han_func(int sig);
char **splt(char *raw_cmd, char *limit);
char *rec_env(char *buf);
void check_mn(int pid , char **cmd);
/**static void free_array(char **array);
*/
#endif
