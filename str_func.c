#include <stdio.h>
#include "simple_shell.h"
#include <stdlib.h>

/**
 * _strdup - _strdup.
 * @str: variable
 * Return: a Or NULL.
*/
char *_strdup(char *str)
{
char *a;
unsigned int j = 0;
unsigned int i = 0;

if (str == NULL)
{
return (NULL);
}
while (str[j] != '\0')
j++;
j = j + 1;
a = malloc(j *sizeof(char));
if (a == NULL)
{
return (NULL);
}
while ((a[i] = str[i]) != '\0')
i++;
return (a);
}

/**
 * _strcpy - copies the string
 * @dest: char the destinated
 * @src: char the source
 * Return: pointer to dest
*/
char *_strcpy(char *dest, char *src)
{
	int i = 0;
	int j;

	while (src[i] != '\0')
		i++;
	for (j = 0; j < i; j++)
	{
		dest[j] = src[j];
	}
	dest[i] = '\0';
	return (dest);
}
/**
 * _strcat - concatenates two strings.
 * @dest: char the destination
 * @src: char the source
 * Return: @dest char
*/
char *_strcat(char *dest, char *src)
{
int i, j = 0;
while (dest[j] != '\0')
{
j++;
}
for (i = 0; src[i] != '\0'; i++)
{
dest[j] = src[i];
j++;
}
dest [j] = '\0';
return (dest);
}