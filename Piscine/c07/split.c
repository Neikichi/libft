#include <stdlib.h>
#include <stdio.h>

char *ft_strlcpy(char *dest, char *src, int len)
{
    int idx;

    idx = 0;
    if (dest == NULL || src == NULL)
        return (NULL);
    while (idx < len)
    {
        dest[idx] = src[idx];
        idx++;
    }
    dest[idx] = '\0';
    return (dest);
}

int ft_chkset(char c, char *charset)
{
    while (*charset)
    {
        if (*charset == c)
            return (1);
        charset++;
    }
    return (0);
}

int get_word(char *str, char *charset)
{
    int cnt;
    int flag;
    int set;

    cnt = 0;
    flag = 0;
    while (*str)
    {
        set = 0;
        if (ft_chkset(*str, charset))
            set = 1;
        if (set == 0 && flag == 0)
        {
            cnt++;
            flag = 1;
        }
        if (set == 1)
            flag = 0;
        str++;
    }
    return (cnt);
}

char **ft_split_ex(char *str, char *charset, char **result)
{
    int idx;
    int len;
    char *find;

    idx = 0;
    while (*str)
    {
        while (*str && ft_chkset(*str, charset))
            str++;
        if (*str)
        {
            find = str;
            while (*find && !ft_chkset(*find, charset))
                find++;
            len = find - str;
            if ((result[idx] = malloc(sizeof(char) * (len + 1))) == NULL)
                return (NULL);
            ft_strlcpy(result[idx], str, len);
            idx++;
            str = find;
        }
        // while (idx == size)
        // {
        //     if ((result[idx] = malloc(sizeof(char) * (1 + 1))) == NULL)
        //         return (NULL);
        //     ft_strlcpy(result[idx], "0", 1);
        //     idx++;
        // }
    }
    result[idx] = NULL;
    return (result);
}

char **ft_split(char *str, char *charset)
{
    char **result;
    int size;

    if (*str == '\0')
    {
        if ((result = malloc(sizeof(char *) * 1 + 1)) == NULL)
            return (NULL);
        // ft_strlcpy(result[0], "0", 1);
        result[0] = NULL;
        return (result);
    }
    size = get_word(str, charset);
    if ((result = malloc(sizeof(char *) * (size + 2))) == NULL)
        return (NULL);
    return (ft_split_ex(str, charset, result));
}

int main(void)
{
    // Test 1: Basic test with multiple separators
    printf("Test 1: Basic test with multiple separators\n");
    char str1[] = "Hello,World!This,is a-test.";
    char charset1[] = ",! -";
    char **result1 = ft_split(str1, charset1);
    int i = 0;
    while (result1[i] != NULL)
    {
        printf("result1[%d]: %s\n", i, result1[i]);
        free(result1[i]); // Free each string
        i++;
    }
    printf("result1[%d]: NULL\n", i); // Marking the end
    free(result1); // Free the array itself
    printf("-------------------------------------------------\n");

    // Test 2: String with consecutive separators
    printf("Test 2: String with consecutive separators\n");
    char str2[] = "Hello,,,World!!This,,is--a-test.";
    char charset2[] = ",! -";
    char **result2 = ft_split(str2, charset2);
    i = 0;
    while (result2[i] != NULL)
    {
        printf("result2[%d]: %s\n", i, result2[i]);
        free(result2[i]); // Free each string
        i++;
    }
    printf("result2[%d]: NULL\n", i); // Marking the end
    free(result2); // Free the array itself
    printf("-------------------------------------------------\n");

    // Test 3: String with no separators
    printf("Test 3: String with no separators\n");
    char str3[] = "HelloWorld";
    char charset3[] = ",! -";
    char **result3 = ft_split(str3, charset3);
    i = 0;
    while (result3[i] != NULL)
    {
        printf("result3[%d]: %s\n", i, result3[i]);
        free(result3[i]); // Free each string
        i++;
    }
    printf("result3[%d]: NULL\n", i); // Marking the end
    free(result3); // Free the array itself
    printf("-------------------------------------------------\n");

    // Test 4: String with only separators
    printf("Test 4: String with only separators\n");
    char str4[] = ",! -";
    char charset4[] = ",! -";
    char **result4 = ft_split(str4, charset4);
    i = 0;
    while (result4[i] != NULL)
    {
        printf("result4[%d]: %s\n", i, result4[i]);
        free(result4[i]); // Free each string
        i++;
    }
    printf("result4[%d]: NULL\n", i); // Marking the end
    free(result4); // Free the array itself
    printf("-------------------------------------------------\n");

    // Test 5: Empty string as input
    printf("Test 5: Empty string as input\n");
    char str5[] = "";
    char charset5[] = ",! -";
    char **result5 = ft_split(str5, charset5);
    i = 0;
    while (result5[i] != NULL)
    {
        printf("result5[%d]: %s\n", i, result5[i]);
        free(result5[i]); // Free each string
        i++;
    }
    printf("result5[%d]: NULL\n", i); // Marking the end
    free(result5); // Free the array itself
    printf("-------------------------------------------------\n");

    // Edge Case 1: Empty charset (no characters to split on)
    printf("Edge Case 1: Empty charset (no characters to split on)\n");
    char str6[] = "HelloWorld";
    char charset6[] = "";
    char **result6 = ft_split(str6, charset6);
    i = 0;
    while (result6[i] != NULL)
    {
        printf("result6[%d]: %s\n", i, result6[i]);
        free(result6[i]); // Free each string
        i++;
    }
    printf("result6[%d]: NULL\n", i); // Marking the end
    free(result6); // Free the array itself
    printf("-------------------------------------------------\n");

    // Edge Case 2: Single separator at the beginning and end
    printf("Edge Case 2: Single separator at the beginning and end\n");
    char str7[] = ",Hello,World,";
    char charset7[] = ",";
    char **result7 = ft_split(str7, charset7);
    i = 0;
    while (result7[i] != NULL)
    {
        printf("result7[%d]: %s\n", i, result7[i]);
        free(result7[i]); // Free each string
        i++;
    }
    printf("result7[%d]: NULL\n", i); // Marking the end
    free(result7); // Free the array itself
    printf("-------------------------------------------------\n");

    // Edge Case 3: Only separators in the middle of the string
    printf("Edge Case 3: Only separators in the middle of the string\n");
    char str8[] = "Hello,,,,World";
    char charset8[] = ",";
    char **result8 = ft_split(str8, charset8);
    i = 0;
    while (result8[i] != NULL)
    {
        printf("result8[%d]: %s\n", i, result8[i]);
        free(result8[i]); // Free each string
        i++;
    }
    printf("result8[%d]: NULL\n", i); // Marking the end
    free(result8); // Free the array itself
    printf("-------------------------------------------------\n");

    // Additional Edge Case: Charset larger than input string
    printf("Additional Edge Case: Charset larger than input string\n");
    char str9[] = "a";
    char charset9[] = "abcdef";
    char **result9 = ft_split(str9, charset9);
    i = 0;
    while (result9[i] != NULL)
    {
        printf("result9[%d]: %s\n", i, result9[i]);
        free(result9[i]); // Free each string
        i++;
    }
    printf("result9[%d]: NULL\n", i); // Marking the end
    free(result9); // Free the array itself
    printf("-------------------------------------------------\n");

    // Additional Edge Case: Both string and charset are empty
    printf("Additional Edge Case: Both string and charset are empty\n");
    char str10[] = "";
    char charset10[] = "";
    char **result10 = ft_split(str10, charset10);
    i = 0;
    if (result10[0] == NULL)
        printf("The result is NULL terminated as expected.\n");
    free(result10); // Free the array itself
    printf("-------------------------------------------------\n");

    return 0;
}