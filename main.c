#include "simple_shell.h"
/**
 * main - simple shell
 * A simple of shell
 * Return: 0 Always
*/
int main ()
{
	char *buf = NULL;
	pid_t pid;
	char	**cmd = NULL;
	size_t len;

	while (1)
	{
		print_prompt();
		if (getline(&buf, &len, stdin) == -1)
		{
			if (isatty(STDIN_FILENO) == 1)
				write(1, "\n", 1);
			break;
		}
		cmd = splt(buf, " \n\t");
		if (cmd[0] == NULL)
		{
			continue;
		}
		if (_strcmp(cmd[0], "exit") == 0)
		{
			break;
		}
		pid = fork();
		check_mn(pid, cmd);
	}
			free(cmd);
			free(buf);
			fflush(stdout);
	return (0);
}
