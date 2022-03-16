/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guntkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 17:29:28 by guntkim           #+#    #+#             */
/*   Updated: 2022/02/09 18:54:13 by guntkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	long long	num;

	num = 1;
	if (nb <= 0)
		return (0);
	while (num * num < nb)
	{
		num += 1;
	}
	if (num * num == nb)
		return (num);
	else
		return (0);
}
