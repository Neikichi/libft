#include "libft.h"

void ft_bzero(void *s, size_t n)
{
    // char *ptr;
    //
    // ptr = s;
    ft_memset(s, '\0', n);
    // while (i < n)
    // {
    //     *ptr = '\0';
    //     ptr++;
    //     i++;
    // }
}
