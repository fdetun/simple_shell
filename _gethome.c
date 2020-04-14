#include "simple_shell.h"
/**
 * _gethome - _gethome
 * @tk: env
 * Return: buf
*/

char *_gethome(char **tk)
{
	int i, j;
	char *ref, *buf;
	char *pth = "HOME=";

	i = 0;
	while (tk[i])
	{
		j = 0;
		while (tk[i][j] == pth[j])
		{
			if (tk[i][j + 1] == pth[j + 1])
			{
				ref = tk[i];
				break;
			}
			j++;
		}
		i++;
	}
	buf = malloc(1024);
	i = _strlen(pth);
	j = 0;
	while (ref[i] != '\0')
	{
		buf[j] = ref[i];
		i++;
		j++;
	}
	buf[j] = '\0';
	return (buf);
}

/**
 * _getoldpwd - _getoldpwd
 * @tk: env
 * Return: buf
*/

char *_getoldpwd(char **tk)
{
	int i, j;
	char *ref, *buf;
	char *pth = "OLDPWD=";

	i = 0;
	while (tk[i])
	{
		j = 0;
		while (tk[i][j] == pth[j])
		{
			if (tk[i][j + 1] == pth[j + 1])
			{
				ref = tk[i];
				break;
			}
			j++;
		}
		i++;
	}
	buf = malloc(1024);
	i = _strlen(pth);
	j = 0;
	while (ref[i] != '\0')
	{
		buf[j] = ref[i];
		i++;
		j++;
	}
	buf[j] = '\0';
	return (buf);
}
