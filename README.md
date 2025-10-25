# Command-Line Arguments in C (with GDB)

This repository contains three small C programs demonstrating how **command-line arguments** (`argc`/`argv`) work and how to **pass arguments to a program under GDB** on Linux.

## Table of Contents
- [Files](#files)
- [Build](#build)
- [Run](#run)
- [Debug with GDB (pass arguments)](#debug-with-gdb-pass-arguments)
- [Sample Outputs](#sample-outputs)
- [Common Pitfalls](#common-pitfalls)
- [Push to GitHub](#push-to-github)
- [References](#references)

---

## Files

- **01_print_command_line_arguments.c**  
  Prints the number of arguments and lists every item in `argv` (including `argv[0]`, the program name).

- **02_demo_working_of_command_line_arguments.c**  
  Demonstrates branching by `argc`, accessing `argv[0]`, and iterating through `argv[i]` for detailed output.

- **03_pass_command_line_arguments_to_gdb.c**  
  Expects **exactly two** arguments and is intended to be run both normally and from within **GDB** to practice passing arguments via `run`.

> All examples are intended to be compiled with debug info (`-g`) for use with GDB.

---

## Build

From the repository root:

```bash
# Example 1
gcc -O0 -g -o print_command_line_arguments 01_print_command_line_arguments.c

# Example 2
gcc -O0 -g -o demo_working_of_command_line_arguments 02_demo_working_of_command_line_arguments.c

# Example 3
gcc -O0 -g -o pass_command_line_arguments_to_gdb 03_pass_command_line_arguments_to_gdb.c
```

> Notes:
> - `-O0` disables optimizations for clearer debugging.
> - `-g` embeds debug symbols so GDB can show line numbers, variables, etc.

---

## Run

```bash
# Example 1
./print_command_line_arguments arg1 arg2 arg3

# Example 2
./demo_working_of_command_line_arguments arg1 arg2 arg3

# Example 3 (requires exactly 2 arguments)
./pass_command_line_arguments_to_gdb Hello World
```

---

## Debug with GDB (pass arguments)

Using the **third** program as an example:

```bash
gdb ./pass_command_line_arguments_to_gdb

(gdb) break main          # optional: stop at main
(gdb) run Hello World     # pass two arguments to the program
# when stopped at a breakpoint:
(gdb) next                # step over
(gdb) step                # step into
(gdb) print argc          # inspect variables
(gdb) print argv[1]
(gdb) info locals
(gdb) backtrace           # show call stack
(gdb) list                # show source around current line
(gdb) quit
```

> Tip: You can also preconfigure arguments via:
> ```
> (gdb) set args Hello World
> (gdb) run
> ```

---

## Sample Outputs

**Example 1**
```
You have entered 4 arguments:
./print_command_line_arguments
arg1
arg2
arg3
```

**Example 2**
```
Program name is: ./demo_working_of_command_line_arguments
Number Of Arguments Passed: 4
----Following Are The Command Line Arguments Passed----
argv[0]: ./demo_working_of_command_line_arguments
argv[1]: arg1
argv[2]: arg2
argv[3]: arg3
```

**Example 3 (exactly two arguments)**
```
$ ./pass_command_line_arguments_to_gdb Hello World
Argument 1: Hello
Argument 2: World
```
If missing/extra arguments:
```
Usage: ./pass_command_line_arguments_to_gdb <arg1> <arg2>
```

---

## Common Pitfalls

- Forgetting that `argv[0]` is the **program name**. Your first *user* argument starts at `argv[1]`.
- Accessing `argv[i]` without checking `argc` first can cause **out-of-bounds** reads.
- Compiling **without** `-g` makes GDB much less informative.
- Using aggressive optimizations may cause variables to be optimized out or re-ordered—use `-O0` when learning/debugging.

---

## References

- GeeksforGeeks — **Command Line Arguments in C/C++**  
  https://www.geeksforgeeks.org/cpp/command-line-arguments-in-c-cpp/

- GeeksforGeeks — **How to Pass Command Line Arguments to GDB in a Linux Environment**  
  https://www.geeksforgeeks.org/linux-unix/how-to-pass-command-line-arguments-to-gdb-in-a-linux-environment/
