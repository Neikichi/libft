#include <stdio.h>

// int ft_sqrt(int nb)
// {
//     int mn;
//     int md;
//     int mx;
//     int rs;

//     if (nb < 0)
//         return (-1);
//     if (nb == 0 || nb == 1)
//         return (nb);
    
//     mn = 1;
//     mx = nb;
//     rs = 0;
//     while (mn <= mx)
//     {
//         md = (mn + mx) / 2;
//         if (md * md == nb)
//             return md;
//         else if (md * md < nb)
//         {
//             mn = md + 1;
//             rs = md;
//         }
//         else
//             mx = md - 1;
//     }
//     return (rs);
// }

// int ft_is_prime(int nb)
// {
//     int idx;
//     int cnt;

//     if (nb <= 1)
//         return (0);
//     if (nb == 2)
//         return (1);
//     cnt = 2;
//     idx = ft_sqrt(nb);
//     while (cnt <= idx)
//     {
//         if (nb % cnt == 0)
//             return (0);
//         cnt++;
//     }
//     return (1);
// }

int	ft_is_prime(int nb)
{
	int	idx;

	idx = 2;
	if (nb <= 1)
		return (0);

	while (idx <= nb / idx)
	{
		if (nb % idx == 0)
			return (0);
		idx++;
	}
	return (1);
}

int main(void)
{
    printf("%d\n", ft_is_prime(-100));
    printf("%d\n", ft_is_prime(0));
    printf("%d\n", ft_is_prime(1));
    printf("%d\n", ft_is_prime(97));
    printf("%d\n", ft_is_prime(101));
    printf("%d\n", ft_is_prime(25));
    printf("%d\n", ft_is_prime(99));
    return 0;
}