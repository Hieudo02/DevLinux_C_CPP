/*
Step 1: Creating a program to debug
*/
#include <stdio.h>

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Usage: %s <arg1> <arg2>\n", argv[0]);
        return 1;
    }
    printf("Argument 1: %s\n", argv[1]);
    printf("Argument 2: %s\n", argv[2]);
    return 0;
}

/*
Step 2: Compiling the program with -g flag
    $ gcc -g -o pass_command_line_arguments_to_gdb 03_pass_command_line_arguments_to_gdb.c

- g: The -g flag is an option used with the "gcc" command.
It instructs the compiler to include debugging information in the compiled executable.
This debugging information is essential for effective debugging using tools like GDB (GNU Debugger).

Step 3: Start GDB with Command Line Arguments
    $ gdb  ./03_pass_command_line_arguments_to_gdb

Step 4: Passing the arguments
    (gdb) run Hello World

Step 5: Setting the breakpoint
    (gdb) break main
    (gdb) run Hello World (if not already running)

Step 6: Start debugging the program
    Now, type run to start debugging the program. The program will run until it reaches the breakpoint.
    You can then step through the code, inspect variables, and perform other debugging tasks.
    - Here are some commonly used commands for further navigation and debugging:
        + next (or 'n'): This command allows you to execute the next line of code in your program,
        skipping over function calls.

        + step (or 's'): Use this command to step into functions,
        meaning you will move to the next line within the called function.

        + continue (or 'c'): It resumes the program's execution until it encounters
        the next breakpoint or reaches the end.

        + print (or 'p'): This command lets you inspect the values of variables
        and expressions during debugging.

        + info locals: Provides information about local variables in the current scope.

        + backtrace (or 'bt'): Displays a stack trace showing the sequence of function calls
        that led to the current point in the program.

        + list: Shows a few lines of source code around the current execution point.

Step 7: Quit GDB
    (gdb) quit
    A prompt will appear asking if you want to confirm quitting. Type y and press Enter to exit GDB.
*/