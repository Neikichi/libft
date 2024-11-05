#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int cond(char c)
{
	int	iswsp;
	int isnb;
	int issn;
	int isal;

	iswsp = (c == ' ' || (c >= 9 && c <= 13));
	issn = (c == '+' || c == '-' );
	isnb = (c >= '0' && c <= '9');
	isal = (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
    if (iswsp)
        return (1);
	if (issn)
        return (2);
	if (isnb)
		return (3);
	if (isal)
		return (4);
    return (0);
}

int isvalid(char c, char *base)
{
    int idx;

    idx = 0;
    while (base[idx] != '\0')
    {
		
        if (c == base[idx])
            return (idx);
        idx++;
    }
	printf("isvalid: %c\n", c);
    return (-1);
}

int	base_check(char *base)
{
	int bcnt;
	char *ptr;

	bcnt = 0;
	if (base[0] == '\0' || base[1] == '\0')
		return (1);
	while (*base)
	{
		ptr = base + 1;
		while (*ptr)
		{
			if (*base == *ptr)
				return (1);
			ptr++;
		}
		if (cond(*base) == 1 || cond(*base) == 2)
			return (1);
		bcnt++;
		base++;
	}
	return (bcnt);
}

void	parse_valid(char *str, char *base, int *amt, int *flag)
{
    while (*str && (cond(*str) == 3 || cond(*str) == 4))
    {
		if (isvalid(*str, base) != -1)
		{
            if (*amt > (2147483647 - isvalid(*str, base)) / base_check(base))
			{
                *flag = 1;
				// printf("max pos!!\n");
				break ;
			}
			if (*amt < (-2147483648 + isvalid(*str, base)) / base_check(base))
			{
                *flag = 1;
				// printf("min pos!!\n");
				break ;
			}
			*amt = *amt * base_check(base) + isvalid(*str, base);
			str++;
		}
		else
        {
            *flag = 1;
			// printf("else pos!!\n");
			break ;
        }
    }
}

int	ft_atoi_base(char *str, char *base, int *flag)
{
	int cnt;
    int amt;

	if (base_check(base) <= 1)
	{
		*flag = 1;
		// printf("basecheck: %d\n", base_check(base));
		return (0);
	}
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
	parse_valid(str, base, &amt, flag);
	if (cnt % 2 == 1)
		return (-amt);
	else
   		return (amt);
}