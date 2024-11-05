#include "libft.h"

/// @brief Extract a substring from a string based on length
/// @param s - The string from which to create the substring 
/// @param start - The start index of the substring in the string 's'
/// @param len - The maximum length of the substring
/// @return The substring. NULL if the allocation fails.
char *ft_substr(char const *s, unsigned int start, size_t len)
{
    char *buffer;
    unsigned int i;

    i = 0;
    buffer = malloc(sizeof(char) * len);
    if (!buffer)
        return (NULL);
    while ((size_t)start < len)
    {
        buffer[i] = s[start - 1];
        start++;
        i++;
    }
    buffer[i] = '\0';
    return (buffer);
}