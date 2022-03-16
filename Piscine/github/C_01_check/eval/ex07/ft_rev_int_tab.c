/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guntkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 18:29:28 by guntkim           #+#    #+#             */
/*   Updated: 2022/02/05 20:34:39 by guntkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	repeat;
	int	i;
	int	tmp;

	repeat = size / 2;
	i = 0;
	while (i < repeat)
	{
		tmp = tab[i];
		tab[i] = tab[size - i - 1];
		tab[size - i - 1] = tmp;
		i += 1;
	}
}

int main(void)
{
	int tab[6] = {1, 2, 3, 4, 5, 6};
	ft_rev_int_tab(tab, 6);
	printf("%d %d %d %d %d %d", tab[0], tab[1], tab[2], tab[3], tab[4], tab[5]);
}
