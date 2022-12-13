#include "simple_shell.h"

/**
*path - cherche for the command location
*@cmd: the command to treat
*Return: The absolute path of the command
**/
char *path(char *cmd)
{
	struct stat st;
	char *new_cmd = NULL, *path = NULL, *_path = NULL, **full = NULL;
	int i, x = 0, len, lencmd, l;

	if (stat(cmd, &st) == 0)
	{
		lencmd = _strlen(cmd);
		new_cmd = _calloc(sizeof(char) * lencmd + 1);
		_strcpy(new_cmd, cmd);
		return (new_cmd);
	}
	path = _getenv("PATH");
	len = _strlen(path);
	_path = _calloc(len + 1);
	_strcpy(_path, path);
	full = split(_path, ":");
	while (full[x])
	{
		l = _strlen(cmd);
		lencmd = _strlen(full[x]);
		new_cmd = _calloc(lencmd + l + 3);
		_strcpy(new_cmd, full[x]);
		_strcat(new_cmd, "/");
		_strcat(new_cmd, cmd);
		if ((stat(new_cmd, &st) == 0) && (access(new_cmd, F_OK | X_OK) == 0))
		{
			free(_path);
			for (i = 0; i < len; i++)
				free(full[i]);
			free(full);
			return (new_cmd);
		}
		free(new_cmd);
		x++;
	}
	for (i = 0; full[i] != NULL; i++)
		free(full[i]);
	free(full);
	free(_path);
	return (NULL);
}
