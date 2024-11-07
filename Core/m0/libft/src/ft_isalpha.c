#include "libft.h"

/// @brief Check if character is an alphabetic letter
/// 
/// This function checks whether the given character `c` is either an uppercase
/// or lowercase alphabetic character.
/// 
/// @param c The character to be checked
/// @return 1 if `c` is an alphabetic letter, 0 otherwise
int ft_isalpha(int c)
{
    if (ft_isupper(c) || ft_islower(c))
        return (1);
    return (0);
}

#include <stdio.h>  // Library used in main for testing purposes

int main(void)
{
    // Test case: 'A' should return 1 since it is an uppercase alphabetic character
    char test_char = 'A';
    printf("ft_isalpha('%c') = %d\n", test_char, ft_isalpha(test_char));  // Expected: 1

    // Test case: 'g' should return 1 since it is a lowercase alphabetic character
    test_char = 'g';
    printf("ft_isalpha('%c') = %d\n", test_char, ft_isalpha(test_char));  // Expected: 1

    // Test case: '5' should return 0 since it is not an alphabetic character
    test_char = '5';
    printf("ft_isalpha('%c') = %d\n", test_char, ft_isalpha(test_char));  // Expected: 0

    return 0;
}