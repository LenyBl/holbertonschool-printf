![texte alternatif](flowchart/flowchart-printf.png)

--

# holbertonschool-printf

A custom implementation of the C `printf` function, written as part of the Holberton curriculum.

## Description

The project aims to recreate the standard `printf` function.  
The `_printf` function prints formatted text by interpreting various *format specifiers*.

## Prototype

```c
int _printf(const char *format, ...);
```

## Supported Specifiers

| Specifier | Description |
|-----------|-------------|
| `%c` | Prints a character |
| `%s` | Prints a string |
| `%d`, `%i` | Prints a signed integer |
| `%%` | Prints the `%` symbol |

## Example Usage

```c
#include "main.h"

int main(void)
{
    _printf("Hello, world!\n");
    _printf("Number: %d, String: %s, Char: %c, Percent: %%\n", 42, "Test", 'A');
    return (0);
}
```

## Compilation

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o printf
```

## Project Structure

- `main.h` — Prototypes and includes  
- `_printf.c` — Main function implementation  
- `utils/` — Helper functions  
- `man_3_printf` — Manual page (if included)

## Constraints

- No global variables  
- Must use the required GCC flags  
- Must follow the required coding style  

## Author

LenyBl and ZimEthane

## License

This project may be freely used and modified.
