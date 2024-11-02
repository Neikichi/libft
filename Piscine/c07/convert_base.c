#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int ft_atoi_base(char *str, char *base, int *flag);
int base_check(char *base);

void    ft_buff2(unsigned int *val, int *amt, char *buffer, char *base)
{
    int idx;

    idx = 0;
    if (*val == 0)
    {
        buffer[idx++] = base[0];
        buffer[idx] = '\0';
        // idx++;
    }
    while (*val > 0)
    {
        buffer[idx++] = base[*val % *amt];
        *val /= *amt;
        // idx++;
    }
    printf("val1: %d\n", *val);
    printf("amt1: %d\n", *amt);
    printf("base1: %c\n", base[0]);
    printf("buffer: %s\n", buffer);
    buffer[idx] = '\0';
}

char    *ft_result(char *buffer, int *bufsz, int flag)
{
    int idx;
    char *result;

    idx = 0;
    result = malloc(sizeof(char) * (*bufsz + 1));
    if (!result)
        return NULL;
    if (flag == 1)
        result[0] = '-';
    while (idx < *bufsz)
    {
        result[idx + flag] = buffer[*bufsz - 1 - idx];
        idx++;
    }
    result[idx + flag] = '\0';
    free(buffer);
    return (result);
}

char *ft_buff(unsigned int *val, int *amt, char *base, int flag)
{
    int idx;
    char *buffer;
    unsigned int bufval;
    int bufsz;
    char *result;

    idx = 0;
    bufval = *val;
    bufsz = 0;
    if (bufval == 0)
        bufsz = 1;
    while (bufval > 0)
    {
        bufval /= *amt;
        bufsz++;
    }
    buffer = malloc(sizeof(char) * bufsz + 1);
    if (!buffer)
        return NULL;
    ft_buff2(val, amt, buffer, base);
    // printf("val1: %d\n", *val);
    // printf("amt1: %d\n", *amt);
    // printf("base1: %s\n", base);
    // printf("flag1: %d\n", flag);
    
    result = ft_result(buffer, &bufsz, flag);
    printf("result: %s\n", result);
    return (result);
}

char    *ft_putnbr_base(int nb, char *base)
{
	int amt;
	unsigned int	val;
    int bufsz;
    //char buffer[36];
    char *result;
    int flag;
    //int j;

    bufsz = 0;
	amt = base_check(base);
    flag = 0;
	if (amt < 2)
		return NULL;
	if (nb < 0)
	{
        flag = 1;
		val = (unsigned)(-nb);
	}
	else
		val = (unsigned)(nb);
    // if (val == 0)
    // {
    //     buffer[idx++] = base[0];
    //     buffer[idx] = '\0';
    // }
    // while (val > 0)
    // {
    //     buffer[idx++] = base[val % amt];
    //     val /= amt;
    // }
    // buffer[idx] = '\0';
    // result = malloc(sizeof(char) * (idx + flag + 1));
    // if (!result)
    //     return NULL;
    // if (flag == 1)
    //     result[0] = '-';
    // printf("val: %d\n", val);
    // printf("amt: %d\n", amt);
    // printf("base: %s\n", base);
    // printf("flag: %d\n", flag);
    result = ft_buff(&val, &amt, base, flag);
    // printf("val1: %d\n", val);
    // printf("amt1: %d\n", amt);
    // printf("base1: %s\n", base);
    // printf("flag1: %d\n", flag);
    printf("resulttt: %s\n", result);
	//j = 0
    // while (idx < idx)
    // {
    //     result[idx + flag] = buffer[idx - idx - 1];
    //     idx++;
    // }
    // result[idx + flag] = '\0';
    return (result);
}

char *ft_convert_base(char *nbr, char *base_from, char *base_to)
{
    int flag;
    int atoi_result;

    flag = 0;

    if (base_check(base_from) == 1 || base_check(base_to) == 1)
        return NULL;
    printf("here\n");
    atoi_result = ft_atoi_base(nbr, base_from, &flag);
    printf("atoi result: %d\n", atoi_result);
    printf("flag result: %d\n", flag);
    if (flag == 1 && atoi_result != 0)
        return NULL;
    return (ft_putnbr_base(atoi_result, base_to));
}

int main(void)
{
    char *result;

    // Test Case 1: Simple positive number conversion from base 10 to base 2
    result = ft_convert_base("--abc", "0123456789", "01");
    if (result)
    {
        printf("42 (Base 10) -> %s (Base 2)\n", result);  // Expected: "101010"
        free(result);
    }
    else
        printf("Test 1: Conversion failed return val: %s.\n",result);

    // // Test Case 2: Negative number conversion from base 10 to base 16
    // result = ft_convert_base("-255", "0123456789", "0123456789ABCDEF");
    // if (result)
    // {
    //     printf("-255 (Base 10) -> %s (Base 16)\n", result);  // Expected: "-FF"
    //     free(result);
    // }
    // else
    //     printf("Test 2: Conversion failed\n");

    // // Test Case 3: Number with leading whitespaces, converting from base 16 to base 10
    // result = ft_convert_base("   FF", "0123456789ABCDEF", "0123456789");
    // if (result)
    // {
    //     printf("   FF (Base 16) -> %s (Base 10)\n", result);  // Expected: "255"
    //     free(result);
    // }
    // else
    //     printf("Test 3: Conversion failed\n");

    // // Test Case 4: Multiple signs, converting from base 10 to base 2
    // result = ft_convert_base("++--42", "0123456789", "01");
    // if (result)
    // {
    //     printf("++--42 (Base 10) -> %s (Base 2)\n", result);  // Expected: "101010"
    //     free(result);
    // }
    // else
    //     printf("Test 4: Conversion failed\n");

    // // Test Case 5: Invalid base_from (duplicate characters)
    // result = ft_convert_base("42", "01234567899", "01");
    // if (result)
    //     printf("Test 5: Failed, unexpected result: %s\n", result);  // Should return NULL
    // else
    //     printf("Test 5: NULL (Invalid base_from detected correctly)\n");

    // // Test Case 6: Invalid base_to (contains '+' sign)
    // result = ft_convert_base("42", "0123456789", "01+");
    // if (result)
    //     printf("Test 6: Failed, unexpected result: %s\n", result);  // Should return NULL
    // else
    //     printf("Test 6: NULL (Invalid base_to detected correctly)\n");

    // // Test Case 7: Base 10 to a custom base "abcde" (Base 5)
    // result = ft_convert_base("42", "0123456789", "abcde");
    // if (result)
    // {
    //     printf("42 (Base 10) -> %s (Base abcde)\n", result);  // Expected: "bcd"
    //     free(result);
    // }
    // else
    //     printf("Test 7: Conversion failed\n");

    // // Test Case 8: Number with trailing whitespace, converting from base 16 to base 10
    // result = ft_convert_base("FF   ", "0123456789ABCDEF", "0123456789");
    // if (result)
    // {
    //     printf("FF   (Base 16) -> %s (Base 10)\n", result);  // Expected: "255"
    //     free(result);
    // }
    // else
    //     printf("Test 8: Conversion failed\n");

    // // Test Case 9: Very large number exceeding int limit (should return NULL)
    // result = ft_convert_base("2147483648", "0123456789", "01234567");
    // if (result)
    //     printf("Test 9: Failed, unexpected result: %s\n", result);  // Should return NULL
    // else
    //     printf("Test 9: NULL (Number exceeding int detected correctly)\n");

    return 0;
}