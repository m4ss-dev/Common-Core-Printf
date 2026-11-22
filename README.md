*This activity has been created as part of the 42 curriculum by ydames.*

<div align="center">
  <h1>🖨️ ft_printf</h1>
  <p><b>Because <code>ft_putnbr()</code> and <code>ft_putstr()</code> aren't enough.</b></p>

  <p>
    <img src="[https://img.shields.io/badge/Language-C-blue?style=for-the-badge&logo=c](https://img.shields.io/badge/Language-C-blue?style=for-the-badge&logo=c)" alt="C Language" />
    <img src="[https://img.shields.io/badge/Norminette-Passing-success?style=for-the-badge](https://img.shields.io/badge/Norminette-Passing-success?style=for-the-badge)" alt="Norminette" />
    <img src="[https://img.shields.io/badge/School-42-black?style=for-the-badge](https://img.shields.io/badge/School-42-black?style=for-the-badge)" alt="42 School" />
  </p>
</div>

---

## 📖 Description

**ft_printf** is a foundational project in the 42 curriculum whose goal is to recode the famous `printf()` function from the C standard library (`libc`)[cite: 6, 8]. 

Through this project, the main objective is to discover and master **variadic functions** in C (`va_start`, `va_arg`, `va_copy`, `va_end`) while building a clean, modular, and extensible codebase that can later be integrated directly into `libft` for future 42 C projects[cite: 4, 8].

### Supported Conversions

Unlike the original `printf()`, this implementation does not handle internal buffer management[cite: 8], and focuses on the following format specifiers[cite: 8, 9]:

| Specifier | Output Format | Type |
| :---: | :--- | :--- |
| **`%c`** | Prints a single character[cite: 9] | `int` (promoted from `char`) |
| **`%s`** | Prints a string (standard C convention)[cite: 9] | `char *` |
| **`%p`** | Prints a `void *` pointer address in hexadecimal format[cite: 9] | `void *` |
| **`%d`** | Prints a signed decimal (base 10) number[cite: 9] | `int` |
| **`%i`** | Prints a signed integer in base 10[cite: 9] | `int` |
| **`%u`** | Prints an unsigned decimal (base 10) number[cite: 9] | `unsigned int` |
| **`%x`** | Prints a number in lowercase hexadecimal (base 16)[cite: 9] | `unsigned int` |
| **`%X`** | Prints a number in uppercase hexadecimal (base 16)[cite: 9] | `unsigned int` |
| **`%%`** | Prints a literal percent sign (`%`)[cite: 9] | *None* |

---

## ⚙️ Instructions

### Compilation

The project includes a `Makefile` compliant with the 42 Norm (compiling with `cc` and the `-Wall -Wextra -Werror` flags without relinking)[cite: 5]. It uses `ar` to generate the static library `libftprintf.a` at the root of the repository[cite: 8].

1. **Clone the repository:**
   ```bash
   git clone git@github.com:42learners/Common-Core---Printf-4e0651bf-7f54-4218-8c34-cf33030a590e.git ft_printf
   cd ft_printf
   ```

2. **Compile the library:**
   ```bash
   make
   ```

3. **Available Makefile rules[cite: 5, 8]:**
   * `make` or `make all`: Compiles the source files and creates `libftprintf.a`.
   * `make clean`: Removes object files (`.o`).
   * `make fclean`: Removes object files and `libftprintf.a`.
   * `make re`: Performs a full recompilation (`fclean` followed by `all`).

### Usage & Execution

To use `ft_printf` in your C code, include the header `"ft_printf.h"`[cite: 8] and link `libftprintf.a` during compilation:

```c
#include "ft_printf.h"

int main(void)
{
    int count;

    count = ft_printf("Hello %s! Number: %d | Hex: %x | Ptr: %p\n", "42", 42, 42, &count);
    ft_printf("Total characters printed: %d\n", count);
    return (0);
}
```

Compile your test program with the library:
```bash
cc -Wall -Wextra -Werror main.c libftprintf.a -o test_printf
./test_printf
```

---

## 🧠 Algorithm & Data Structure

### Algorithm Design: Sequential Parsing & Dispatching
`ft_printf` processes the format string linearly in a single pass ($O(n)$ time complexity, where $n$ is the length of the format string):
1. **Initialization:** A `va_list` is initialized using `va_start` to access the variable arguments passed after `const char *format`[cite: 8].
2. **String Traversal:** The function iterates character by character through `format`.
   * If the current character is not `%`, it is written directly to standard output (`fd = 1`) via `write()`, incrementing the total printed character counter[cite: 8].
   * When a `%` is encountered, the parser inspects the very next character (`format[i + 1]`) and routes execution to a dedicated conversion handler function.
3. **Recursive Base Conversion:** For numeric conversions (`%d`, `%i`, `%u`, `%x`, `%X`, and `%p`), a recursive division-modulo algorithm (`n / base` and `n % base`) is used. Recursion naturally prints digits from the most significant to the least significant without needing dynamic heap allocation (`malloc`), preventing memory leaks and avoiding unnecessary buffer overhead[cite: 5, 8].
4. **Edge-Case Handling:** Special cases such as `INT_MIN` (`-2147483648`), `NULL` strings (`"(null)"`), and `NULL` pointers (`"(nil)"` or `"0x0"` depending on system behavior) are explicitly handled to match the standard `printf()` output[cite: 8].
5. **Cleanup:** `va_end` is called before returning the total count of printed characters[cite: 8].

### Data Structure Justification
* **No Complex Heap Structures:** Because the subject explicitly specifies *not* to implement the buffer management of the original `printf()`[cite: 8], storing tokens or formatted substrings in linked lists or dynamic arrays was avoided.
* **Lightweight State (`va_list` + `int` counter):** Relying solely on C's standard `va_list` structure and a local integer accumulator keeps memory usage at $O(1)$ stack space, eliminates the risk of heap fragmentation or leaks, and keeps the code strictly compliant with the 42 Norm (short, single-responsibility functions under 25 lines)[cite: 5].

---

## 📚 Resources

### Classic References
* **Linux Manual Pages:** `man 3 printf` and `man 3 stdarg` — Official documentation on format specifiers, return values, and variadic macros (`va_start`, `va_arg`, `va_end`)[cite: 8].
* **The C Programming Language (K&R):** Chapter 7 (*Input and Output*) — Reference on variable-length argument lists and formatted output design.
* **42 Docs & Peer Discussions:** Community guides and peer-to-peer code reviews regarding edge cases (`NULL` pointers, unsigned integer overflows, and hexadecimal formatting).

### AI Usage Disclosure
* **No AI tools were used** during the design, coding, debugging, or testing of this project. All logic, edge-case handling, and code structure were written manually through documentation reading and peer-learning exchanges[cite: 6, 7, 10].