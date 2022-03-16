/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guntkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 16:10:03 by guntkim           #+#    #+#             */
/*   Updated: 2022/02/09 16:29:40 by guntkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_recursive_power(int nb, int power)
{
	int	ans;

	ans = 1;
	if (power == 1)
		return nb;
	return (nb * ft_recursive_power(nb, power - 1));
}
