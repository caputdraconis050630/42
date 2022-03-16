/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guntkim <guntkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 08:34:09 by guntkim           #+#    #+#             */
/*   Updated: 2022/02/21 09:32:49 by guntkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		ft_putchar(str[i++]);
}

void	ft_putnbr(int nb)
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
