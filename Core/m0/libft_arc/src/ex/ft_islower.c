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

/*#include <stdio.h>*/
/**/
/*int main(void)*/
/*{*/
/*    char test_char = 'g';*/
/*    printf("ft_islower('%c') = %d\n", test_char, ft_islower(test_char));*/
/*    test_char = 'G';*/
/*    printf("ft_islower('%c') = %d\n", test_char, ft_islower(test_char));*/
/*    test_char = 'a';*/
/*    printf("ft_islower('%c') = %d\n", test_char, ft_islower(test_char));*/
/**/
/*    return 0;*/
/*}*/
