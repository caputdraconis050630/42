/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guntkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 15:59:38 by guntkim           #+#    #+#             */
/*   Updated: 2022/02/09 16:06:38 by guntkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	ans;

	ans = 1;
	if (nb < 0)
		return (0);
	if (nb == 0 && power == 0)
		return (1);
	while (power--)
		ans *= nb;
	return (ans);
}
