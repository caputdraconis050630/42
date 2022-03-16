/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guntkim <guntkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 16:49:03 by guntkim           #+#    #+#             */
/*   Updated: 2022/02/22 16:51:09 by guntkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display_file.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i++], 1);
	}
}

void	put_nbr(int nbr)
{
	long long	long_nb;

	long_nb = nb;
	if (long_nb < 0)
	{
		long_nb *= -1;
		ft_putchar('-');
	}
	if (long_nb >= 10)
	{
		ft_putnbr(long_nb / 10);
	}
	ft_putchar((long_nb % 10) + '0');
}
