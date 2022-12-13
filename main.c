#include "simple_shell.h"
/**
*main - tha main function
*Return: Always 0
*/
int main(void)
{
	char *line, *cmd = NULL, **str, *div = " ​\t\r\n\a\v​:";
	int status = 1, count = 0, ex = 0;

	signal(SIGINT, sig);
	while (status)
	{
		count++;
		if (isatty(STDIN_FILENO))
			prompt();
		fflush(stdin);
		line = _getline();
		if (!line)
			continue;
		str = split(line, div);
		free(line);
		if (str == NULL)
		continue;
		if ((_strcmp(str[0], "env") == 0))
		{
			free_array(str);
			print_env();
			continue;
		}
		if ((_strcmp(str[0], "exit") == 0))
		{
			if (str[1] != NULL)
				ex = _atoi(str[1]);
			free_array(str);
			exit(ex);
		}
		cmd = path(str[0]);
		status = _exec(cmd, str);
		if (status == -1)
			_perror(count);
		free_array(str);
		free(cmd);
		if (!isatty(STDIN_FILENO))
		exit(0);
	}
	return (0);
}
