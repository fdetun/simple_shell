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
/**	char	*foued = NULL;
	int err = 0;
*/	size_t len;

	while (1)
	{
		print_prompt();
		if (getline(&buf, &len, stdin) == EOF)
		{
			if (isatty(0) == 1)
			{
				write(STDOUT_FILENO, "\n", 1);
				break;
			}
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
		if (pid == -1)
			perror("fork");
		else if (pid > 0)
		{
			waitpid(pid, 0, 0);
			kill(pid, SIGTERM);
		}
		else
		{
			if (execve(rec_env(buf), cmd, NULL) == -1)
			{
				perror("shell");
			}
			exit(EXIT_FAILURE);
		}
/**		free_array(cmd);
*/	}
	fflush(stdout);
	return (0);
}
