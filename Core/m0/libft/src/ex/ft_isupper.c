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

/*#include <stdio.h>*/
/**/
/*int main(void)*/
/*{*/
/*    char test_char = 'G';*/
/*    printf("ft_isupper('%c') = %d\n", test_char, ft_isupper(test_char));*/
/*    test_char = 'g';*/
/*    printf("ft_isupper('%c') = %d\n", test_char, ft_isupper(test_char));*/
/*    test_char = 'A';*/
/*    printf("ft_isupper('%c') = %d\n", test_char, ft_isupper(test_char));*/
/**/
/*    return 0;*/
/*}*/
