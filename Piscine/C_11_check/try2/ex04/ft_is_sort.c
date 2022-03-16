/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guntkim <guntkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 08:30:41 by guntkim           #+#    #+#             */
/*   Updated: 2022/02/21 08:32:34 by guntkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_rev_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	j;

	i = 0;
	while (i < length)
	{
		j = 0;
		while (j < i)
		{
			if (f(tab[i], tab[j]) > 0)
				return (0);
			j += 1;
		}
		i += 1;
	}
	return (1);
}

int	ft_is_right_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	j;

	i = 0;
	while (i < length)
	{
		j = 0;
		while (j < i)
		{
			if (f(tab[i], tab[j]) < 0)
				return (0);
			j += 1;
		}
		i += 1;
	}
	return (1);
}

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	flag;
	int	flag_rev;

	flag = ft_is_right_sort(tab, length, f);
	flag_rev = ft_is_rev_sort(tab, length, f);
	if (flag || flag_rev)
		return (1);
	return (0);
}
