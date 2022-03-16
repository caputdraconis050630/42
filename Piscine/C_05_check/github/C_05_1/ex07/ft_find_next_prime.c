/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guntkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 20:04:47 by guntkim           #+#    #+#             */
/*   Updated: 2022/02/09 20:06:04 by guntkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_find_next_prime(int nb)
{
	long long	long_nb;
	long long	num;

	long_nb = (long long)nb;
	while (long_nb ++)
	{
		num = 2;
		while (num * num <= long_nb)
		{
			if (long_nb % num == 0)
				return (long_nb);
			num += 1;
		}
	}
	return (0);
}
