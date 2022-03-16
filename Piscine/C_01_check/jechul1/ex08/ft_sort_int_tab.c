/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guntkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 18:29:13 by guntkim           #+#    #+#             */
/*   Updated: 2022/02/05 18:29:15 by guntkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int	now;
	int	target;
	int	i;
	int	tmp;

	now = 0;
	while (now < size -1)
	{
		target = now;
		i = now + 1;
		while (i <= size - 1)
		{
			if (tab[i] < tab[target])
			{
				target = i;
			}
			i += 1;
		}
		tmp = tab[now];
		tab[now] = tab[target];
		tab[target] = tmp;
		now += 1;
	}
}
