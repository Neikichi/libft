#include <stdio.h>
#include <stdlib.h>

int cond(char c)
{
	int	iswsp;
	int isnb;
	int issn;

	isnb = (c >= '0' && c <= '9');
	iswsp = (c == ' ' || (c >= 9 && c <= 13));
	issn = (c == '+' || c == '-' );
    if (iswsp)
        return (1);
	if (issn)
        return (2);
	if (isnb)
		return (3);
    return (0);
}

int	ft_atoi(char *str)
{
	int cnt;
    int amt;

	cnt = 0;
	amt = 0;
	while (*str && cond(*str) == 1)
        str++;
    while (*str && cond(*str) == 2)
    {
        if (*str == '-')
            cnt++;
        str++;
    }
    while (*str && cond(*str) == 3)
    {
        amt = amt * 10 + (*str - '0');
        str++;
    }
	if (cnt % 2 == 1)
		return (-amt);
	else
   		return (amt);
}

int main(void)
{
    char a[] = "- 2147483649isuahda";

    // printf("atoi: %d ==\n", atoi(a));
    printf("owns: %d ==\n", ft_atoi(a));

    return (0);
}