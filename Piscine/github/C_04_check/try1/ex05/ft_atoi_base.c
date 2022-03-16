/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guntkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 13:58:08 by guntkim           #+#    #+#             */
/*   Updated: 2022/02/08 21:23:09 by guntkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
int	process_num(char *str, long long num, int sign)
{
	int	i;

	i = 0;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		if (num * sign > 2147483647)
			return (-1);
		else if (num * sign < -2147483648)
			return (0);
		else
			num = num * 10 + (str[i] - '0');
		i++;
	}
	return (num * sign);
}

void	process_minus(int minus, int *sign)
{
	if (minus % 2)
		*sign = -1;
}

int	is_space(char c)
{
	if (c == '\f')
		return (1);
	if (c == '\n')
		return (1);
	if (c == '\v')
		return (1);
	if (c == '\t')
		return (1);
	if (c == '\r')
		return (1);
	if (c == ' ')
		return (1);
	return (0);
}
int	ft_atoi(char *str)
{
	int			i;
	int			minus;
	int			sign;
	long long	num;

	i = 0;
	sign = 1;
	minus = 0;
	num = 0;
	while (is_space(str[i]))
		i += 1;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			minus += 1;
		i += 1;
	}
	process_minus(minus, &sign);
	return process_num(&str[i], num, sign);
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

void init(int *arr)
{
	int	i;

	i = 0;
	while (i < 94)
	{
		arr[i] = 0;
		i += 1;
	}
}

int	ft_atoi_base(char *str, char *base)
{
	int	base_len;
	int	chk[94];

	base_len = 0;
	init(chk);
	while (base[base_len]){
		if (chk[base[base_len] - 33] == 1)
			return (0);
		if (base[base_len] == '+' || base[base_len] == '-')
			return (0);
		chk[base[base_len] - 33] = 1; 
		base_len += 1;
	}
	if (base_len <= 1)
		return (0);
	ft_putnbr((long long)ft_atoi(str), base, base_len);
}

int main(void)
{
	printf("%d", ft_atoi_base("62423", "hoit"));
}
