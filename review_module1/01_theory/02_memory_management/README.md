# C/C++ Memory Layout — Practical Guide

This README explains the typical memory segments in C/C++ programs and embedded firmware (e.g., STM32/ESP32). It focuses on what lives where, how startup works, and common pitfalls.

---

## 1) Big Picture

A compiled program is organized by the **linker** into named **sections/segments**. On desktops, these map into process’s virtual memory; on microcontrollers, they map to real **Flash/ROM** and **SRAM**.

Common segments:

- **.text** – machine instructions (code)
- **.rodata** – read‑only constants (string literals, lookup tables)
- **.data** – initialized globals/statics (non‑zero initial value)
- **.bss** – zero‑initialized or uninitialized globals/statics
- **Heap** – dynamic allocations (`malloc/new`)
- **Stack** – per‑thread/task call frames and local (automatic) variables

---

## 2) Details

### .text (Code) — usually in ROM/Flash
- **What lives here?** Compiled functions/instructions.
- **Access:** Read‑only + executable.
- **Embedded note:** Often stored in Flash. Certain platforms allow/require placing time‑critical ISRs in fast internal RAM (e.g., ESP32 `IRAM`, Cortex‑M ITCM).

### .rodata (Read‑Only Data) — ROM/Flash
- **What lives here?** Compile‑time constants: string literals, `const` global tables.
- **Access:** Read‑only.
- **Embedded note:** Big constant tables stay in Flash; on some MCUs may need attributes/pragmas to ensure they don’t get copied into RAM.

### .data (Initialized Data) — RAM at runtime (image stored in ROM)
- **What lives here?** Global/static variables **with non‑zero initializers** (e.g., `int x = 42;`).
- **Startup:** Copied from Flash to RAM during reset/startup so variables begin with the right values.
- **Cost:** Consumes **RAM** at runtime and **Flash** for the initial image.

### .bss (Zero/Uninitialized Data) — RAM
- **What lives here?** Global/static variables **without** an explicit initializer, or initialized to zero.
- **Startup:** Cleared to zero during reset/startup.
- **Benefit:** No Flash storage for contents (saves ROM), but still consumes RAM.

### Heap — RAM (dynamic)
- **What lives here?** Memory requested via `malloc/new`; released with `free/delete`.
- **When to use:** Variable‑sized data, lifetime managed at runtime.
- **Embedded cautions:** Fragmentation, out‑of‑memory, and nondeterministic timing. Prefer fixed pools/arenas for real‑time code.

### Stack — RAM (per thread/task)
- **What lives here?** Function call frames, return addresses, saved registers, local variables (without `static`).
- **Behavior:** Grows/shrinks with calls/returns; each RTOS task has its own stack.
- **Embedded cautions:** Overflows are common failure modes. Avoid large local arrays and deep recursion in tight‑memory systems.

---

## 3) Quick Rules for Where Things Go

- **Local variables (no `static`)** → **Stack**  
- **`static` or global with non‑zero initializer** → **.data**  
- **`static` or global with zero/no initializer** → **.bss**  
- **`const` globals / string literals** → **.rodata**  
- **`malloc/new`** → **Heap**

> C++ note: Global/static objects with constructors also rely on init tables; the runtime calls their constructors before `main()`.

---

## 4) What Happens at Reset (Embedded Startup)

1. CPU jumps to **Reset/Startup** code.
2. **.bss** is **zeroed**.
3. **.data** is **copied** from Flash image to RAM.
4. **C++ static constructors** (if any) run.
5. `main()` is called.

This sequence explains why `.data` consumes both Flash (for the image) and RAM (for runtime storage), whereas `.bss` only consumes RAM and is cheaper in Flash.

---

## 5) Platform Notes (STM32/ESP32)

- **Cortex‑M (STM32):**  
  - May have small, fast RAMs (ITCM/DTCM/CCM). Link critical code/data there with section attributes + linker script.  
  - Vector table sits in Flash by default; can be remapped to RAM if needed.

- **ESP32/ESP32‑S3:**  
  - Distinguish **IRAM** (instruction RAM) and **DRAM** (data RAM). Place time‑critical ISRs in IRAM; critical data in DRAM.  
  - Large `const` tables and strings live in `.rodata` (Flash) and are cache‑fetched; avoid Flash access in contexts where the cache may be off.

---

## 6) Basic, Concrete Examples

- A **string literal** like `"Hello"` → **.rodata** (Flash).  
- A **lookup table** declared as `const` → **.rodata**.  
- A **global counter** with `= 0` or no initializer → **.bss** (zeroed).  
- A **global threshold** with `= 42` → **.data** (copied to RAM at boot).  
- A **temporary buffer** declared inside a function → **Stack**.  
- A **buffer allocated at runtime** with `malloc/new` → **Heap**.

---

## 7) Common Pitfalls & How to Avoid Them

- **Hidden RAM bloat:** Large non‑zero initialized globals land in **.data** and cost both Flash + RAM. Prefer zero‑init (→ `.bss`) or place in external memory when available.
- **Stack overflows:** Big local arrays or recursion. Move large buffers to static/global or use heap/pools; enable stack guards/watermarks.
- **Heap fragmentation:** Many small dynamic allocations over time. Use fixed‑size pools/arenas, or avoid dynamic allocation in real‑time paths.
- **“Const” not really const:** Forgetting `const` can move tables from `.rodata` to `.data`, increasing RAM use.
- **Flash access in critical paths:** Some platforms temporarily disable caches/Flash access in ISRs or during flash writes. Keep critical code/data in fast RAM.

---

## 8) Inspecting Sizes (useful when tune memory)

- **Section sizes:** `size` / `arm-none-eabi-size` shows `.text`, `.data`, `.bss`.  
- **Symbol placement:** Linker **map file** (`.map`) shows where each symbol lives and its size.  
- **Disassembly/headers:** `objdump -h -d` to examine sections and addresses.  
- **RTOS tools:** Enable task stack watermarking and heap stats.

---

## 9) Conclusion

- **.text / .rodata** → Flash (ROM).  
- **.data / .bss / Heap / Stack** → RAM.  
- **Startup:** zero `.bss`, copy `.data`, run C++ static ctors, call `main()`.  
- Optimize RAM by keeping big data in `.bss` or in Flash when truly constant; watch stack and heap usage on embedded targets.
