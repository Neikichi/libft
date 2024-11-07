#include "libft.h"

char *ft_strdup(const char *s)
{
    char *dup;

    if (!s)
        return (NULL);
    dup = malloc(ft_strlen(s) * 1 + 1);
    if (!dup)
        return (NULL);
    ft_strcpy(dup, s);
    return (dup);
}
