/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guntkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 08:40:29 by guntkim           #+#    #+#             */
/*   Updated: 2022/02/15 20:13:13 by guntkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

void	get_copy(char *copy, char *av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		copy[i] = av[i];
		i += 1;
	}
	return ;
}

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len += 1;
	return (len);
}

struct	s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int					i;
	struct s_stock_str	*ft;

	i = 0;
	ft = (struct s_stock_str *)malloc(sizeof(struct s_stock_str) * (ac + 1));
	if (!ft)
		return (0);
	while (i < ac)
	{
		ft[i].size = ft_strlen(av[i]);
		ft[i].str = av[i];
		ft[i].copy = malloc(sizeof(char) * 1500);
		get_copy(ft[i].copy, av[i]);
		i += 1;
	}
	ft[i].str = 0;
	ft[i].copy = 0;
	return (ft);
}
