"include "hsh.h"

/**
 * getLine = function to read lines from the command
 * 
 */

char getLine()
{
	char *line = (char *)malloc(sizeof(char) *1024);
	char ch;
	int bufersize = 1024, position = 0;

	if (!line)
	{
		printf("\nBuffer Allocation Error.");
		exit(EXIT_FAILURE);
	}
	while(1)
	{
		ch getchar();
		if (ch == EOF || ch == '\n')
		{
			line[position] = '\0';
			return line;
		}
		else
		{
			line[position] = ch;
		}
		postion++;

		if (position >= buffersize)
		{
			buffersize += 1024;
			line = realloc(line, sizeof(char) * buffersize);
			if (!line)
			{
				printf("\nBuffer Allocation Error.");
				exit(EXIT_FAILURE);
			}
		}
	}
}

/**
 * main - main entry point 
 * @argc: command line arguments
 * @argv: pointer to number of arguments
 *
 */

int main(int agrc, chat **argv)
{
	if (argc == 1)
		shell_interact();
	else if (argc == 2)
		shell_sript(argv[1]);
	else
		printf("\nInvalid Number Of Arguments");

	return EXIT_SUCCES;
}
