#include "hsh.h"

/**
 * launch_shell - function to create child preocess
 * and run commands.
 * @args: arguments
 *
 * Return: returns 1
 */

int launch_shell(char **args)
{
	pid_t pid, wpid;
	int status;

	pid = fork();

	if (pid == 0)
	{
		if (execvp(args[0], args) == -1)
		{
			perror("$ ");
		}
	exit(EXIT_FAILURE);
	}

	else if (pid < 0)
	{
		perror("$ ");
	}
	else
	{
		do {
			wpid = waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}

	return (1);
}
