# Simple Shell

This a Unix command line interpreter that we implemented using C, created to run in a Unix-like operating system, to capture and execute commands from the user. It's designed to mimic sh shell.

## Installation
clone this repository:
```
git clone git@github.com:wanjaeliud/simple_shell.git
cd simple_shell
```

## Compilation and output
Your shell should be compiled this way:
```
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```

## Output
Your shell should work like this in interactive mode:
```
$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$
```
But also in non-interactive mode:
```
$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
$
$ cat test_ls_2
/bin/ls
/bin/ls
$
$ cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
$
```

## Files
This repository contains the following files:
| File | Description |
| -------- | ----------- |
| [hsh.c](./hsh.c) | This is the entry point of our program |
| [_getline.c](./_getline.c) | Reads the standard input for commands |
| [execute_builtins.c](./execute_builtins.c) | Implements the shell built in commands |
| [split_string.c](./split_string.c) | Tokenizes arguments from the standard input |
| [getPathName.c](./getPathName.c) | Fetches the shell executable programs |
| [create_process.c](./create_process.c) | creates child process to execute shell programs |
| [man_1_simple_shell](./man_1_simple_shell) | Contains the man page for our Simple shell |

## Contributors
* **Beldine Moturi** - [Beldine-Moturi](https://github.com/Beldine-Moturi)
* **Eliud Wanja** - [wanjaeliud](https://github.com/wanjaeliud)

## Acknowledgements
If you find some observations or ways to improve this project, kindly reach out to any of us.
