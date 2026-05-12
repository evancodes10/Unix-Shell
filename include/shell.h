#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <fcntl.h>

#define MAX_ARGS 64
#define MAX_LINE 1024

typedef struct
{
    char **argv;
    int argc;
    
    int background;
    
    char *input_file;
    char *output_file;

    int has_pipe;
    char **pipe_argv;

} Command;

#endif
