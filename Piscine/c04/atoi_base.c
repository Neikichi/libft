#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int cond(char c)
{
	int	iswsp;
	int isnb;
	int issn;
	int isal;

	isnb = (c >= '0' && c <= '9');
	iswsp = (c == ' ' || (c >= 9 && c <= 13));
	issn = (c == '+' || c == '-' );
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
    return (-1);
}

int	base_check(char *base)
{
	int cnt;
	int bcnt;

	bcnt = 0;
	if (base[0] == '\0')
		return (1);
	while (*base)
	{
		cnt = 0;
		while (*base == base[++cnt] && base[++cnt] != '\0')
			return (1);
		if (cond(*base) == 1 || cond(*base) == 2)
			return (1);
		bcnt++;
		base++;
	}
	return (bcnt);
}

void	parse_valid(char *str, char *base, int *amt)
{
    while (*str && (cond(*str) == 3 || cond(*str) == 4))
    {
		if (isvalid(*str, base) != -1)
		{
			*amt = *amt * base_check(base) + isvalid(*str, base);
			str++;
		}
		else
			break ;
    }
}

int	ft_atoi_base(char *str, char *base)
{
	int cnt;
    int amt;

	if (base_check(base) <= 1)
		return (0);
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
	parse_valid(str, base, &amt);
	if (cnt % 2 == 1)
		return (-amt);
	else
   		return (amt);
}

int main(void)
{
	printf("%d\n", ft_atoi_base("10101010", "01"));
	return 0;
}