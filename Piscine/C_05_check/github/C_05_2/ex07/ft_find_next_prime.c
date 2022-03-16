/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guntkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 20:04:47 by guntkim           #+#    #+#             */
/*   Updated: 2022/02/10 13:09:00 by guntkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_find_next_prime(int nb)
{
	long long	num;
	int			flag;

	if (nb <= 2)
		return (2);
	if (nb == 3)
		return (3);
	while (nb)
	{
		flag = 0;
		num = 2;
		while (num * num <= nb)
		{
			if (nb % num == 0)
			{
				flag = 1;
				break ;
			}
			num += 1;
		}
		if (flag == 0)
			return (nb);
		nb += 1;
	}
	return (0);
}
