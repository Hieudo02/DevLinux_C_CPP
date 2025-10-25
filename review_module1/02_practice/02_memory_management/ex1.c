// 1. Is there anything wrong with the following code ?

/*
    #include <stdio.h>
    #include <string.h>

    void myfunction(char *q) {
        memcpy(q, "hello", 5);
    }

    int main(void) {
        char *p;
        myfunction(p);
        printf("%s\n", p);
        return 0;
    }
*/

/*
1. Uninitialized pointer (p) => Undefined Behavior:
    - "char *p;" has an indeterminate value and doesn’t point to valid writable memory.
    - Passing it to memcpy writes to a random address => crash/segfault or silent corruption.
    => must allocate memory for p before using it, e.g.: char p[6];
2. No null terminator copied (likely unintended):
    - "hello" is 5 bytes long, but C strings need a trailing '\0'. Copying only 5 bytes means if we later treat q as a string, it won’t be null-terminated.
    => must copy 6 bytes (including '\0') to ensure null termination.
*/

// Fixing the code:
#include <stdio.h>
#include <string.h>

void myfunction(char *q)
{
    memcpy(q, "hello", 6); // copy 'h','e','l','l','o','\0'
}

int main(void)
{
    char p[6]; // buffer for "hello" + '\0'
    myfunction(p);
    printf("%s\n", p);
    return 0;

    // or use malloc and free
    /*
        char *p = malloc(6);
        if (p) {
            myfunction(p);
            printf("%s\n", p);
            free(p);
        }
        return 0;
    */
}

// build command:
// gcc -o ex1 ex1.c
// run command:
// ./ex1