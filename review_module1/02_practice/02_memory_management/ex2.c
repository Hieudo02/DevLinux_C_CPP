// Where are the variables allocated?

#include <stdio.h>
#include <stdlib.h>

int a;
char *b;
const char c[20] = "I am a string";

void func(char d, int c_param, char *f)
{
    int g = 0;
    static int h = 2;
    char *i = NULL;
    i = (char *)malloc(20);
    if (i != NULL)
    {
        free(i);
    }
}

/*
## Globals / file-scope objects
- int a;
    + Storage duration: static (exists for the whole program).
    + Linkage/scope: file scope.
    + Memory region: .bss (zero-initialized data in RAM).
    + Initialization: implicitly 0.

- char *b;
    + Storage duration: static.
    + Memory region: .bss.
    + Initialization: implicitly NULL (0). Note: this allocates no pointed-to memory; it’s just a pointer variable.

- const char c[20] = "I am a string";
    + Type: a fixed-size array, not a pointer.
    + Storage duration: static.
    + Memory region: typically .rodata (read-only data in ROM/flash); some toolchains may place it in .data but keep it read-only.
    + Initialization: contains "I am a string\0" and padding to 20 bytes. Contents are not writable because of const

## Inside func
=> Parameters and locals (except static) have automatic storage and live on the stack while the function runs.
- Parameters: char d, int c_param, char *f
    + Storage duration: automatic.
    + Memory region: stack.
    + Each is a copy of the caller’s arguments (for f, it’s a copy of the pointer value).
- int g = 0;
    + Storage duration: automatic.
    + Memory region: stack.
    + Reinitialized to 0 on every call.
- static int h = 2;
    + Storage duration: static (persists across calls).
    + Memory region: .data (because it has a nonzero initializer; if it were = 0, it would likely be .bss).
    + Initialization: initialized to 2.
- char *i = NULL;
    + Storage duration: automatic (the pointer itself is on the stack).
    + Memory region: stack.
    + Initialized to NULL.
- i = (char *)malloc(20);
    + i = malloc(20); allocates 20 bytes on the heap and stores the returned address in i.
    + The allocated memory is in the heap region.
    + After malloc, i points to that heap block.
- free(i); releases that heap block. After free, i becomes a dangling pointer (best practice: set i = NULL; after freeing if the variable will be used again in the same scope).
*/

// Summary:
/*
    - a: Data segment (bss)
    - b: Data segment (bss)
    - c: Data segment (data)

    - d: Stack
    - c_param: Stack
    - f: Stack
    - g: Stack
    - h: Data segment (data)
    - i: Stack (pointer), Heap (allocated memory)
    (Khi khởi tạo biến con trỏ i với NULL, bản thân biến con trỏ i được cấp phát trên ngăn xếp (stack), còn vùng nhớ mà nó trỏ tới là NULL, tức là không trỏ tới vùng nhớ hợp lệ nào cả. 
    Khi sau đó sử dụng malloc để cấp phát bộ nhớ, vùng nhớ mới được cấp phát nằm trên heap, và con trỏ i sẽ trỏ tới vùng nhớ này.)
*/