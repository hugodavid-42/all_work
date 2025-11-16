# Common Core - Libft

_This project has been created as part of the 42 curriculum by <hugodavid-42>hdavid_

## 📝 Description

Libft is an individual project at 42 that requires students to re-implement a collection of standard C library functions, along with creating additional utility functions. This custom library serves as a foundational toolkit that will be utilized and expanded throughout subsequent projects in the 42 program.

The project covers essential functions from string manipulation, memory management, character classification, and data conversion, providing a deeper understanding of how these fundamental operations work at the implementation level.

## 🛠️ Instructions

The project uses a Makefile to compile all source files into a static library (`libft.a`). Each function is implemented in its own `.c` file following standard conventions.

**Build commands:**
- `make` - Compiles the library
- `make clean` - Removes object files
- `make fclean` - Removes object files and the library
- `make re` - Recompiles the entire project

# 📋 Liste des Fonctions Libft

## 🧩 Partie 1 - Fonctions standards Libc

### Caractères
- `ft_isalpha` - checks for an alphabetic character.
- `ft_isdigit` - check for a digit (0 through 9).
- `ft_isalnum` - checks for an alphanumeric character.
- `ft_isascii` - checks whether c fits into the ASCII character set.
- `ft_isprint` - checks for any printable character.
- `ft_toupper`	- convert char to uppercase.
- `ft_tolower`	- convert char to lowercase.

### Chaînes de caractères
- `ft_strlen` - calculate the length of a string.
- `ft_strchr` - Recherche caractère
- `ft_strrchr` - Recherche depuis la fin
- `ft_strncmp` - Comparaison de chaînes
- `ft_strnstr` - locate a substring in a string.
- `ft_strlcpy` - copy string to a specific size.
- `ft_strlcat` - concatenate a string to a specific size.

### Mémoire
- `ft_memset` - fill memory with a constant byte.
- `ft_bzero` - zero a byte string.
- `ft_memcpy` - copy memory area.
- `ft_memmove` - copy memory area.
- `ft_memchr` - scan memory for a character.
- `ft_memcmp` - compare memory areas.

### Conversion
- `ft_atoi` - convert a string to an integer.

### Allocation
- `ft_calloc` - allocates memory and sets its bytes' values to 0.
- `ft_strdup` - creates a duplicate for the string passed as a parameter.

## 🚀 Partie 2 - Fonctions supplémentaires

- `ft_substr` - returns a substring from a string.
- `ft_strjoin` - concatenates two strings.
- `ft_strtrim` - trims the beginning and end of a string with a specific set of chars.
- `ft_split` - splits a string using a char as parameter.
- `ft_itoa` - converts a number into a string.
- `ft_strmapi` - applies a function to each character of a string.
- `ft_striteri` - applies a function to each character of a string.
- `ft_putchar_fd` - output a char to a file descriptor.
- `ft_putstr_fd` - output a string to a file descriptor.
- `ft_putendl_fd` - output a string to a file descriptor, followed by a new line.
- `ft_putnbr_fd` - output a number to a file descriptor.

## 🔗 Partie 3 - Listes chaînées

- `ft_lstnew` - creates a new list element.
- `ft_lstadd_front` - adds an element at the beginning of a list.
- `ft_lstsize` - counts the number of elements in a list.
- `ft_lstlast` - returns the last element of the list.
- `ft_lstadd_back` - adds an element at the end of a list.
- `ft_lstdelone` - deletes and free list.
- `ft_lstclear` - deletes and free list.
- `ft_lstiter` - applies a function to each element of a list.
- `ft_lstmap` - applies a function to each element of a list.

## 📚 Resources

**Documentation references used during development:**
- [GeeksforGeeks](https://www.geeksforgeeks.org/) - Algorithm explanations and examples
- [KooR.fr](https://koor.fr/) - C programming tutorials and references
- [IBM Documentation](https://www.ibm.com/docs/fr) - Technical specifications and standards

**🔧 Standard Library Headers Utilized:**
- `<stdlib.h>` - Memory allocation and process control
- `<stdint.h>` - Fixed-width integer types
- `<limits.h>` - Implementation-defined constants and limits

