#include "libft.h"


/// @brief Copy a string to a destination buffer, considering buffer size
/// 
/// This function copies up to `size - 1` characters from the string `src` to `dst`,
/// null-terminating the result if `size` is not zero.
/// 
/// @param dst The destination buffer to which the string is copied
/// @param src The source string to be copied
/// @param size The total size of the destination buffer
/// @return The total length of the source string (`src`)
size_t ft_strlcpy(char *dst, const char *src, size_t size)
{
    size_t i;

    i = 0;
    if (size > 0)
    {
        while (i < size - 1 && src[i] != '\0')
        {
            dst[i] = src[i];
            i++;
        }
    }
    dst[i] = '\0';
    return (ft_strlen(src));
}

#include <stdio.h>  // For testing purposes
#include <string.h> // For comparison with standard strlcpy

int main(void)
{
    // Test case 1: Normal copy
    const char *src1 = "Hello, world!";
    char dest1[20];
    size_t result1 = ft_strlcpy(dest1, src1, sizeof(dest1));
    printf("ft_strlcpy result: %s\n", dest1);  // Expected: Hello, world!
    printf("ft_strlcpy total length: %zu\n", result1);  // Expected: 13

    // Test case 2: Small buffer
    char dest2[6];
    size_t result2 = ft_strlcpy(dest2, src1, sizeof(dest2));
    printf("ft_strlcpy result (small buffer): %s\n", dest2);  // Expected: Hello (truncated)
    printf("ft_strlcpy total length: %zu\n", result2);  // Expected: 13

    // Test case 3: Empty buffer
    char dest3[1];
    size_t result3 = ft_strlcpy(dest3, src1, sizeof(dest3));
    printf("ft_strlcpy result (empty buffer): '%s'\n", dest3);  // Expected: ''
    printf("ft_strlcpy total length: %zu\n", result3);  // Expected: 13

    // Test case 4: Compare with standard strlcpy
    char std_dest[20];
    size_t std_result = strlcpy(std_dest, src1, sizeof(std_dest));
    printf("Standard strlcpy result: %s\n", std_dest);  // Expected: Hello, world!
    printf("Standard strlcpy total length: %zu\n", std_result);  // Expected: 13

    return 0;
}