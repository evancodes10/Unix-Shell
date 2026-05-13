#include "shell.h"
#include "io.h"
#include "parser.h"
#include "executor.h"

int main(void)
{
    for(;;)
    {
        print_prompt();

        char *line = read_line();

        Command cmd = parse_command(line);

        execute_command(&cmd);
        
        free_command(&cmd);
        free(line);
    }

    return 0;
}