#include "simple_shell.h"

/**
 * check_built - verif built or not
 *@src: command input
 * Return: 1 or 0
 */
int check_built(char *src)
{
int i = 0;
char *builtarray[] = {"exit", "cd", NULL};

while (builtarray[i])
{
if (_strcmp(builtarray[i], src) == 0)
return (1);
i++;
}
return (0);
}

/**
 * execd - exec cmdbuilt
 *@cmdbuilt : cmdbuilt input
 * Return: void
 */

void execd(char **cmdbuilt)
{
if (_strcmp(cmdbuilt[0], "exit") == 0)
exit(0);
else if (_strcmp(cmdbuilt[0], "cd") == 0)
if (chdir(cmdbuilt[1]) == -1)
{
perror("chdir error");
}
}


/**
 * execute_cmd - execute the command
 * @buf: the command line
 * @argv: argv
 * @f: 0
 * Return: 1 if null, 2 if exit, else 0
*/
int execute_cmd(char *buf, char **argv, int f)
{
pid_t pid;
char **cmd = NULL;

cmd = splt(buf, " \n\t");
if (cmd[0] == NULL)
return (1);
if (check_built(cmd[0]) == 1)
{
execd(cmd);
}
else
{
pid = fork();
check_mn(pid, cmd, argv, f);
}
return (0);
}
/**
 * check_split - check for ";" and split the commands line
 * @buf: the line entred
 * Return: splited commands and flag
*/
split_cmd check_split(char *buf)
{
	int length = 0, flag = 0, number_cmd = 0;
	char *all_cmd;
	char **all_cmd_buf;
	split_cmd r;

	while (buf[length] != '\0')
	{
		if (buf[length] == ';')
		{
			flag = 1;
			all_cmd_buf = malloc(1024);
			all_cmd = _strtok(buf, ";");
			while (all_cmd != NULL)
			{
				all_cmd_buf[number_cmd] = _strdup(all_cmd);
				all_cmd = _strtok(NULL, ";");
				number_cmd++;
			}
			break;
		}
		length++;
	}
	r.all_cmd_buf = all_cmd_buf;
	r.number_cmd = number_cmd;
	r.flag = flag;
	return (r);
}
