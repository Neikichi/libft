/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlow <vlow@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 21:30:34 by vlow              #+#    #+#             */
/*   Updated: 2024/09/10 12:44:09 by vlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_atoi_base(char *str, char *base, int *flag);
int	base_check(char *base);

void	ft_buff2(unsigned int *val, int *amt, char *buffer, char *base)
{
	int	idx;

	idx = 0;
	if (*val == 0)
	{
		buffer[idx++] = base[0];
		buffer[idx] = '\0';
	}
	while (*val > 0)
	{
		buffer[idx++] = base[*val % *amt];
		*val /= *amt;
	}
	buffer[idx] = '\0';
}

char	*ft_result(char *buffer, int *bufsz, int flag)
{
	int		idx;
	char	*result;

	idx = 0;
	result = malloc(sizeof(char) * (*bufsz + 1));
	if (!result)
		return (NULL);
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

char	*ft_buff(unsigned int *val, int *amt, char *base, int flag)
{
	int				idx;
	char			*buffer;
	unsigned int	bufval;
	int				bufsz;
	char			*result;

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
		return (NULL);
	ft_buff2(val, amt, buffer, base);
	result = ft_result(buffer, &bufsz, flag);
	return (result);
}

char	*ft_putnbr_base(int nb, char *base)
{
	int				amt;
	unsigned int	val;
	int				bufsz;
	char			*result;
	int				flag;

	bufsz = 0;
	amt = base_check(base);
	flag = 0;
	if (amt < 2)
		return (NULL);
	if (nb < 0)
	{
		flag = 1;
		val = (unsigned)(-nb);
	}
	else
		val = (unsigned)(nb);
	result = ft_buff(&val, &amt, base, flag);
	return (result);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int	flag;
	int	atoi_result;

	flag = 0;
	if (!base_check(base_from) || !base_check(base_to))
		return (NULL);
	atoi_result = ft_atoi_base(nbr, base_from, &flag);
	if (flag == 1)
		return (NULL);
	return (ft_putnbr_base(atoi_result, base_to));
}
