#include <stdio.h>
#include <unistd.h>

extern char **environ;

int main(int argc, char *argv[])
{
	int counter = 0;

	while (environ[counter] != NULL)
	{
		puts(environ[counter]);
		counter++;
	}
	return (0);
}
