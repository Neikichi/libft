#include "libft.h"

/// @brief Check if character is lowercase
/// 
/// This function checks whether the given character `c` is a lowercase
/// alphabetic character (between 'a' and 'z').
/// 
/// @param c The character to be checked
/// @return 1 if `c` is a lowercase letter, 0 otherwise
int ft_islower(int c)
{
    if (c >= 'a' && c <= 'z')
        return (1);
    return (0);
}

#include <stdio.h>  // Library used in main for testing purposes

int main(void)
{
    // Test case: 'g' should return 1 since it is a lowercase letter
    char test_char = 'g';
    printf("ft_islower('%c') = %d\n", test_char, ft_islower(test_char));  // Expected: 1

    // Test case: 'G' should return 0 since it is not a lowercase letter
    test_char = 'G';
    printf("ft_islower('%c') = %d\n", test_char, ft_islower(test_char));  // Expected: 0

    // Test case: 'a' should return 1 since it is the first lowercase letter
    test_char = 'a';
    printf("ft_islower('%c') = %d\n", test_char, ft_islower(test_char));  // Expected: 1

    return 0;
}