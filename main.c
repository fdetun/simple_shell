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
	}
			free(cmd), free(buf), fflush(stdout);
	return (0);
}
