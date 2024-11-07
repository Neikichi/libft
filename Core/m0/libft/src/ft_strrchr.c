#include "libft.h"

/// @brief Locate the last occurrence of a character in a string
/// 
/// This function searches for the last occurrence of the character `c` in the string `s`.
/// The terminating null byte is considered part of the string, so if `c` is `\0`,
/// the function returns a pointer to the null byte at the end of `s`.
/// 
/// @param s The string to be searched
/// @param c The character to be located (converted to `char`)
/// @return A pointer to the last occurrence of the character `c` in the string,
///         or `NULL` if the character is not found
char *ft_strrchr(const char *s, int c)
{
    char *ptr;

    ptr = NULL;
    while (*s)
    {
        if (*s == (char)c)
            ptr = (char *)s;
        s++;
    }
    if ((char)c == '\0')
        return ((char *)s);
    return (ptr);
}


#include <stdio.h> // For testing purposes
#include <string.h> // For comparison with standard strrchr

int main(void)
{
    // Test case 1: Character appears multiple times
    const char *str1 = "Hello, world!";
    char *result1 = ft_strrchr(str1, 'o');
    printf("ft_strrchr result: %s\n", result1 ? result1 : "NULL");  // Expected: "orld!"

    // Test case 2: Character appears only once
    const char *str2 = "Hello, world!";
    char *result2 = ft_strrchr(str2, 'H');
    printf("ft_strrchr result: %s\n", result2 ? result2 : "NULL");  // Expected: "Hello, world!"

    // Test case 3: Character not found
    const char *str3 = "Hello, world!";
    char *result3 = ft_strrchr(str3, 'z');
    printf("ft_strrchr result: %s\n", result3 ? result3 : "NULL");  // Expected: NULL

    // Test case 4: Null terminator search
    const char *str4 = "Hello, world!";
    char *result4 = ft_strrchr(str4, '\0');
    printf("ft_strrchr result for null terminator: %s\n", result4 ? result4 : "NULL");  // Expected: ""

    // Test case 5: Compare with standard strrchr
    const char *str5 = "Hello, world!";
    char *std_result = strrchr(str5, 'o');
    printf("Standard strrchr result: %s\n", std_result ? std_result : "NULL");  // Expected: "orld!"

    return 0;
}