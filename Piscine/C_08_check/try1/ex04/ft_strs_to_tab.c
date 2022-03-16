/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guntkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 08:40:29 by guntkim           #+#    #+#             */
/*   Updated: 2022/02/15 19:22:31 by guntkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

void	get_copy(int *size, char *str, char *copy, char *av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		str[i] = av[i];
		copy[i] = av[i];
		i += 1;
	}
	*size = i;
	return ;
}

struct	s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int					i;
	struct s_stock_str	*ft;

	i = 0;
	ft = (struct s_stock_str *)malloc(sizeof(struct s_stock_str) * (ac + 1));
	if (!ft || ac == 0)
		return (0);
	while (i < ac)
	{
		ft[i].str = malloc(sizeof(char) * 1500);
		ft[i].copy = malloc(sizeof(char) * 1500);
		if (!ft[i].str || !ft[i].copy)
			return (0);
		get_copy(&(ft[i].size), ft[i].str, ft[i].copy, av[i]);
		i += 1;
	}
	ft[i].str = 0;
	return (ft);
}
