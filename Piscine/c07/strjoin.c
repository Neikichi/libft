#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int ft_strlen(char *str)
{
    int cnt;

    cnt = 0;
    while (*str)
    {
        str++;
        cnt++;
    }
    return (cnt);
}

char	*ft_strstr(char *str, char *to_find)
{
    int idx;
    int cnt;

    idx = 0;
    if (*to_find == '\0')
        return (str);
    while (str[idx] != '\0')
    {
        cnt = 0;
        while (to_find[cnt] == str[idx + cnt])
        {
            if (to_find[cnt + 1] == '\0')
            {
                return (str + idx);
            }
            cnt++;
        }
        idx++;
    }
    return (0);
}

char *ft_strcat(char *dest, char *src)
{
    int idx;
    int dest_len;
    int src_len;

    idx = 0;
    dest_len = ft_strlen(dest);
    src_len = ft_strlen(src);
    while (src[idx] != '\0')
    {
        dest[dest_len + idx] = src[idx];
        idx++;
    }
    dest[dest_len + idx] = '\0';
    return (dest);
}

void    ft_catsep(int size, char **strs, char *sep, char *result)
{
    int idx;

    idx = 0;
    result[0] = '\0';
    while (idx < size)
    {
        ft_strcat(result, strs[idx]);
        if (idx < size - 1)
            ft_strcat(result, sep);
        idx++;
    }
}

char *ft_strjoin(int size, char **strs, char *sep)
{
    int idx;
    int len;
    int sep_size;
    char *result;

    idx = 0;
    len = 0;
    sep_size = ft_strlen(sep) * (size - 1);
    if (size == 0)
    {
        result = malloc(1);
        if (result)
            result[0] = '\0';
        return result;
    }
    while (idx < size)
    {
        len += ft_strlen(strs[idx]);
        idx++;
    }
    // printf("strs 1: %s || strs 2: %s || strs 3: %s || sep: %d || len: %d\n", strs[0], strs[1], strs[2], sep_size, len);
    result = malloc(sizeof(char) * (len + sep_size) + 1);
    if (!result)
        return NULL;
    // printf("strs 1: %d || strs 2: %s || strs 3: %s || sep: %s || len: %d\n", ft_strlen(strs[0]), strs[1], strs[2], sep, len);
    ft_catsep(size, strs, sep, result);
    // printf("strs 1: %s || strs 2: %s || strs 3: %s || sep: %s || len: %d\n", strs[0], strs[1], strs[2], sep, len);
    return (result);
}

int main(void)
{
    char *result;

    // Test case 1: ft_strjoin with size 0 (no strings)
    printf("Test 1: ft_strjoin with size 0\n");
    char *strs1[] = {}; // No strings
    result = ft_strjoin(0, strs1, ",");
    if (result == NULL || strcmp(result, "") != 0)
    {
        printf("Test FAILED\n");
        printf("Expected: \"\"\n");
        printf("Got:      \"%s\"\n", result ? result : "(null)");
    }
    else
    {
        printf("Test PASSED\n");
    }
    free(result);

    // Test case 2: ft_strjoin with size 1 (one string)
    printf("\nTest 2: ft_strjoin with size 1\n");
    char *strs2[] = { "Hello" };
    result = ft_strjoin(1, strs2, ",");
    if (result == NULL || strcmp(result, "Hello") != 0)
    {
        printf("Test FAILED\n");
        printf("Expected: \"Hello\"\n");
        printf("Got:      \"%s\"\n", result ? result : "(null)");
    }
    else
    {
        printf("Test PASSED\n");
    }
    free(result);

    // Test case 3: ft_strjoin with size 3 (three strings, separator ", ")
    printf("\nTest 3: ft_strjoin with size 3\n");
    char *strs3[] = { "Hello", "world", "!" };
    result = ft_strjoin(3, strs3, ", ");
    if (result == NULL || strcmp(result, "Hello, world, !") != 0)
    {
        printf("Test FAILED\n");
        printf("Expected: \"Hello, world, !\"\n");
        printf("Got:      \"%s\"\n", result ? result : "(null)");
        
    }
    else
    {
        printf("Test PASSED\n");
        printf("aaaaa:      \"%s\"\n", result);
    }
    free(result);

    // Test case 4: ft_strjoin with size 4 and empty strings, separator "-"
    printf("\nTest 4: ft_strjoin with size 4 and empty strings\n");
    char *strs4[] = { "", "Hello", "", "world" };
    result = ft_strjoin(4, strs4, "-");
    if (result == NULL || strcmp(result, "-Hello--world") != 0)
    {
        printf("Test FAILED\n");
        printf("Expected: \"-Hello--world\"\n");
        printf("Got:      \"%s\"\n", result ? result : "(null)");
    }
    else
    {
        printf("Test PASSED\n");
    }
    free(result);

    // Test case 5: ft_strjoin with size 2 and empty separator
    printf("\nTest 5: ft_strjoin with size 2 and empty separator\n");
    char *strs5[] = { "Hello", "world" };
    result = ft_strjoin(2, strs5, "");
    if (result == NULL || strcmp(result, "Helloworld") != 0)
    {
        printf("Test FAILED\n");
        printf("Expected: \"Helloworld\"\n");
        printf("Got:      \"%s\"\n", result ? result : "(null)");
    }
    else
    {
        printf("Test PASSED\n");
    }
    free(result);

    return 0;
}