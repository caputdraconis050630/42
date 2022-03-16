/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guntkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 09:16:29 by guntkim           #+#    #+#             */
/*   Updated: 2022/02/15 19:22:49 by guntkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"

void	put_nbr(int nbr)
{
	char	c;

	if (nbr > 10)
	{
		put_nbr(nbr / 10);
	}
	c = (nbr % 10) + '0';
	write(1, &c, 1);
}

void	put_str(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i += 1;
	}
	write(1, "\n", 1);
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = 0;
	while (par[i].str != 0)
	{
		put_str(par[i].str);
		put_nbr(par[i].size);
		write(1, "\n", 1);
		put_str(par[i].copy);
		i += 1;
	}
}
