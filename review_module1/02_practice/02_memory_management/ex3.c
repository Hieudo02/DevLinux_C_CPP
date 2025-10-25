// Where are "a" and "b" allocated and stored?

void main(void)
{
    char a[4] = "foo";
    char *b = "bar";
}

/*
- "a" is allocated on the stack:
    + Storage duration: automatic (lives until the function returns). // Khi hàm main() kết thúc, vùng nhớ cho "a" sẽ được giải phóng.
    + Memory region: stack.
    + It is a local array variable initialized with the string "foo\0".

- "b" is allocated in the read-only data segment:
    + Storage duration: static (exists for the whole program). // "b" tồn tại trong suốt thời gian chạy của chương trình.
    + Memory region: .rodata (read-only data in ROM/flash).
    + It points to the string literal "bar", which is stored in a read-only section.

## Difference between char a[4] and char *b:
    - "a" is an array variable that allocates space for 4 characters on the stack, and its contents can be modified.
    - "b" is a pointer variable that points to a string literal in read-only memory; attempting to modify the contents of "bar" via "b" would lead to undefined behavior.
    (But "b" can be made to point to a different string literal.)

- Example:
    a[0] = 'F'; // valid, modifies the first character of "a"
    b[0] = 'B'; // invalid, leads to undefined behavior (attempting to modify read-only memory)

    b = "baz"; // valid, changes pointer "b" to point to a different string literal
*/