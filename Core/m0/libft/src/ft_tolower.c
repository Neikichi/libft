#include "libft.h"

/// @brief Convert an uppercase character to lowercase
/// 
/// This function converts an uppercase character to its corresponding lowercase character.
/// If the character is not an uppercase letter, it is returned unchanged.
/// 
/// @param c The character to be converted
/// @return The converted lowercase character, or the original character if it is not uppercase
int ft_tolower(int c)
{
    if (ft_isupper(c))
    {
        return (c + 32);
    }
    return (c);
}

#include <stdio.h> // For testing purposes

int main(void)
{
    // Test case 1: Convert an uppercase letter
    int ch1 = 'A';
    int result1 = ft_tolower(ch1);
    printf("ft_tolower('%c') = '%c'\n", ch1, result1);  // Expected: 'a'

    // Test case 2: Convert another uppercase letter
    int ch2 = 'Z';
    int result2 = ft_tolower(ch2);
    printf("ft_tolower('%c') = '%c'\n", ch2, result2);  // Expected: 'z'

    // Test case 3: Input is a lowercase letter
    int ch3 = 'm';
    int result3 = ft_tolower(ch3);
    printf("ft_tolower('%c') = '%c'\n", ch3, result3);  // Expected: 'm'

    // Test case 4: Input is a non-alphabetical character
    int ch4 = '!';
    int result4 = ft_tolower(ch4);
    printf("ft_tolower('%c') = '%c'\n", ch4, result4);  // Expected: '!'

    return 0;
}