/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlow <vlow@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 20:18:13 by vlow              #+#    #+#             */
/*   Updated: 2024/09/05 20:21:39 by vlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	count;

	count = 0;
	while (str[count] != '\0')
	{
		count++;
	}
	return (count);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	idx;
	int	cnt;

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

void	ft_selcsort(char *argv[], int max)
{
	int		idx;
	int		jdx;
	int		min;
	char	*temp;

	idx = 1;
	while (idx < max)
	{
		min = idx;
		jdx = idx + 1;
		while (jdx <= max)
		{
			if (ft_strcmp(argv[jdx], argv[min]) < 0)
			{
				min = jdx;
			}
			jdx++;
		}
		temp = argv[min];
		argv[min] = argv[idx];
		argv[idx] = temp;
		idx++;
	}
}

int	main(int argc, char *argv[])
{
	int	idx;
	int	max;

	max = argc - 1;
	if (argc > 1)
	{
		ft_selcsort(argv, max);
		idx = 1;
		while (idx < argc)
		{
			write(1, argv[idx], ft_strlen(argv[idx]));
			write(1, "\n", 1);
			idx++;
		}
	}
	return (0);
}
