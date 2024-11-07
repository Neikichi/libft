#include "libft.h"

/// @brief Calculate the length of a string
/// 
/// This function counts the number of characters in the string `str`
/// until the null terminator is encountered.
/// 
/// @param str The input string whose length is to be calculated
/// @return The length of the input string (excluding the null terminator)
size_t ft_strlen(const char *str)
{
    size_t count;

    count = 0;
    while (*str)
    {
        count++;
        str++;
    }
    return (count);
}

#include <stdio.h> // For testing purposes
#include <string.h> // For comparison with standard strlen

int main(void)
{
    // Test case 1: Normal string
    const char *str1 = "Hello, world!";
    size_t len1 = ft_strlen(str1);
    printf("ft_strlen(\"%s\") = %zu\n", str1, len1);  // Expected: 13

    // Test case 2: Empty string
    const char *str2 = "";
    size_t len2 = ft_strlen(str2);
    printf("ft_strlen(\"%s\") = %zu\n", str2, len2);  // Expected: 0

    // Test case 3: String with spaces
    const char *str3 = "   Leading and trailing spaces   ";
    size_t len3 = ft_strlen(str3);
    printf("ft_strlen(\"%s\") = %zu\n", str3, len3);  // Expected: 34

    // Test case 4: Compare with standard strlen
    size_t std_len1 = strlen(str1);
    printf("Standard strlen(\"%s\") = %zu\n", str1, std_len1);  // Expected: 13

    return 0;
}