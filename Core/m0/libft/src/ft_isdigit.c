#include "libft.h"

/// @brief Check if character is a digit (0-9)
/// 
/// This function checks whether the given character `c` is a decimal digit
/// (between '0' and '9').
/// 
/// @param c The character to be checked
/// @return 1 if `c` is a digit, 0 otherwise
int ft_isdigit(int c)
{
    if (c >= '0' && c <= '9')
        return (1);
    return (0);
}

#include <stdio.h>  // Library used in main for testing purposes

int main(void)
{
    // Test case: '5' should return 1 since it is a digit
    char test_char = '5';
    printf("ft_isdigit('%c') = %d\n", test_char, ft_isdigit(test_char));  // Expected: 1

    // Test case: 'a' should return 0 since it is not a digit
    test_char = 'a';
    printf("ft_isdigit('%c') = %d\n", test_char, ft_isdigit(test_char));  // Expected: 0

    // Test case: '0' should return 1 since it is the first valid digit
    test_char = '0';
    printf("ft_isdigit('%c') = %d\n", test_char, ft_isdigit(test_char));  // Expected: 1

    return 0;
}