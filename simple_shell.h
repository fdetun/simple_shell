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

void print_prompt ();
char **splt(char *raw_cmd, char *limit);
char *rec_env(char *buf);
/**static void free_array(char **array);
*/
#endif
