#include"simple_shell.h"

/**
*split - divide the buffer to small segment
*@line: the buffer to divide
*@div: the character to split with
*Return: return a string prepared for the exec
**/
char **split(char *line, char *div)
{
	char **buffer;
	char *token;
	int i = 0, len;

	if (line == NULL)
	{
		return (NULL);
	}

	buffer = _calloc(sizeof(char *) * 256);
	if (buffer == NULL)
		return (NULL);
	token = strtok(line, div);
	if (token == NULL)
	{
		free(buffer);
		return (NULL);
	}

	while (token)
	{
		len = _strlen(token);
		buffer[i] = _calloc(sizeof(char) * len + 1);
		if (buffer[i] == NULL)
		return (NULL);
		_strcpy(buffer[i], token);
		token = strtok(NULL, div);
		i++;
	}
	buffer[i] = NULL;
	return (buffer);
}
