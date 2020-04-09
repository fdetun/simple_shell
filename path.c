#include "simple_shell.h"
/**
 * rec_env - env
 * @buf: buffer to read
 * Return: NULL
*/
char *rec_env(char *buf)
{
	struct stat buff;
	char *str;
	char *s;
	char *token;
	int i = 0;
	char* args[100];
	char* tab[100];

	s = getenv("PATH");
        token = strtok(s,":");
	while (token != NULL)
	{
		args[i] = token;
		i++;
		token = strtok(NULL,":");
	}
        i = 0;
	while (args[i])
	{
		str = (char*)malloc(100);
		strcat(str, args[i]);
		strcat(str, "/");
		strcat(str,buf);
		tab[i] = str;
		if (stat(tab[i], &buff) == 0)
		{
			return (tab[i]);
		}
		i++;
	}
	free(str);
	free(token);
	return (NULL);

}
