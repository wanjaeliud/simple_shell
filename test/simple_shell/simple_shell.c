#include "main.h"

/**
 *main - displays a prompt
 *       and executes commands entered by user
 *       until "exit" is passed as command
 *
 *Return: 0 on success
 */

int main(void)
{
	//ssize_t charsRead;
	char *line = NULL;
	size_t size = 0;
	pid_t child_pid;
	char *argv[] = NULL;
	int status;

	while (1)
	{
		printf("#Simple_Shell$ ");
		line = _getline();
		if (!line)
			break;
		else
		{
			if (strcmp(line, "\n") == 0)
				continue;
			if (strcmp(line, "exit\n") == 0)
			{
				free(line);
				break;
			}
			child_pid = fork();
			if (child_pid == -1)
			{
				perror("Error: ");
				continue;
			}
			if (child_pid == 0)
			{
				argv = split_string(line, " ");
				if (execve(argv[0], argv, NULL) == -1)
				{
					perror("Error: ");
					exit(EXIT_FAILURE);
				}
			}
			else if (child_pid != 0)
			{
				wait(&status);
			}
		}
	}
	_exit(EXIT_SUCCESS);
}
