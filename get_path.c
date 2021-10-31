#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/wait.h>

char *my_getline(void)
{
    char *input = NULL; // initialise pointer to be passed through getline() function
   //  char **array = NULL; // initialise pointer to be passed through getline() function
    size_t size = 0; // initialise pointer to be passed through getline() function

    printf("$> "); // Prompt display

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

void print_env(char **env)
{
    for (unsigned int i = 0; env[i] != NULL; ++i) // parse env
        printf("%s\n", env[i]); // print each lines of env
}

char *find_path(char **env)
{
    char *path = NULL; // also mean &path[0]

    for (unsigned int i = 0; env[i] != NULL; ++i) // parse env
        if (strncmp(env[i], "PATH=", strlen("PATH=")) == 0) // if 5 first characters of env line is equal to PATH=, then assign path value
            path = env[i];
    path = &path[5]; // remove "PATH=" on string

    return path; // return all paths, without any useless characters
}

char *get_exec_command(char *token, char *line)
{
    static char str[1024]; // set 1024 char to str
    unsigned int i = 0;

    for (; token[i] != '\0'; ++i) // parse token character
        str[i] = token[i]; // set token character to our str declared before, for example now str will be "/bin"
    str[i] = '/'; // set / character after the new str, so it will be "/bin/"
    ++i; // increment i to get next characters
    for (unsigned int t = 0; line[t] != '\0'; ++i, ++t) // set all line's character to our new str, so str will be "/bin/ls"
        str[i] = line[t];
    str[i] = '\0'; // very important to avoid bugs, set the last string character

    return str; // return the new string : "/bin/ls"
}

void string_copy(char *dest, char *src, size_t n)
{
    for (unsigned int i = 0; i < n; ++i) // copy src (source) to dest (destination)
        dest[i] = src[i];
}

void execute_by_path(char *get, char **av, char **env)
{
    char const *separator = ":"; // separator get by PATH= value
    char *path = find_path(env); // value returned by find_path(env) function
    char *token = strtok(path, separator); // first split of path
    char *str = NULL; // will be use to get all string concatenated
    bool not_found = true; // check if command exist or not

    while (token != NULL) { // token is equal to string split
        string_copy(path, token, strlen(path)); // copy token to path, to avoid bugs
        str = get_exec_command(path, get); // str is now equal to : current string split + / + command line
        if (access(str, X_OK) == 0) { // access function with X_OK flag return 0 if the string passed as parameter is executable
            not_found = false; // set not_found as false because we found the executable
            if (fork() == 0) // if fork() == 0 means that fork() didn't fail and created child process
                execve(str, av, env); // execve will execute a command, so in our case it will be str, then it kills process, but we're in a child process so there is no problem
            else
                wait(NULL); // if fork() failed, use wait to avoid bug (tbh i dont rly know why but we should use this xd)
            break; // break mean it will leave the loop (while token != NULL), because we don't need to make any occurrence anymore
        }
        token = strtok(NULL, separator); // if the split + / + command line has not executable, we continue with another token (= string split)
    }
    if (not_found == true) // if not_found is set as true yet, that mean we didn't enter to access() condition because in access condition we say that not_found is equal to false
        printf("%s: command not found\n", get); // so print the command line: command not found
}

void execute_command(char *get, char **av, char **env)
{
    if (!get || strcmp(get, "exit") == 0) { // check if user input is "exit"
        printf("Exit\n");
        free(get); // free allocate memory
        exit(0); // leave the main function, so the program
    }
    if (strcmp(get, "env") == 0) // compare command line and "env" character, if it's true, print_env
        print_env(env);
    else // else go to execute_by_path() function to try to execute the command line
        execute_by_path(get, av, env);
}

int main(int ac, char **av, char **env)
{
    char *get = NULL;
    (void)ac; // we don't need ac, but we need to put it as parameters, because env is always the third parameter of main function

    while (1) { // infinite loop, need something to stop it
        get = my_getline(); // assign to getline
        execute_command(get, av, env); // main function of the program, will execute all functions
        free(get); // free memory allocated
    } // It will return to the beginning of the loop because it's an infinite loop

    return 0;
}
