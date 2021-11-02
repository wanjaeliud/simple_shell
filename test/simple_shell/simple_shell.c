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
	ssize_t charsRead;
	char *line = NULL;
	size_t size = 0;
	pid_t child_pid;
	char *argv[] = {NULL, NULL};
	int status;

	while (1)
	{
		printf("#Simple_Shell$ ");
		charsRead = getline(&line, &size, stdin);
		if (charsRead == -1)
		{
			fprintf(stderr, "Failed to read input\n");
			continue;
		}
		else
		{
			if (strcmp(line, "\n") == 0)
				continue;
			if (strcmp(line, "exit\n") == 0)
				_exit(EXIT_SUCCESS);
			child_pid = fork();
			if (child_pid == -1)
			{
				perror("Error: ");
				continue;
			}
			if (child_pid == 0)
			{
				argv[0] = line;
				if (execve(line, argv, NULL) == -1)
				{
					perror("Error: ");
					continue;
				}
			}
			else if (child_pid != 0)
			{
				wait(&status);
			}
		}
	}
}
