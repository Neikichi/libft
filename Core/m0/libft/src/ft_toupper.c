#include "libft.h"

/// @brief Convert a lowercase character to uppercase
/// 
/// This function converts a lowercase character to its corresponding uppercase character.
/// If the character is not a lowercase letter, it is returned unchanged.
/// 
/// @param c The character to be converted
/// @return The converted uppercase character, or the original character if it is not lowercase
int ft_toupper(int c)
{
    if (ft_islower(c))
    {
        return (c - 32);
    }
    return (c);
}

#include <stdio.h> // For testing purposes

int main(void)
{
    // Test case 1: Convert a lowercase letter
    int ch1 = 'a';
    int result1 = ft_toupper(ch1);
    printf("ft_toupper('%c') = '%c'\n", ch1, result1);  // Expected: 'A'

    // Test case 2: Convert another lowercase letter
    int ch2 = 'z';
    int result2 = ft_toupper(ch2);
    printf("ft_toupper('%c') = '%c'\n", ch2, result2);  // Expected: 'Z'

    // Test case 3: Input is an uppercase letter
    int ch3 = 'M';
    int result3 = ft_toupper(ch3);
    printf("ft_toupper('%c') = '%c'\n", ch3, result3);  // Expected: 'M'

    // Test case 4: Input is a non-alphabetical character
    int ch4 = '!';
    int result4 = ft_toupper(ch4);
    printf("ft_toupper('%c') = '%c'\n", ch4, result4);  // Expected: '!'

    return 0;
}