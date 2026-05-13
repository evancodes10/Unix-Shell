#include "io.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

void print_prompt()
{
    printf("myshell> "); //display shell prompt 
    fflush(stdout); //forces the prompt to display instantly
}

char *read_line()
{
    char *line = NULL;
    size_t buffer_size = 0;

    ssize_t chars_read = getline(&line, &buffer_size, stdin); //gets the users input with NULL and 0 initially for automatic allocation upon user input

    if (chars_read == -1) //error handling for EOF ("Ctrl+D") or input failure
    {
        free(line); 
        printf("\n");
        exit(EXIT_SUCCESS);
    }

    if (chars_read > 0 && line[chars_read - 1] == '\n') //remove trailing newline character from input
    {
        line[chars_read - 1] = '\0'; //replace newline with null terminator
    }

    return line;
}