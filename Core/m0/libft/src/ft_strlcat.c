#include "libft.h"

/// @brief Concatenate strings, taking buffer size into account
/// 
/// This function appends the `src` string to the `dst` string, ensuring that
/// the total length of the resulting `dst` string does not exceed `size` - 1,
/// leaving room for a null terminator.
/// 
/// @param dst The destination buffer to which `src` will be concatenated
/// @param src The source string to be appended to `dst`
/// @param size The total size of the destination buffer
/// @return The total length of the string it tried to create (initial `dst` length + `src` length)
size_t ft_strlcat(char *dst, const char *src, size_t size)
{
    size_t i;

    i = 0;
    while (i < size - 1 && src[i] != '\0')
    {
        dst[i] = src[i];
        i++;
    }
    dst[i] = '\0';
    return (ft_strlen(src));
}


#include <stdio.h>  // For testing purposes
#include <string.h> // For comparison with standard strlcat

int main(void)
{
    // Test case 1: Normal concatenation
    char dest1[20] = "Hello, ";
    const char *src1 = "world!";
    size_t size1 = sizeof(dest1);
    size_t result1 = ft_strlcat(dest1, src1, size1);
    printf("ft_strlcat result: %s\n", dest1);  // Expected: Hello, world!
    printf("ft_strlcat total length: %zu\n", result1);  // Expected: 13

    // Test case 2: Buffer too small
    char dest2[10] = "Hello";
    const char *src2 = "world!";
    size_t size2 = sizeof(dest2);
    size_t result2 = ft_strlcat(dest2, src2, size2);
    printf("ft_strlcat result (small buffer): %s\n", dest2);  // Expected: Hello (truncated)
    printf("ft_strlcat total length: %zu\n", result2);  // Expected: 11 (5 + 6)

    // Test case 3: Compare with standard strlcat
    char std_dest[20] = "Hello, ";
    size_t std_result = strlcat(std_dest, src1, size1);
    printf("Standard strlcat result: %s\n", std_dest);  // Expected: Hello, world!
    printf("Standard strlcat total length: %zu\n", std_result);  // Expected: 13

    return 0;
}