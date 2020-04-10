#include "simple_shell.h"
/**
 * rec_env - env
 * @buf: buffer to read
 * Return: NULL
*/
char *rec_env(char *cmd)
{
	char **en = environ;
	char *path_array[100];
	char *s2 = cmd;
	char *new_var = NULL;
	struct stat buf;
	int i = 0, j = 0;
	char *path_get;
	char *first_path;
	char *path_tokens;

	path_get = _getenv(en);
	first_path = _strdup(path_get);
	path_tokens = strtok(first_path, ":");
	new_var = malloc(sizeof(char) * 100);
	while (path_tokens != NULL)
	{
		path_array[i++] = path_tokens;
		path_tokens = strtok(NULL, ":");
	}
	path_array[i] = NULL;
	for (j = 0; path_array[j]; j++)
	{
		_strcpy(new_var, path_array[j]);
		_strcat(new_var, "/");
		_strcat(new_var, s2);
		_strcat(new_var, "\0");

		if (stat(new_var, &buf) == 0)
		{
			free(first_path);
			return (new_var);
		}
		else
			new_var[0] = 0;
	}
	free(first_path);
	free(new_var);
	if (stat(cmd, &buf) == 0)
		return (strdup(cmd));
	return (NULL);
}
