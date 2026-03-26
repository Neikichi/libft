# libft — Extended C Library

> **42KL Core Project**

A comprehensive, custom C library built from scratch, extending the standard C library with utility functions for character classification, string manipulation, memory management, number conversion, linked lists, I/O, `ft_printf`, and `get_next_line`. This library is reused across all subsequent 42 projects.

---

## 📁 Project Structure

```
libft/
├── include/
│   └── libft.h          # All function prototypes, typedefs and macros
├── src/
│   ├── char/            # Character classification & conversion
│   ├── string/          # String manipulation
│   ├── memory/          # Memory functions
│   ├── number/          # Number/digit utilities
│   ├── io/              # File-descriptor I/O + get_next_line
│   ├── list/            # Singly-linked list operations
│   └── printf/          # ft_printf implementation
└── Makefile
```

---

## 📚 Function Reference

### Character Functions (`src/char/`)

| Function | Description |
|---|---|
| `ft_isalnum` | Checks if character is alphanumeric |
| `ft_isalpha` | Checks if character is alphabetic |
| `ft_isascii` | Checks if character is a valid ASCII character |
| `ft_isdigit` | Checks if character is a decimal digit |
| `ft_isprint` | Checks if character is printable |
| `ft_isupper` | Checks if character is uppercase |
| `ft_islower` | Checks if character is lowercase |
| `ft_isspace` | Checks if character is whitespace |
| `ft_tolower` | Converts character to lowercase |
| `ft_toupper` | Converts character to uppercase |

### String Functions (`src/string/`)

| Function | Description |
|---|---|
| `ft_strlen` | Returns length of a string |
| `ft_strchr` | Locates first occurrence of character in string |
| `ft_strrchr` | Locates last occurrence of character in string |
| `ft_strdup` | Duplicates a string (heap-allocated) |
| `ft_strlcpy` | Safe string copy with size limit |
| `ft_strlcat` | Safe string concatenation with size limit |
| `ft_strncmp` | Compares up to `n` characters of two strings |
| `ft_strnstr` | Locates substring within first `n` characters |
| `ft_strjoin` | Concatenates two strings into a new string |
| `ft_strtrim` | Trims characters from both ends of a string |
| `ft_substr` | Extracts a substring |
| `ft_split` | Splits a string by a delimiter into an array |
| `ft_striteri` | Applies function to each character (with index) |
| `ft_strmapi` | Creates new string applying function to each character |
| `ft_strlowercase` | Converts all characters to lowercase in-place |
| `ft_struppercase` | Converts all characters to uppercase in-place |

### Memory Functions (`src/memory/`)

| Function | Description |
|---|---|
| `ft_memset` | Fills memory with a constant byte |
| `ft_bzero` | Zeroes out a memory region |
| `ft_memcpy` | Copies memory from source to destination |
| `ft_memmove` | Copies memory, handling overlapping regions |
| `ft_memchr` | Scans memory for a byte |
| `ft_memcmp` | Compares two memory regions |
| `ft_calloc` | Allocates and zero-initialises memory |

### Number / Digit Functions (`src/number/`)

| Function | Description |
|---|---|
| `ft_atoi` | Converts ASCII string to integer |
| `ft_itoa` | Converts integer to string |
| `ft_itoa_u` | Converts unsigned long to decimal string |
| `ft_itoa_hex` | Converts unsigned long to hexadecimal string |
| `ft_countdigits` | Counts decimal digits in a signed integer |
| `ft_countdigits_u` | Counts decimal digits in an unsigned integer |
| `ft_countdigits_hex` | Counts hex digits in an unsigned integer |

### I/O Functions (`src/io/`)

| Function | Description |
|---|---|
| `ft_putchar_fd` | Writes a character to a file descriptor |
| `ft_putstr_fd` | Writes a string to a file descriptor |
| `ft_putendl_fd` | Writes a string followed by newline to fd |
| `ft_putnbr_fd` | Writes an integer to a file descriptor |
| `ft_putnstr_fd` | Writes first `n` characters of a string to fd |
| `ft_putnchar_fd` | Writes a character `n` times to a file descriptor |
| `get_next_line` | Reads one line at a time from a file descriptor |

### Linked List Functions (`src/list/`)

| Function | Description |
|---|---|
| `ft_lstnew` | Creates a new list node |
| `ft_lstadd_front` | Prepends a node to a list |
| `ft_lstadd_back` | Appends a node to a list |
| `ft_lstsize` | Returns the number of nodes in a list |
| `ft_lstlast` | Returns the last node of a list |
| `ft_lstdelone` | Deletes a single node using a given function |
| `ft_lstclear` | Deletes and frees an entire list |
| `ft_lstiter` | Applies a function to each node's content |
| `ft_lstmap` | Creates a new list by applying a function to each node |

### Printf (`src/printf/`)

A complete reimplementation of `printf` supporting the following conversion specifiers and flags:

| Specifier | Description |
|---|---|
| `%c` | Single character |
| `%s` | String |
| `%d` / `%i` | Signed decimal integer |
| `%u` | Unsigned decimal integer |
| `%x` / `%X` | Unsigned hexadecimal (lower/upper case) |
| `%p` | Pointer address |
| `%%` | Literal `%` character |

**Supported Flags:**

| Flag | Effect |
|---|---|
| `-` | Left-align output |
| `0` | Pad with zeros instead of spaces |
| `#` | Prefix `0x` / `0X` for hex |
| `+` | Always show sign |
| ` ` (space) | Prefix space for positive numbers |
| `*` | Width / precision from argument |

---

## 🔧 Data Structures

```c
/* Singly-linked list node */
typedef struct s_list {
    void          *content;
    struct s_list *next;
} t_list;

/* printf formatting control */
typedef struct s_flags {
    int   left_align;
    int   zero_pad;
    int   hash_hex;
    int   show_sign;
    int   space;
    int   width;
    int   precision;
    char  specifier;
    char *buffer;
} t_flags;
```

---

## 🛠️ Build

```bash
# Build the static library (libft.a)
make

# Build with bonus targets
make bonus

# Clean object files
make clean

# Full clean (including library)
make fclean

# Rebuild everything
make re
```

---

## 🚀 Usage

Include the header in your source file and link against the compiled library:

```c
#include "libft.h"
```

```bash
gcc -Wall -Wextra -Werror main.c -L. -lft -o my_program
```

---

## ⚙️ Configuration

`get_next_line` uses an internal buffer whose size is controlled at compile time:

```bash
# Default buffer size is 42
make CFLAGS="-DBUFFER_SIZE=128"
```

---

## 📝 Notes

- All heap-allocated strings are null-terminated.
- `ft_split` returns a `NULL`-terminated array of strings; all elements must be freed individually.
- `get_next_line` maintains a static internal buffer; call with `fd = -1` is handled gracefully.
- `ft_printf` returns the total number of characters written, matching the behaviour of the standard `printf`.
