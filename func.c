#include "simple_shell.h"
/**
 * print_prompt - print the prompt
*/
void print_prompt()
{
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 2);
}
/**
 * han_func - handle commands
 * @sig: int to handle
*/
void han_func(int sig)
{
	signal(sig, SIG_IGN);
	write(STDERR_FILENO, "\n", 1);
	print_prompt();
	signal(SIGINT, han_func);
}
/**
 * check_mn - cheker for main
 * @pid: to check
 * @cmd: command to check
*/
void check_mn(int pid , char **cmd)
{
	char *doc = NULL;

	doc = rec_env(cmd[0]);
	if (pid == -1)
		perror("fork");
	else if (pid > 0)
	{
		waitpid(pid, 0, 0);
		kill(pid, SIGTERM);
	}
	else
	{
		if (doc == NULL)
		{
			printf("Command not found\n");
		}
		else if (execve(doc, cmd, environ) == -1)
		{
			perror("hsh");
			fflush(stdout);
			free(cmd);
			exit(1);
		}
		exit(EXIT_FAILURE);
	}
}
