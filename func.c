#include "simple_shell.h"

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
/**
 * pn - pn.
 * @count: counter
 * Return: Always 0.
 */
void pn(int count)
{
	if ((count / 10) > 0)
		pn(count / 10);
	_putchar((count % 10) + '0');
}

#include "simple_shell.h"
/**
 * print_prompt - print the prompt
*/
void print_prompt(void)
{
	if (isatty(STDIN_FILENO))
		write(1, SHELL, _strlen(SHELL));
	signal(SIGINT, han_func);
}
/**
 * han_func - handle commands
 * @sig: int to handle
*/
void han_func(int sig)
{
	signal(sig, SIG_IGN);
	write(STDERR_FILENO, "\n", 1);
	write(STDOUT_FILENO, SHELL, _strlen(SHELL));
	signal(SIGINT, han_func);
}
/**
 * check_mn - cheker for main
 * @pid: to check
 * @cmd: command to check
 * @av: av
 * @f: f
*/
void check_mn(int pid, char **cmd, char **av, int f)
{
	char *doc = NULL;

	doc = splt_env(cmd[0]);
	if (pid == -1)
		perror("not forked");
	else if (pid > 0)
	{
		waitpid(pid, 0, 0);
		kill(pid, SIGTERM);
	}
	else
	{
		if (doc == NULL)
		{
			write(STDOUT_FILENO, av[0], _strlen(av[0]));
			write(STDOUT_FILENO, ": ", 2);
			pn(f);
			write(STDOUT_FILENO, ": ", 2);
			write(STDOUT_FILENO, cmd[0], _strlen(cmd[0]));
			write(STDOUT_FILENO, ": not found\n", 12);
			fflush(stdout);
			free(cmd);
			exit(127);
		}
		if (execve(doc, cmd, environ) == -1)
		{
			perror("hsh");
			fflush(stdout);
			free(cmd);
			exit(1);
		}
		exit(EXIT_FAILURE);
	}
}
