#include "main.h"



int main(int ac, char *av[])
{
	int i;
	char *string;
	char **string2;

	printf("Print string; ");
	string = _getline();
	if (string == NULL)
		printf("_getline failed\n");
	string2 = split_string(string, " \t");
	if (string2 == NULL)
		printf("split_string failed\n");
	string2[0] = "changed";

	for (i = 0; string2[i] != NULL; i++)
		printf("%s\n", string2[i]);
	printf("print this \n");
	return (0);
}
