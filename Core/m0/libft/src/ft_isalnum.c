#include "libft.h"

/// @brief Check if character is alphanumeric
/// 
/// This function checks whether the given character `c` is either a letter (alphabetic)
/// or a digit (0-9).
/// 
/// @param c The character to be checked
/// @return 1 if `c` is alphanumeric, 0 otherwise
int ft_isalnum(int c)
{
    if (ft_isalpha(c) || ft_isdigit(c))
        return (1);
    return (0);
}

#include <stdio.h>  // Library used in main for testing purposes

int main(void)
{
    // Test case: Edge character, '0' should return 1 since it is a digit
    char test_char = '0';
    printf("ft_isalnum('%c') = %d\n", test_char, ft_isalnum(test_char));  // Expected: 1

    // Test case: '@' should return 0 since it's neither a letter nor a digit
    test_char = '@';
    printf("ft_isalnum('%c') = %d\n", test_char, ft_isalnum(test_char));  // Expected: 0

    return 0;
}
