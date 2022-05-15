#include <stdio.h>
#include "main.h"
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

/*
    1 - display the environments variables
    2 - get an env variable (_getenv)
    3 - searching an executable from the PATH env (locate)
    4 - simple shell (show case)
*/

extern char **environ;

int main(void)
{
    char *cmd = NULL;
    char *args[] = {NULL, NULL};
    size_t buff_size = 0;
    ssize_t n_read = 0;
    char *cmd_path = NULL;

    while (1)
    {
        printf("Enter command: ");
        n_read = getline(&cmd, &buff_size, stdin);
        cmd[n_read - 1] = '\0';

        cmd_path = locate(cmd);
        if (cmd_path)
        {
            args[0] = cmd_path;
            if (fork() == 0)
                execve(*args, args, NULL);
            else {
                wait(NULL);
                free(cmd_path);
                cmd_path = NULL;
            };
        }
        else
            dprintf(STDERR_FILENO, "%s: Command not found\n", cmd);
    }

    return (0);
}
