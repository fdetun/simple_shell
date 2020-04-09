#include "simple_shell.h"
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
	int i = 0;
	int j = 0;

	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	return (dest);
}
