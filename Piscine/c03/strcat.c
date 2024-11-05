#include <unistd.h>
#include <stdio.h>
#include <string.h>

int	ft_strlen(char *str)
{
	int	ct;

	ct = 0;
	while (*str)
	{
		str++;
		ct++;
	}
	return (ct);
}

char *ft_strcat(char *dest, char *src)
{  
    char *ptr = dest;
    while (*ptr != '\0')
    {
        ptr++;
    }
    while (*src != '\0')
    {
        *ptr++ = *src++;
    }
    *ptr = '\0';
    return (dest);
}

int main(void)
{
    char src[] = "Hejlo World";
    char dest[50] = "";
    char src1[] = "Hejlo World";
    char dest1[50] = "";
    printf("%s\n", strcat(src, dest));
    printf("%s\n", ft_strcat(src1, dest1));
}