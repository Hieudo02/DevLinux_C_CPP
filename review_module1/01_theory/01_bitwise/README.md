# Bitwise Operations in C

This repository contains a single C program, **`bitwise.c`**, that demonstrates some common bitwise techniques with clear, runnable examples and console output. It is designed for quick study, revision, or onboarding teammates who are new to low‑level C manipulation.

## Table of Contents
- [What’s inside](#whats-inside)
- [Build](#build)
- [Run](#run)
- [Quick reference (the 15 patterns)](#quick-reference-the-15-patterns)
- [Sample output (abridged)](#sample-output-abridged)
- [Notes and portability](#notes-and-portability)

---

## What’s inside

`bitwise.c` defines small, focused functions and calls them from `main()` so you can compile once and see everything run. Each function prints before/after values and comments explain the logic and truth tables.

---

## Build

Compile with GCC/Clang from the repository root:

```bash
gcc -O0 -g -Wall -Wextra -o bitwise_demo bitwise.c
```

- `-O0` keeps code easy to debug and avoids optimizing out variables.
- `-g` includes debug symbols for use with `gdb` if needed.
- `-Wall -Wextra` enables useful warnings.

---

## Run

```bash
./bitwise_demo
```

You should see a sequence of sections showing each technique and its results.

---

## Quick reference (the 15 patterns)

Below is a concise summary of each technique demonstrated in `bitwise.c` and the core expression used.

1. **Set bit _n_**  
   Set a specific bit to 1:  
   ```c
   x |= (1 << n);
   ```

2. **Clear bit _n_**  
   Clear a specific bit to 0:  
   ```c
   x &= ~(1 << n);
   ```

3. **Toggle bit _n_**  
   Flip a bit:  
   ```c
   x ^= (1 << n);
   ```

4. **Test bit _n_**  
   Check if bit is set:  
   ```c
   if (x & (1 << n)) { /* set */ }
   ```

5. **Swap two integers (XOR swap)**  
   Swap without a temp variable:  
   ```c
   a ^= b; b ^= a; a ^= b;
   ```

6. **Is power of two**  
   True if exactly one bit is set (and x != 0):  
   ```c
   (x != 0) && ((x & (x - 1)) == 0)
   ```

7. **Count set bits (Brian Kernighan)**  
   Clear the least‑significant 1 each iteration:  
   ```c
   while (n) { n &= (n - 1); count++; }
   ```
   (Optionally, `__builtin_popcount` on GCC/Clang.)

8. **Even or odd**  
   ```c
   (x & 1) == 0  // even
   (x & 1) != 0  // odd
   ```

9. **Two’s complement**  
   Negation via bitwise:  
   ```c
   -x == (~x + 1)
   ```

10. **Compare without relational operators**  
    ```c
    (a ^ b) == 0  // equal
    ```

11. **Find MSB position**  
    Shift until only the highest bit remains; return index (0‑based).

12. **Find LSB position**  
    Shift right until `(x & 1)` becomes 1; return index (0‑based).

13. **Turn off rightmost 1**  
    ```c
    x &= (x - 1);
    ```

14. **Isolate rightmost 1**  
    ```c
    x & -x;
    ```

15. **Multiple of 8**  
    Last three bits must be 0:  
    ```c
    (x & 7) == 0;
    ```

---

## Sample output (abridged)

> Actual output will include binary/hex prints before and after each operation.

```
The value of x before setting bit 3: 0x 0 0 0 0 0 0 0 0
The value of x after  setting bit 3: 0x 0 0 0 0 1 0 0 0

The value of x before clearing bit 3: 0x f f f f f f f f
The value of x after  clearing bit 3: 0x f f f f f 0 f f

Before swap: x = 5, y = 10
After  swap: x = 10, y = 5

16 is a power of 2
18 is not a power of 2

Binary representation of 29: 0b00011101
Number of set bits in 29 = 4

4 is even

The 2's complement of 121 is -121

The Most Significant Bit (MSB) of 2 is at position 1
The Least Significant Bit (LSB) of 8 is at position 3
```

---

## Notes and portability

- Shifts like `(1 << n)` assume `n` is within the width of the type. Shifting by or past the width is **undefined behavior** in C.  
- Prefer unsigned types for bit operations where possible (`unsigned`, `uint32_t`, etc.).  
- For fixed width across platforms, include `<stdint.h>` and use `uint8_t`, `uint32_t`, etc.

---
