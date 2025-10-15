// C program to illustrate
// command line arguments
#include <stdio.h>

int main(int argc, char* argv[])
{
    printf("Program name is: %s", argv[0]);

    if (argc == 1)
        printf("\nNo Extra Command Line Argument Passed "
               "Other Than Program Name");

    if (argc >= 2) {
        printf("\nNumber Of Arguments Passed: %d", argc);
        printf("\n----Following Are The Command Line "
               "Arguments Passed----");
        for (int i = 0; i < argc; i++)
            printf("\nargv[%d]: %s", i, argv[i]);
    }
    return 0;
}

// how to build
// gcc -o demo_working_of_command_line_arguments demo_working_of_command_line_arguments.c

// how to run
// ./demo_working_of_command_line_arguments arg1 arg2 arg3
    // Output
    // Program name is: ./demo_working_of_command_line_arguments
    // Number Of Arguments Passed: 4
    // ----Following Are The Command Line Arguments Passed----
    // argv[0]: ./demo_working_of_command_line_arguments
    // argv[1]: arg1
    // argv[2]: arg2
    // argv[3]: arg3