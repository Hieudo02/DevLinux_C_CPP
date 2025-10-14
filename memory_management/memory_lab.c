#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void stack_overflow() {
    printf("Attempting to cause a stack overflow...\n");
    char buffer[10];
    snprintf(buffer, sizeof(buffer), "%s", "A very long string that exceeds the buffer size...");

    // Intentionally cause a stack overflow by recursive calls 
    stack_overflow();
}

void memory_leak() {
    printf("Allocating memory without freeing it...\n");
    for (int i = 0; i < 1000000; i++) {
        char *leak = (char *)malloc(1024 * 1024); // Allocate 1MB
        if (leak == NULL) {
            printf("Memory allocation failed\n");
            return;
        }
        // Intentionally not freeing the allocated memory
    }
}

void out_of_memory() {
    printf("Attempting to allocate a large amount of memory...\n");
    size_t size = (size_t)-1; // Requesting an extremely large size
    char *ptr = (char *)malloc(size);
    if (ptr == NULL) {
        printf("Memory allocation failed as expected\n");
    } else {
        printf("Unexpectedly allocated memory\n");
        free(ptr);
    }
}

void main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <option>\n", argv[0]);
        printf("Options:\n");
        printf("  stack_overflow - Cause a stack overflow\n");
        printf("  memory_leak    - Cause a memory leak\n");
        printf("  out_of_memory  - Attempt to allocate too much memory\n");
        return;
    }

    if (strcmp(argv[1], "stack_overflow") == 0) {
        stack_overflow();
    } else if (strcmp(argv[1], "memory_leak") == 0) {
        memory_leak();
    } else if (strcmp(argv[1], "out_of_memory") == 0) {
        out_of_memory();
    } else {
        printf("Unknown option: %s\n", argv[1]);
    }
}

// how to build
// gcc -o memory_lab memory_lab.c

// how to run
// ./memory_lab stack_overflow
// ./memory_lab memory_leak
// ./memory_lab out_of_memory