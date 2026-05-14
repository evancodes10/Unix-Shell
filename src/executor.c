#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include "shell.h"
#include "executor.h"

void execute_command(Command *cmd)
{
    if (cmd->argc == 0) //handles empty input
    {
        return;
    }

    pid_t pid = fork(); //creates a child process so commands run separately from the shell

    if (pid < 0) //if the fork fails then no child is created
    {
        perror("Fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0)
    {
        execvp(cmd->argv[0], cmd->argv); //replaces child process with target program

        perror("execvp"); //only runs if execvp fails
        exit(EXIT_FAILURE);
    }

    else
    {
        waitpid(pid, NULL, 0); //parent waits for child process ot finish before showing next prompt
    }
}