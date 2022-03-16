/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guntkim <guntkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 14:02:07 by guntkim           #+#    #+#             */
/*   Updated: 2022/02/03 18:39:19 by guntkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print(char c)
{
	write(1, &c, 1);
}

void	print_min(void)
{
	char	arr[11];

	arr[0] = '-';
	arr[1] = '2';
	arr[2] = '1';
	arr[3] = '4';
	arr[4] = '7';
	arr[5] = '4';
	arr[6] = '8';
	arr[7] = '3';
	arr[8] = '6';
	arr[9] = '4';
	arr[10] = '8';
	write(1, arr, 11);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		print_min();
	}
	else
	{
		if (nb < 0)
		{
			ft_print('-');
			nb *= -1;
		}
		if (nb > 9)
		{
			ft_putnbr(nb / 10);
		}
		ft_print(nb % 10 + '0');
	}
}
