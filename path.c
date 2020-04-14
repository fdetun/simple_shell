#include "simple_shell.h"

/**
 * spltarr - spltarr
 * @nr: char to read
 * @c: char to read
 * @arr: char to read
 * Return: nr Or NULL
*/

char *spltarr(char *nr, char *c, char **arr)
{
	struct stat rf;
	int j = 0;

	while (arr[j])
	{
		_strcpy(nr, arr[j]);
		_strcat(nr, "/");
		_strcat(nr, c);
		_strcat(nr, "\0");
		j++;
		if (stat(nr, &rf) == 0)
			return (nr);
	}
	return (NULL);
}

/**
 * splt_env - env
 * @b: buffer to read
 * Return: NULL
*/
char *splt_env(char *b)
{
	char **en = environ;
	char *arr[1024];
	char *newarr = NULL;
	struct stat ref;
	int i = 0;
	char *a, *tooks, *myge;

	myge = _getenv(en);
	a = _strdup(myge);
	tooks = _strtok(a, ":");
	newarr = malloc(sizeof(char) * 1024);
	while (tooks)
	{
		arr[i] = tooks;
		tooks = _strtok(NULL, ":");
		i++;
	}
	arr[i] = NULL;
	if (spltarr(newarr, b, arr))
	{
		return (spltarr(newarr, b, arr));
	}
	else
		newarr[0] = 0;
	free(a);
	free(newarr);
	if (stat(b, &ref) == 0)
		return (_strdup(b));
	return (NULL);
}
