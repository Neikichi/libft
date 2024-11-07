#include "libft.h"
#include <stdlib.h>

/// @brief Create a substring from a given string
/// 
/// This function creates a substring from the string `s`, starting at index `start`
/// and containing up to `len` characters. If `start` is greater than the length of `s`,
/// the function returns an empty string.
/// 
/// @param s The original string from which the substring will be created
/// @param start The starting index of the substring in `s`
/// @param len The maximum length of the substring
/// @return A pointer to the newly created substring, or `NULL` if allocation fails
char *ft_substr(char const *s, unsigned int start, size_t len)
{
    char *buffer;
    unsigned int i;

    i = 0;
    buffer = malloc(sizeof(char) * len + 1);
    if (!buffer)
        return (NULL);
    ft_strlcpy(buffer, &s[start], len + 1);
    // buffer[i] = '\0';
    return (buffer);
}


#include <stdio.h>  // For testing purposes

int main(void)
{
    // Test case 1: Normal substring extraction
    const char *str1 = "Hello, world!";
    char *result1 = ft_substr(str1, 7, 5);
    if (result1)
    {
        printf("ft_substr result: '%s'\n", result1);  // Expected: "world"
        free(result1);
    }

    // Test case 2: Start beyond the string length
    const char *str2 = "Hello, world!";
    char *result2 = ft_substr(str2, 20, 5);
    if (result2)
    {
        printf("ft_substr result (start beyond length): '%s'\n", result2);  // Expected: ""
        free(result2);
    }

    // Test case 3: Extract substring longer than remaining characters
    const char *str3 = "Hello, world!";
    char *result3 = ft_substr(str3, 7, 20);
    if (result3)
    {
        printf("ft_substr result (len greater than remaining): '%s'\n", result3);  // Expected: "world!"
        free(result3);
    }

    // Test case 4: Empty string as input
    const char *str4 = "";
    char *result4 = ft_substr(str4, 0, 5);
    if (result4)
    {
        printf("ft_substr result (empty input): '%s'\n", result4);  // Expected: ""
        free(result4);
    }

    return 0;
}