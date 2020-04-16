#include "simple_shell.h"
/**
 * splt - split
 * @cm: to split
 * @limit: where to stop
 * Return: cmd
*/
char **splt(char *cm, char *limit)
{
	char	*ptr = NULL;
	char	**cmd = NULL;
	size_t	i = 0;

	ptr = _strtok(cm, limit);
	cmd = malloc(1024);
	if (!cmd)
	{
		perror("Error\n");
		free(cmd);
		free(cm);
		exit(99);
	}
	while (ptr != NULL)
	{
		cmd[i++] = ptr;
		ptr = _strtok(NULL, limit);
	}
	cmd[i] = NULL;
	return (cmd);
}

