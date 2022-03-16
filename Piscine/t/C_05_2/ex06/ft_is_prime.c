/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guntkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 18:54:29 by guntkim           #+#    #+#             */
/*   Updated: 2022/02/10 12:47:56 by guntkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	long long	num;
	long long	long_nb;

	num = 2;
	long_nb = (long)nb;
	if (nb <= 1)
		return (0);
	while (num * num <= long_nb)
	{
		if (long_nb % num == 0)
			return (0);
		num += 1;
	}
	return (1);
}
