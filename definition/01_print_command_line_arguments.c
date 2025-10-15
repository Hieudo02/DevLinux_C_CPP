// C program named mainreturn.c to demonstrate the working
// of command line arguement
#include <stdio.h>

// defining main with arguments
int main(int argc, char* argv[])
{
    printf("You have entered %d arguments:\n", argc);

    for (int i = 0; i < argc; i++) {
        printf("%s\n", argv[i]);
    }
    return 0;
}

// how to build
// gcc -o print_command_line_arguments print_command_line_arguments.c

// how to run
// ./print_command_line_arguments arg1 arg2 arg3
    // Output
    // You have entered 4 arguments:
    // ./print_command_line_arguments
    // arg1
    // arg2
    // arg3