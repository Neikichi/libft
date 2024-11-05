#include "libft.h"

char *ft_strncpy(char *dest, char *src, size_t len)
{
    size_t i_len;
    size_t j_len;

    i_len = 0;
    j_len = len;
    while (i_len != len && src[i_len] != '\0')
    {
        dest[i_len] = src[i_len];
        i_len++;
        j_len--;
    }
    while (j_len != 0)
    {
        dest[i_len] = '\0';
        i_len++;
        j_len--;
    }
    return (dest);
}