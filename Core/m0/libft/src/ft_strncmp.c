#include "libft.h"

/// @brief Compare two strings up to a given number of characters
/// 
/// This function compares up to `n` characters of the strings `s1` and `s2`.
/// It returns an integer less than, equal to, or greater than zero if `s1`
/// is found, respectively, to be less than, to match, or to be greater than `s2`.
/// 
/// @param s1 The first string to be compared
/// @param s2 The second string to be compared
/// @param n The maximum number of characters to compare
/// @return The difference between the first differing characters, or `0` if no difference is found within `n` characters
int ft_strncmp(const char *s1, const char *s2, size_t n)
{
    size_t i;
    
    i = 0;
    if (n <= 0)
        return (0);
    while (i < n && s1[i] != '\0' && s2[i] != '\0')
    {
        if (s1[i] != s2[i])
            return (s1[i] - s2[i]);
        i++;
    }
    if (i != n)
        return (s1[i] - s2[i]);
    return (0);
}

#include <stdio.h> // For testing purposes
#include <string.h> // For comparison with standard strncmp

int main(void)
{
    // Test case 1: Strings are equal
    const char *str1 = "Hello";
    const char *str2 = "Hello";
    size_t n = 5;
    int result = ft_strncmp(str1, str2, n);
    printf("ft_strncmp result (equal strings): %d\n", result);  // Expected: 0

    // Test case 2: Strings differ within `n` characters
    const char *str3 = "Hello";
    const char *str4 = "Hellz";
    result = ft_strncmp(str3, str4, n);
    printf("ft_strncmp result (differ at last character): %d\n", result);  // Expected: negative value (difference between 'o' and 'z')

    // Test case 3: Strings differ after `n` characters
    const char *str5 = "Hello";
    const char *str6 = "HelLo";
    result = ft_strncmp(str5, str6, 3);
    printf("ft_strncmp result (differ after n characters): %d\n", result);  // Expected: 0

    // Test case 4: One string is shorter
    const char *str7 = "Hel";
    const char *str8 = "Hello";
    result = ft_strncmp(str7, str8, 5);
    printf("ft_strncmp result (one string shorter): %d\n", result);  // Expected: negative value

    // Test case 5: Compare with standard strncmp
    result = strncmp(str1, str4, n);
    printf("Standard strncmp result: %d\n", result);  // Expected: similar value as ft_strncmp

    return 0;
}