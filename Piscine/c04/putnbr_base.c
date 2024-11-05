#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


void	ft_putchar(char c)
{
	write(1, &c, 1);
}

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

void	ft_putnbr_base(int nb, char *base)
{
	int amt;
	unsigned int	val;

	amt = base_check(base);
	if (amt < 2)
		return;
	if (nb < 0)
	{
		ft_putchar('-');
		val = (unsigned)(-nb);
	}
	else
	{
		val = (unsigned)(nb);
	}
	if (val >= (unsigned)(amt))
		ft_putnbr_base(val / amt, base);
	ft_putchar(base[val % amt]);
}

int main(void)
{
	ft_putnbr_base(-2147483648, "01");
	return 0;
}	