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
		signal(SIGINT, han_func);
		if (getline(&buf, &len, stdin) == EOF)
		{
/**			if (isatty(0) == 1)
			{
*/				write(STDOUT_FILENO, "\n", 1);
				break;
		}
		cmd = splt(buf, " \n\t");
		if (cmd[0] == NULL)
		{
			free(cmd);
			continue;
		}
		if (strcmp(cmd[0], "exit") == 0)
			break;
		pid = fork();
		check_mn(pid, cmd);
	}
	fflush(stdout);
	free(cmd);
	free(buf);
	return (0);
}
