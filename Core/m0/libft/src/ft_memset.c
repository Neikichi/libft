#include "libft.h"


/// @brief Fill memory with a constant byte
/// 
/// This function fills the first `n` bytes of the memory area pointed to by `s`
/// with the constant byte `c`.
/// 
/// @param s A pointer to the memory area to be filled
/// @param c The byte value to be set, passed as an int but treated as an unsigned char
/// @param n The number of bytes to be filled
/// @return A pointer to the memory area (`s`)
void *ft_memset(void *s, int c, size_t n)
{
    size_t i;
    unsigned char *ptr;

    ptr = s;
    i = 0;
    while (i < n)
    {
        *ptr = (unsigned char)c;
        ptr++;
        i++;
    }
    return (s);
}


#include <stdio.h>  // Library used in main for testing purposes
#include <string.h> // For comparison with standard memset

int main(void)
{
    // Test case: Set the first 5 bytes of an array to '*'
    char str[20] = "Hello, world!";
    ft_memset(str, '*', 5);
    printf("ft_memset result: %s\n", str);  // Expected: *****o, world!

    // Test case: Set all bytes of an integer array to zero
    int arr[5] = {1, 2, 3, 4, 5};
    ft_memset(arr, 0, sizeof(arr));
    printf("ft_memset result for integer array: ");
    for (size_t i = 0; i < 5; i++)
    {
        printf("%d ", arr[i]);  // Expected: 0 0 0 0 0
    }
    printf("\n");

    // Test case: Compare with standard memset
    char std_str[20] = "Hello, world!";
    memset(std_str, '*', 5);
    printf("Standard memset result: %s\n", std_str);  // Expected: *****o, world!

    return 0;
}