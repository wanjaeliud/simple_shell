#include "main.h"

/**
 *getPATH - gets the list of directories in PATH
 *
 *Return: an array containing list of directories in PATH
 */

char **getPATH(void)
{
	char **path_dir;
	int i = 0, n = 0;
	size_t size = 1;
	char *token, *token2;

	while (environ[i])
	{
		if (strncmp(environ[i], "PATH=", 5) == 0)
		{
			token = strtok(environ[i], "=");
			break;
		}
		i++;
	}

	token = strtok(NULL, "=");

	path_dir = malloc(sizeof(char *) * (size + 1));
	if (!path_dir)
		return (NULL);

	token2 = strtok(token, ":");
	while (token2 != NULL)
	{
		path_dir[n] = token2;
		token2 = strtok(NULL, ":");
		size++;
		path_dir = realloc(path_dir, sizeof(char *) * size);
		n++;
	}

	return (path_dir);
}


/**
 *get_abs_pathname - gets the absolute pathname
 *                        of an existing shell executable
 *@argument: the name of executable to get absolute pathname for
 *@path_dir: the list of direcotries to check
 *           if argument exists in
 *
 *Return: absolute pathname of argument
*/

char *get_abs_pathname(char *argument, char **path_dir)
{
	struct stat status;
	char *token, *path;
	int i = 0;
	char *buffer;

	buffer = malloc(sizeof(char) * 1024);
	if (!buffer)
		return (NULL);

	token = strtok(argument, "/");

	while (token != NULL)
	{
		while (path_dir[i])
		{
			buffer = strcpy(buffer, path_dir[i]);
			buffer[strlen(path_dir[i])] = '/';
			buffer[strlen(path_dir[i]) + 1] = '\0';
			path = strcat(buffer, token);
			if (stat(path, &status) == -1)
				continue;
			else
				return (buffer);
			i++;
		}
		token = strtok(NULL, "/");
	}
	return (NULL);
}
