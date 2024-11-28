/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlow <vlow@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 23:17:45 by vlow              #+#    #+#             */
/*   Updated: 2024/09/05 20:40:27 by vlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	idx;

	idx = 2;
	if (nb <= 1)
		return (2);
	while (idx <= nb / idx)
	{
		if (nb % idx == 0)
			return (0);
		idx++;
	}
	return (nb);
}

int	ft_find_next_prime(int nb)
{
	if (nb == ft_is_prime(nb))
		return (nb);
	return (ft_find_next_prime(nb + 1));
}
