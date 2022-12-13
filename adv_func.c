#include "simple_shell.h"

/**
 * _getenv - function to get enviroment variable by name
 * @name: name of the variable
 * Return: Return a pointer
 */
char *_getenv(char *name)
{
	char **env, *c, *_name;

	env = environ;
	while (*env != NULL)
	{
		for (c = *env, _name = name; *c == *_name; c++, _name++)
		{
			if (*c == '=')
				break;
		}
		if ((*c == '=') && (*_name == '\0'))
			return (c + 1);
		env++;
	}
	return (NULL);
}
/**
 * _calloc - a function that allocates memory for an array, using malloc.
 * @size : int
 * Return: pointer to an array
 */
void *_calloc(unsigned int size)
{
	char *a;
	unsigned int i;

	if (size == 0)
	return (NULL);
	a = malloc(size);
	if (a == NULL)
	return (NULL);
	for (i = 0; i < size; i++)
	{
		a[i] = '\0';
	}
	return (a);
}
/**
 * _itoa - turns integer to str
 * @num : int
 * @str : string
 * Return: str
 */
char *_itoa(int num, char *str)
{
	int i = 0, r;
	int isNegative = 0;

	if (num == 0)
	{
		str[i++] = '0';
		str[i] = '\0';
		return (str);
	}

	if (num < 0)
	{
	isNegative = 1;
		num = -num;
	}

	while (num != 0)
	{
		r = num % 10;
		str[i++] = (r > 9) ? (r - 10) + 'a' : r + '0';
		num = num / 10;
	}

	if (isNegative == 1)
		str[i++] = '-';
	str[i] = '\0';
	rev_string(str);
	return (str);
}
/**
 *rev_string - reverse string
 *@s : string
 *Return: 0
 */
void rev_string(char *s)
{
	char h;
	int i, j;
	int c = 0;

	for (i = 0; s[i] != '\0'; i++)
	{
		c++;
	}
	for (j = 0 ; j < c / 2 ; j++)
	{
		h = s[c - j - 1];
		s[c - j - 1] = s[j];
		s[j] = h;
	}
}
/**
 * _atoi - convert into integer
 * @s : string
 * Return: 0
 */
int _atoi(char *s)
{
	int i, sign = 1, num = 0, res;

	for (i = 0; s[i] != '\0';)
	{
		if (s[i] == '-')
		{
			sign = sign * (-1);
			i++;
		}
		else if ((s[i] >= '0') && (s[i] <= '9'))
		{
			num = num * 10 + (s[i] - '0');
			i++;
		}
		else
			i++;
	}
	res = (sign * num);
	return (res);
}
