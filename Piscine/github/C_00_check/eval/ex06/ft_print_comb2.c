/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guntkim <guntkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 13:57:55 by guntkim           #+#    #+#             */
/*   Updated: 2022/02/03 18:35:29 by guntkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	update_num(int idx, char *arr, int *flag)
{
	*flag = 0;
	if (arr[idx + 1] == '9')
	{
		if (arr[idx] == '9')
		{
			if (idx == 3)
			{
				*flag = 1;
			}
		}
		else
		{
			arr[idx] += 1;
			arr[idx + 1] = '0';
		}
	}
	else
	{
		arr[idx + 1] += 1;
	}
}

void	to_nxt_num(char *arr)
{	
	int	flag;

	update_num(3, arr, &flag);
	if (flag == 1)
	{
		update_num(0, arr, &flag);
		if (arr[1] == '9')
		{
			arr[3] = arr[0] + 1;
			arr[4] = '0';
		}
		else
		{
			arr[3] = arr[0];
			arr[4] = arr[1] + 1;
		}
	}
}

void	ft_print_comb2(void)
{
	char	arr[13];

	arr[0] = '0';
	arr[1] = '0';
	arr[2] = ' ';
	arr[3] = '0';
	arr[4] = '1';
	arr[5] = ',';
	arr[6] = ' ';
	while (! (arr[0] == '9' && arr[1] == '8' && arr[3] == '9' && arr[4] == '9'))
	{
		write(1, arr, 7);
		to_nxt_num(arr);
	}
	write(1, arr, 5);
}
