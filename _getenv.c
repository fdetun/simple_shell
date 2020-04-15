#include "simple_shell.h"
/**
 * _getenv - _getenv
 * @tk: env
 * Return: buf
*/

char *_getenv(char *pth)
{
int i = 0, j;
char **en = environ;

if (pth == NULL)
return (NULL);
while (en[i])
{
j = 0;
if (pth[j] == en[i][j])
{
for (j = 0; pth[j] != '\0'; j++)
{
if (pth[j] == en[i][j])
continue;
else
break;
}
if (pth[j] == '\0')
return (en[i] + j + 1);
}
i++;
}
return (NULL);
}
