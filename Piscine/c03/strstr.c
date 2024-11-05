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

int main(void)
{
    char c1[] = "";
    char c2[] = "Hello";
	printf("%s\n", ft_strstr(c1,c2));
    // printf("%s\n", strstr(c1, c2));
    return 0;
}