#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"
#include "parser.h"

Command parse_command(char *line)
{
    Command cmd; //creates the inital command struct that will be used throughout the parser file

    cmd.argc = 0;
    cmd.background = 0;
    cmd.input_file = NULL;
    cmd.output_file = NULL;
    cmd.has_pipe = 0;
    cmd.pipe_argv = NULL;

    cmd.argv = malloc(MAX_ARGS * sizeof(char*)); //allocates memory for the maximum amount of argument values

    if (cmd.argv == NULL) //error handling for malloc failure
    {
        perror("Malloc Failure");
        exit(EXIT_FAILURE);
    }

    char *token = strtok(line, " "); //each token is created after a space seperation
    
    while(token != NULL && cmd.argc < MAX_ARGS - 1) //ensures that the loop is not executed if the token is null or if the maximum arguments are exceeded 
    {
        cmd.argv[cmd.argc] = token; //the string at an argc index will be the token
        cmd.argc++; //increments the value for the next loops token

        token = strtok(NULL, " "); //gets the next token
    }

    cmd.argv[cmd.argc] = NULL; //null terminate argv for execvp

    return cmd;
}

void free_command(Command *cmd)
{
    free(cmd->argv); //frees the argv memory allocated 
}