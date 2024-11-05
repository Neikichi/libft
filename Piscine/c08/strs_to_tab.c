#include <stdio.h>
#include <stdlib.h>
// #include "ft_stock_str.h"

// void	ft_show_tab(struct s_stock_str *par);

typedef struct s_stock_str
{
    int size;
    char *str;
    char *copy;
}   t_stock_str;

int ft_strlen(char *str)
{
    int cnt;

    cnt = 0;
    while (*str)
    {
        cnt++;
        str++;
    }
    return (cnt);
}

char *ft_strcpy(char *dest, char *src)
{
    char *st;

    st = dest;
    // if (dest == NULL || src == NULL)
    //     return (NULL);
    while (*src)
    {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
    return (st);
}

char *ft_strdup(char *src)
{
    char *dup;
    // int size;
    // int cnt = ft_strlen(src);
    // printf("cnt: %d\n", cnt);

    // size = 0;
    // // if (src == NULL)
    // //     return (NULL);
    // while (src[size])
    //     size++;
    dup = malloc(sizeof(char) * (ft_strlen(src) + 1));
    if (!dup)
        return (NULL);
    ft_strcpy(dup, src);
    // while (src[size])
    // {
    //     dup[size] = src[size];
    //     size++;
    // }
    // dup[size] = '\0';
    return (dup);
}

// void free_tab_ex(struct s_stock_str *ptr, int idx)
// {
//     while (idx >= 0)
//     {
//         // printf("inside free tab ex 1\n");
//         free(ptr[idx].str);
//         // printf("inside free tab ex 2\n");
//         free(ptr[idx].copy);
//         idx--;
//     }
//     free(ptr);
// }

// int ft_strs_to_tab_ex(struct s_stock_str *ptr, char *av)
// {
//     int size;

//     size = 0;
//     while (av[size])
//         size++;
//     ptr->size = size;
//     ptr->str = ft_strdup(av);
//     ptr->copy = ft_strdup(ptr->str);
//     if (!(ptr->str) || !(ptr->copy))
//         return (0);
//     return (1);
// }

struct s_stock_str *ft_strs_to_tab(int ac, char **av)
{
    int idx;
    struct s_stock_str *ptr;

    idx = 0;
    // if (ac <= 0 || av == NULL)
    //     return (NULL);
    ptr = malloc(sizeof(*ptr) * (ac + 1));
    if (!ptr)
        return (NULL);
    while (idx < ac)
    {
        // if (av[idx] == NULL || !ft_strs_to_tab_ex(&ptr[idx], av[idx]))
        // {
        //     free_tab_ex(ptr, idx);
        //     return NULL;
        // }
        (ptr + idx)->size = ft_strlen(av[idx]);
        // printf("after size\n");
        (ptr + idx)->str = av[idx];
        // printf("after str\n");
        (ptr + idx)->copy = ft_strdup(av[idx]);
        // printf("after copy\n");
        // if (!(ptr[idx].str) || !(ptr[idx].copy))
        // {
        //     // while (--idx >= 0)
        //     // {
        //     //     free(ptr[idx].str);
        //     //     free(ptr[idx].copy);
        //     //     // idx--;
        //     // }
        //     // free(ptr);
        //     free_tab_ex(ptr, idx);
        //     return (NULL);
        // }
        idx++;
    }
    // printf("before last\n");
    ptr[idx].str = 0;
    // printf("after last\n");
    return (ptr);
}

int main(void)
{
    char *av[] = {"aa"};
    int ac = 1;
    struct s_stock_str *av_trans;
    int i = 0;
    
    av_trans = ft_strs_to_tab(ac, av);
    while (av_trans[i].str != 0)
    {
        printf("size: %i\n", av_trans[i].size);
        printf("str: %s\n", av_trans[i].str);
        printf("copy: %s\n\n", av_trans[i].copy);
        i++;
    }

    // char *strings[] = {"Hello", "World", "42", "School"};
    // int count = 4; // Number of strings in the array
    // struct s_stock_str *result;
    
    // // Call the ft_strs_to_tab function
    // result = ft_strs_to_tab(count, strings);
    
    // // Check if the result is not NULL
    // if (result == NULL)
    // {
    //     printf("Error: ft_strs_to_tab failed.\n");
    //     return (1);
    // }
    
    // // Print the results
    // for (int i = 0; i < count; i++)
    // {
    //     printf("String %d:\n", i);
    //     printf("Original: %s\n", result[i].str);
    //     printf("Copy: %s\n", result[i].copy);
    //     printf("Size: %d\n\n", result[i].size);
    // }

    // // Free memory
    // for (int i = 0; i < count; i++)
    // {
    //     free(result[i].str);
    //     free(result[i].copy);
    // }
    // free(result);
    
    return 0;
}