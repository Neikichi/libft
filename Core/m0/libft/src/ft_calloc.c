#include "libft.h"

void *ft_calloc(size_t nmemb, size_t size)
{
    unsigned char *init;
    size_t i;
    
    i = nmemb * size;
    init = malloc(i);
    if (!init)
        return (NULL);
    ft_memset(init, 0, i);
    return init;
}