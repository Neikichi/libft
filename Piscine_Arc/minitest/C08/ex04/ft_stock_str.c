/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rychan <rychan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 20:13:44 by rychan            #+#    #+#             */
/*   Updated: 2024/09/12 21:11:12 by rychan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
	{
		len++;
	}
	return (len);
}

char	*ft_strdup(char *src)
{
	int		i;
	char	*copy;

	i = 0;
	copy = (char *)malloc((ft_strlen(src) + 1) * sizeof(char));
	if (copy == NULL)
		return (NULL);
	while (src[i] != '\0')
	{
		copy[i] = src[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

struct	s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	t_stock_str	*tab;

	i = 0;
	tab = (t_stock_str *) malloc((ac + 1) * sizeof(t_stock_str));
	if (tab == NULL)
		return (NULL);
	while (i < ac)
	{
		tab[i].size = ft_strlen(av[i]);
		tab[i].str = av[i];
		tab[i].copy = ft_strdup(av[i]);
		if (tab[i].copy == NULL)
			return (NULL);
		i++;
	}
	tab[i].str = NULL;
	return (tab);
}
