#include "simple_shell.h"
/**
 * main - simple shell
 * A simple of shell
 * @argc: unused
 * @argv: vector
 * Return: 0 Always
*/
int main(int argc __attribute__((unused)), char **argv)
{
	char *buf = NULL, **cmd = NULL, **all_cmd_buf;
	size_t len;
	int f = 0, number_cmd = 0, i, flag, get;
	split_cmd r;

	while (1)
	{
		flag = 0, f++;
		print_prompt();
		if (getline(&buf, &len, stdin) != -1)
		{
			r = check_split(buf);
			all_cmd_buf = r.all_cmd_buf, number_cmd = r.number_cmd, flag = r.flag;
		}
		else
		{
			if (isatty(STDIN_FILENO) == 1)
				write(1, "\n", 1);
			break;
		}
		if (flag == 0)
			get = execute_cmd(buf, argv, f);
		if (flag == 1)
			for (i = 0; i < number_cmd; i++)
				get = execute_cmd(all_cmd_buf[i], argv, f);
		if (get == 1)
			continue;
		if (get == 2)
		{
			exit(0);
			break;
		}

	}
			free(cmd), free(buf), fflush(stdout);
	return (0);
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
	if (_strcmp(cmd[0], "exit") == 0)
	{
		return (2);
	}
	pid = fork();
	check_mn(pid, cmd, argv, f);
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
