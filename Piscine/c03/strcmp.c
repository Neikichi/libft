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

int ft_strcmp(char *s1, char *s2)
{  
    int idx;
    int cnt;

    idx = 0;
    cnt = 0;
    while ((idx < ft_strlen(s1)) || (idx < ft_strlen(s2)))
    {
        cnt = cnt + (s1[idx] - s2[idx]);
        if (cnt != 0)
        {
            return (cnt);
        }
        idx++;
    }
    return (0);
}

int	ft_strcmp2(char *s1, char *s2)
{
	int	cnt;

	cnt = 0;
	while (*s1 || *s2)
	{
		cnt = cnt + (*s1 - *s2);
		if (cnt != 0)
			return (cnt);
		s1++;
        s2++;
	}
	return (0);
}

int main(void)
{
    char test[] = "01235";
    char testt[] = "0123";
    int number = strcmp(test,testt);
    int numberr = ft_strcmp(test,testt);
    int numberrr = ft_strcmp2(test,testt);
    printf("%d\n", number);
    printf("%d\n", numberr);
    printf("%d\n", numberrr);
}