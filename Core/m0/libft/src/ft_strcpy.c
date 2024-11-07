#include "libft.h"


/// @brief Copy a string to a destination buffer
/// 
/// This function copies the string `src` (including the terminating null byte)
/// to the buffer `dest`. The destination buffer must be large enough to receive
/// the entire string.
/// 
/// @param dest The destination buffer where the string is copied to
/// @param src The source string to be copied
/// @return A pointer to the destination buffer (`dest`)
char *ft_strcpy(char *dest, const char *src)
{
    char *ptr;

    ptr = dest;
    while (*src)
    {
        *ptr = *src;
        src++;
        ptr++;
    }
    *ptr = '\0';
    return (dest);
}

#include <stdio.h>  // For testing purposes
#include <string.h> // For comparison with standard strcpy

int main(void)
{
    // Test case: Copy a string to a new buffer
    char src[] = "Hello, world!";
    char dest[50];  // Make sure it's large enough to hold the source string

    char *result = ft_strcpy(dest, src);
    printf("ft_strcpy result: %s\n", result);  // Expected: Hello, world!

    // Test case: Compare with standard strcpy
    char std_dest[50];
    strcpy(std_dest, src);
    printf("Standard strcpy result: %s\n", std_dest);  // Expected: Hello, world!

    return 0;
}