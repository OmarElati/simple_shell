#include "simple_shell.h"
char *_memcpy(char *dest, char *src, unsigned int n);

/**
 **_realloc -  a function that reallocates a memory block using malloc and free
 *@ptr : pointer
 *@old_size : int
 *@new_size : int
 *Return: pointer
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *tmp;

	if (new_size == old_size)
	return (ptr);
	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	if (ptr == NULL)
	{
		ptr = malloc(new_size);
		return (ptr);
	}
	tmp = malloc(new_size);
	tmp = _memcpy(tmp, ptr, new_size);
	free(ptr);
	return (tmp);
}
/**
**_memcpy - copies memory area.
*@dest: pointer
*@src: pointer
*@n: int
*Return: pointer
*/
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		dest[i] = src[i];
	}
	return (dest);
}
/**
 * _perror - prints error message
 * @count : int
 */
void _perror(int count)
{
	char *err, *err1;
	int le;

	le = int_len(count);
	err1 = _calloc(le + 1);
	err1 = _itoa(count, err1);
	err = _calloc(le + 11);
	_strcat(err, "./shell: ");
	_strcat(err, err1);
	perror(err);
	free(err);
	free(err1);
}
