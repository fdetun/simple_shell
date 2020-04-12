#include "simple_shell.h"
/**
 * _strtok - split a string
 * @s: the string to split
 * @deli: deliminator
 * Return: splited string
*/
char *_strtok(char *s, char *deli)
{
	int i;
	static char *c;

	if (!s)
		s = c;
	i = *s++;
	while (_strchr(deli, i))
	{
		if (i == 0)
			return (0);
		i = *s++;
	}
	--s;
	c = s + _strcspn(s, deli);
	if (*c != 0)
	{
		*c = 0;
		c++;
	}
	return (s);
}
/**
 * _strchr - function that locates a char in string
 * @s: char the string
 * @c: char to locate in  a string
 * Return: 0 Alwyas
*/
char *_strchr(char *s, char c)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] == c)
			return (s + i);
	}
	if (s[i] == c)
		return (s + i);
	return (0);
}
/**
 * _strcspn - gets the length of a prefix string
 * @s: string
 * @pre: prefix string
 * Return: number of bytes in the initial seg of s
 */
unsigned int _strcspn(char *s, char *pre)
{
	unsigned int len = 0, i = 0;

	while (s[len] != 0)
	{
		int flag = 0;

		for (i = 0; pre[i] != 0; i++)
		{
			if (s[len] == pre[i])
			{
				flag = 1;
				break;
			}
		}
		if (flag == 0)
			len++;
		else
			break;
	}
	return (len);
}
