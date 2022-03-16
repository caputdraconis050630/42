/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guntkim <guntkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 13:58:44 by guntkim           #+#    #+#             */
/*   Updated: 2022/02/03 21:05:22 by guntkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print(char *arr, int size)
{
	write(1, arr, size);
}

void	to_nxt_num(char	*arr)
{
	if (arr[2] == '9' )
	{
		if (arr[1] == '8')
		{
			arr[0] += 1;
			arr[1] = arr[0] + 1;
		}
		else
		{
			arr[1] += 1;
		}
		arr[2] = arr[1] + 1;
	}
	else
	{
		arr[2] += 1;
	}
}

void	ft_print_comb(void)
{
	char	arr[6];

	arr = "012, ";
	while (! (arr[0] == '7' && arr[1] == '8' && arr[2] == '9'))
	{
		ft_print(arr, 5);
		to_nxt_num(arr);
	}
	ft_print(arr, 3);
}
