#include "simple_shell.h"

/**
 * _putchar - writes the character c
 * @c: The character to print
 * Return: Always 0 (success)
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 **_strchr - a function that locates a character in a string.
 *@s : pointer
 *@c : char
 *Return: 0
*/
char *_strchr(char *s, char c)
{
	for (; *s != c && *s != '\0'; s++)
	;
	if (*s == c)
		return (s);
	else
		return (NULL);
}

/**
 *_strlen - length of string
 *@s : a string
 *Return: len
 */
int _strlen(char *s)
{
	int i;
	int c = 0;

	if (s == NULL)
		return (0);
	for (i = 0; s[i] != '\0'; i++)
	{
		c++;
	}
	return (c);
}

/**
 *_strcpy - copy a string
 *@dest: a string
 *@src: a string
 *Return: copied string
*/
char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
	if (dest[i] != '\0')
		dest[i] = '\0';
	return (dest);
}

/**
 * _strcmp - compare two strings
 *@s1 : a string
 *@s2 : a string
 *Return: 0
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] != '\0'; i++)
	{
		if (s1[i] != s2[i])
			break;
	}
	return (s1[i] - s2[i]);
}
