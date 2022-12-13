#include "simple_shell.h"

/**
* print_env - print the envirment variables
**/
void print_env(void)
{
	size_t i;
	int len;

	for (i = 0; environ[i] != NULL; i++)
	{
		len = _strlen(environ[i]);
		write(1, environ[i], len);
		write(STDOUT_FILENO, "\n", 1);
	}
}

/**
* _strcat - concatenate 2 strings
* @dest : string
* @src : string
* Return: 0
*/
char *_strcat(char *dest, char *src)
{
	int i, j;

	for (i = 0; dest[i] != '\0'; i++)
	;

	for (j = 0; src[j] != '\0'; j++)
		dest[i + j] = src[j];
	dest[i + j] = '\0';
	return (dest);
}
/**
* int_len - length of a number
* @n: the number
* Return: The length
*/
int int_len(int n)
{
	int len = 0;

	while (n != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}
/**
 * free_array - frees an array
 * @str : double pointer
 */
void free_array(char **str)
{
	int i;

	for (i = 0; str[i] != NULL; i++)
	{
		free(str[i]);
	}
	free(str);
}
/**
 * prompt - display prompt
 */
void prompt(void)
{
	_putchar('>');
	_putchar(' ');
}
