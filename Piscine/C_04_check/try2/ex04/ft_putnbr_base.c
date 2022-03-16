/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guntkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 13:20:51 by guntkim           #+#    #+#             */
/*   Updated: 2022/02/09 12:49:35 by guntkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(long long nbr, char *base, int base_len)
{
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr *= -1;
	}
	if (nbr >= base_len)
	{
		ft_putnbr(nbr / base_len, base, base_len);
	}
	ft_putchar(base[nbr % base_len]);
}

void	init(int *arr)
{
	int	i;

	i = 0;
	while (i < 200)
	{
		arr[i] = 0;
		i += 1;
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	base_len;
	int	chk[200];

	base_len = 0;
	init(chk);
	while (base[base_len] != '\0')
	{
		if (chk[(int)base[base_len]] == 1)
			return ;
		if (base[base_len] == '+' || base[base_len] == '-')
			return ;
		chk[(int)base[base_len]] = 1;
		base_len += 1;
	}
	if (base_len <= 1)
		return ;
	ft_putnbr((long long)nbr, base, base_len);
}
