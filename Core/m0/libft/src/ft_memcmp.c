#include "libft.h"


/// @brief Compare two memory blocks
/// 
/// This function compares the first `n` bytes of the memory areas `s1` and `s2`.
/// The comparison is done lexicographically as unsigned char values.
/// 
/// @param s1 A pointer to the first memory block
/// @param s2 A pointer to the second memory block
/// @param n The number of bytes to compare
/// @return An integer less than, equal to, or greater than zero if the first
///         differing byte in `s1` is found to be less than, to match, or be greater
///         than the corresponding byte in `s2`
int ft_memcmp(const void *s1, const void *s2, size_t n)
{
    size_t i;
    const unsigned char *ptrs1;
    const unsigned char *ptrs2;

    ptrs2 = (const unsigned char *)s2;
    ptrs1 = (const unsigned char *)s1;
    i = 0;
    while (i < n)
    {
        if (*ptrs1 != *ptrs2)
            return (*ptrs1 - *ptrs2);
        i++;
        ptrs1++;
        ptrs2++;
    }
    return (0);
}


#include <stdio.h>  // Library used in main for testing purposes
#include <string.h> // For comparison with standard memcmp

int main(void)
{
    // Test case: Compare two identical strings
    char str1[] = "Hello, world!";
    char str2[] = "Hello, world!";
    int result = ft_memcmp(str1, str2, strlen(str1));
    printf("ft_memcmp result for identical strings: %d\n", result);  // Expected: 0

    // Test case: Compare two strings that differ
    char str3[] = "Hello, world!";
    char str4[] = "Hello, Word!";
    result = ft_memcmp(str3, str4, strlen(str3));
    printf("ft_memcmp result for different strings: %d\n", result);  // Expected: non-zero (depends on where it differs)

    // Test case: Compare with standard memcmp for verification
    int std_result = memcmp(str3, str4, strlen(str3));
    printf("Standard memcmp result for different strings: %d\n", std_result);  // Expected: same as ft_memcmp result

    return 0;
}