/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guntkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 09:53:19 by guntkim           #+#    #+#             */
/*   Updated: 2022/02/16 12:06:39 by guntkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	get_index(char c, char *base);

int	check_base(const char *base)
{
	int		len;
	int		j;
	char	c;

	len = 0;
	while (base[len])
	{
		c = base[len];
		j = 0;
		while (j < len)
		{
			if (base[j++] == base[len])
				return (-1);
		}
		if (c == '+' || c == '-')
			return (-1);
		if (c == ' ' || c == '\t' || c == '\n'
			|| c == '\v' || c == '\f' || c == '\r')
		   return (-1);	
		len += 1;
	}
	if (len <= 1)
		return (-1);
	return (len);
}

int	atoi_base(char *nbr, char *base_from, int len)
{
	long long	ans;
	int			i;

	i = 0;
	ans = 0;
	while (nbr[i])
	{
		if (get_index(nbr[i], base_from) == -1)
			break ;
		ans = ans * len + get_index(nbr[i], base_from);
		i += 1;
	}
	return (ans);
}

void	itoa(int ans, char *base_to, int *i, char *ft)
{
	int	len;

	len = 0;
	while (base_to[len])
		len += 1;
	if (ans / len)
	{
		itoa(ans / len, base_to, i, ft);
	}
	ft[*i] = base_to[ans % len];
	*i += 1;
}

char	*process_nbr(char *nbr, int *sign)
{
	int	i;

	i = 0;
	while (nbr[i])
	{
		if (nbr[i] == '+' || nbr[i] == '-')
		{
			if (nbr[i] == '-')
				*sign *= -1;
			i += 1;
		}
		else if (nbr[i] == '\t' || nbr[i] == '\n'
			|| nbr[i] == '\v' || nbr[i] == '\f'
			|| nbr[i] == '\r' || nbr[i] == ' ')
			i += 1;
		else
			break ;
	}
	return (&nbr[i]);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		sign;
	char	*ft;
	int		base_from_len;
	int		i;
	int		ans;

	sign = 1;
	i = 0;
	base_from_len = 0;
	ft = (char *)malloc(sizeof(char) * 1500);
	if (check_base(base_from) == -1 || check_base(base_to) == -1)
		return (0);
	while (base_from[base_from_len])
		base_from_len += 1;
	nbr = process_nbr(nbr, &sign);
	ans = atoi_base(nbr, base_from, base_from_len);
	if (sign == -1 && ans != 0)
	{
		ft[i++] = '-';
	}
	itoa(ans, base_to, &(i), ft);
	ft[i] = '\0';
	return (ft);
}
