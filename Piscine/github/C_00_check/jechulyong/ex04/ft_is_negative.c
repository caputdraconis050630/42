/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guntkim <guntkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 13:59:36 by guntkim           #+#    #+#             */
/*   Updated: 2022/02/03 17:38:01 by guntkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_is_negative(int n);

void	ft_is_negative(int n)
{
	char	ch_p;
	char	ch_n;

	ch_p = 'P';
	ch_n = 'N';
	if (n >= 0)
	{
		write(1, &ch_p, 1);
	}
	else
	{
		write(1, &ch_n, 1);
	}
}
