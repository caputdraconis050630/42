/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guntkim <guntkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 15:13:22 by guntkim           #+#    #+#             */
/*   Updated: 2022/02/05 17:04:21 by guntkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	is_last(char *arr, int target, int *flag)
{
	int	index;

	index = target - 1;
	if (arr[index] != '9')
	{
		return ;
	}
	index --;
	while (index >= 0)
	{
		if (arr[index + 1] - 1 != arr[index])
		{
			*flag = 0;
			return ;
		}
		index --;
	}
	*flag = 1;
}

void	append(char *arr, int target, int index)
{	
	int		flag;
	char	bridge[2];

	flag = 0;
	if (target == index)
	{	
		flag = 0;
		is_last(arr, target, &flag);
		write(1, arr, target);
		if (flag == 0)
		{
			bridge[0] = ',';
			bridge[1] = ' ';
			write(1, bridge, 2);
		}
		return ;
	}
	arr[index] = arr[index - 1] + 1;
	while (arr[index] <= '9')
	{
		append(arr, target, index + 1);
		arr[index] += 1;
	}
}

void	ft_print_combn(int n)
{
	char	arr[10];

	arr[0] = '0';
	while (arr[0] <= '9')
	{
		append(arr, n, 1);
		arr[0] += 1;
	}
}
