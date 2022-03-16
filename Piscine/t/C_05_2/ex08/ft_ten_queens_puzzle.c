/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guntkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 12:43:36 by guntkim           #+#    #+#             */
/*   Updated: 2022/02/10 12:45:02 by guntkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	put_nbr(int nb)
{
	char	c;

	c = nb + '0';
	write(1, &c, 1);
}

int	chk_ganeung(int *arr, int now, int index)
{
	int	i;

	i = 0;
	while (i < index)
	{
		if (arr[i] == arr[index])
			return (0);
		i += 1;
	}
	i = 0;
	while (i < index)
	{
		if (arr[i] == now + (index - i))
			return (0);
		if (arr[i] == now - (index - i))
			return (0);
		i += 1;
	}
	return (1);
}

void	append(int *arr, int index, int *num)
{
	int	i;

	i = 0;
	if (index == 10)
	{
		while (i < 10)
		{
			put_nbr(arr[i]);
			i += 1;
		}
		write(1, "\n", 1);
		*num += 1;
		return ;
	}
	arr[index] = 0;
	while (arr[index] <= 9)
	{
		if (chk_ganeung(arr, arr[index], index))
			append(arr, index + 1, num);
		arr[index] += 1;
	}
	return ;
}

int	ft_ten_queens_puzzle(void)
{
	int	arr[10];
	int	num;

	num = 0;
	arr[0] = 0;
	while (arr[0] <= 9)
	{
		append(arr, 1, &num);
		arr[0] += 1;
	}
	return (num);
}
