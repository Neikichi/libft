#include "libft.h"

/// @brief Check if character is printable
/// 
/// This function checks whether the given character `c` is a printable
/// character, including space, but excluding control characters.
/// 
/// @param c The character to be checked
/// @return 1 if `c` is a printable character, 0 otherwise
int ft_isprint(int c)
{
    if (c >= 32 && c <= 126)
        return (1);
    return (0);
}

#include <stdio.h>  // Library used in main for testing purposes

int main(void)
{
    // Test case: Space character (ASCII 32) should return 1 as it is printable
    int test_char = 32;
    printf("ft_isprint(%d) = %d\n", test_char, ft_isprint(test_char));  // Expected: 1

    // Test case: ASCII 127 should return 0 since it is not printable
    test_char = 127;
    printf("ft_isprint(%d) = %d\n", test_char, ft_isprint(test_char));  // Expected: 0

    // Test case: 'A' (ASCII 65) should return 1 as it is a printable character
    test_char = 'A';
    printf("ft_isprint('%c') = %d\n", test_char, ft_isprint(test_char));  // Expected: 1

    return 0;
}