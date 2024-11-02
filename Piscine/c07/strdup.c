#include <stdlib.h>
#include <stdio.h>
// #include <string.h>

int ft_strlen(char *src)
{
    int cnt;

    cnt = 0;
    if (src == NULL)
        return 0;
    while (*src)
    {
        src++;
        cnt++;
    }
    return (cnt);
}

char    *ft_strcpy(char *dest,char *src)
{
    if (src == NULL || dest == NULL)
        return NULL;
    while (*src)
    {
        *dest = *src;
        src++;
        dest++;
    }
    *dest = '\0';
    return (dest);
}

char *ft_strdup(char *src)
{
    int size;
    char *dup;

    if (src == NULL)
        return (NULL);
    size = ft_strlen(src);
    dup = malloc(size * 1 + 1);
    if (dup == NULL)
        return (NULL);
    ft_strcpy(dup, src);
    return (dup);
}

int main(void)
{

    char *src = "こんにちは";  // "Hello" in Japanese
    char *dup = ft_strdup(src);
    printf("Original: %s\n", src);
    printf("Duplicate: %s\n", dup);
    free(dup);

    // char a[] = "Hello World";
    // char b[] = "Donkey Kong";

    // char *dup_str = ft_strdup(a);
    
    // if (dup_str != NULL)
    // {
    //     printf("%s\n", dup_str);
    //     free(dup_str);
    // }
    // else
    // {
    //     printf("LEAK LEAK LEAK\n");
    // }
    return (0);
}