#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *my_getline(void)
{
    char *input = NULL; // initialise pointer to be passed through getline() function
    //char **array = NULL; // initialise pointer to be passed through getline() function
    size_t size = 0; // initialise pointer to be passed through getline() function

    printf("$ "); // Prompt display

    if (getline(&input, &size, stdin) == -1) { // getline, get line (lol) from user input, if it return -1 that means getline has been stopped by ctrl + d or something wrong happened
        free(input); // free memory allocated
        return NULL; // return return a value to function but also leave the function
    }
    if (size == 0) // Error handling
        return NULL;
    if (input[strlen(input) - 1] == '\n') // Manage new line in command prompt
        input[strlen(input) - 1] = '\0';

    return input; // return the string that user put
}

int main(void)
{
    char *get = NULL;

    while (1) { // infinite loop, need something to stop it
        get = my_getline(); // assign to getline
        if (!get || strcmp(get, "exit") == 0) { // check if user input is "exit"
            printf("Exit\n");
            free(get); // free allocate memory
            return 0; // leave the main function, so the program
        }
        free(get); // free memory allocated
    } // It will return to the beginning of the loop because it's an infinite loop

    return 0;
}
