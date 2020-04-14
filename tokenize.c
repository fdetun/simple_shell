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
		exit(99);
	}
	while (ptr)
	{
		cmd[i] = _strdup(ptr);
		ptr = _strtok(NULL, limit);
		++i;
	}
	cmd[i] = NULL;
	return (cmd);
}
