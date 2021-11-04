#include "main.h"

/**
 *main - test split_string and _getline
 *Return: 0 on success
 */

int main(void)
{
	int i, size = 0;
	char **string;
	char *line = NULL;

	printf("$ ");
	line = _getline();
	if (!line)
		return (1);

	string = split_string(line, " ");
	if (string == NULL)
	{
		printf("Failed to fill string\n");
		return (1);
	}

	for (i = 0; string[i] != NULL; ++i)
	{
		printf("%s\n", string[i]);
		size++;
	}
	printf("Size of array = %d", size);

	/*if (execve(string[0], string, NULL) == -1)
	  printf("Error: failed to execute command\n");*/
	/*free(line);
	for (i = size; i >= 0; i--)
		free(string[i]);
		free(string);*/

	return (0);
}
