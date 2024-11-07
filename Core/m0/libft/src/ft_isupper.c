#include "libft.h"

/// @brief Check if character is uppercase
/// 
/// This function checks whether the given character `c` is an uppercase
/// alphabetic character (between 'A' and 'Z').
/// 
/// @param c The character to be checked
/// @return 1 if `c` is an uppercase letter, 0 otherwise
int ft_isupper(int c)
{
    if (c >= 'A' && c <= 'Z')
        return (1);
    return (0);
}

#include <stdio.h>  // Library used in main for testing purposes

int main(void)
{
    // Test case: 'G' should return 1 since it is an uppercase letter
    char test_char = 'G';
    printf("ft_isupper('%c') = %d\n", test_char, ft_isupper(test_char));  // Expected: 1

    // Test case: 'g' should return 0 since it is not an uppercase letter
    test_char = 'g';
    printf("ft_isupper('%c') = %d\n", test_char, ft_isupper(test_char));  // Expected: 0

    // Test case: 'A' should return 1 since it is the first uppercase letter
    test_char = 'A';
    printf("ft_isupper('%c') = %d\n", test_char, ft_isupper(test_char));  // Expected: 1

    return 0;
}