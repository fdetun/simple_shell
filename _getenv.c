#include "simple_shell.h"
/**
 * _getenv - _getenv
 * @tk: env
 * Return: buf
*/

char *_getenv(char **tk)
{
int i, j;
char *ref, *buf;
char *pth = "PATH=";
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
i = strlen(pth);
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
