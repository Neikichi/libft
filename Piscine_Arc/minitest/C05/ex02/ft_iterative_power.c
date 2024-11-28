/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlow <vlow@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 22:44:20 by vlow              #+#    #+#             */
/*   Updated: 2024/09/05 20:29:03 by vlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	idx;
	int	amt;

	idx = 0;
	amt = nb;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	while (++idx < power)
		amt *= nb;
	return (amt);
}
