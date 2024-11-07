#include "libft.h"

/// @brief Check if character is an ASCII character
/// 
/// This function checks whether the given character `c` is in the ASCII range (0 to 127).
/// 
/// @param c The character to be checked
/// @return 1 if `c` is an ASCII character, 0 otherwise
int ft_isascii(int c)
{
    if (c >= 0 && c <= 127)
        return (1);
    return (0);
}

#include <stdio.h>  // Library used in main for testing purposes

int main(void)
{
    // Test case: 65 (ASCII value for 'A') should return 1
    int test_char = 65;
    printf("ft_isascii(%d) = %d\n", test_char, ft_isascii(test_char));  // Expected: 1

    // Test case: -5 should return 0 since it is not in the ASCII range
    test_char = -5;
    printf("ft_isascii(%d) = %d\n", test_char, ft_isascii(test_char));  // Expected: 0

    // Test case: 128 should return 0 since it is above the ASCII range
    test_char = 128;
    printf("ft_isascii(%d) = %d\n", test_char, ft_isascii(test_char));  // Expected: 0

    return 0;
}