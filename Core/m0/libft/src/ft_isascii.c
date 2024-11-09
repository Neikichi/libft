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
