#include "libft.h"

char *ft_strcpy(char *dst, char *src)
{
    char *ptr;

    ptr = dst;
    while (*src)
    {
        *ptr = *src;
        ptr++;
        src++;
    }
    *ptr = '\0';
    return (dst);
}