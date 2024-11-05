#include "libft.h"

char *ft_strcpy(char *dest, const char *src)
{
    while (*src)
    {
        *dest = *src;
        src++;
        dest++;
    }
    *dest = '\0';
    return (dest);
}