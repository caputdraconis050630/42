/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guntkim <guntkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 14:48:01 by guntkim           #+#    #+#             */
/*   Updated: 2022/02/19 21:00:06 by guntkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		base_to_int(char *nbr, char *base_from);
void	int_to_base(int ans, char *base_to, char *ft, int *i);

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len += 1;
	return (len);
}

char	*process_nbr(char *nbr, int *sign)
{
	int	i;

	i = 0;
	while (nbr[i] == '\t' || nbr[i] == '\n'\
		|| nbr[i] == '\v' || nbr[i] == '\f'\
		|| nbr[i] == '\r' || nbr[i] == ' ')
		i += 1;
	while (nbr[i] == '+' || nbr[i] == '-')
	{
		if (nbr[i] == '-')
			*sign *= -1;
		i += 1;
	}
	return (nbr);
}

int	check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		j = 0;
		while (j < i)
		{
			if (base[j++] == base[i])
				return (1);
		}
		if (base[i] == '+' || base[i] == '-')
			return (1);
		i += 1;
	}
	return (0);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	*ft;
	int		sign;
	int		i;
	int		ans;

	sign = 1;
	i = 0;
	ft = (char *)malloc(sizeof(char) * 600);
	if (!ft)
		return (0);
	if (check_base(base_from) || check_base(base_to))
		return (0);
	nbr = process_nbr(nbr, &sign);
	ans = base_to_int(nbr, base_from);
	if (sign == -1)
		ft[0] = '-';
	int_to_base(ans, base_to, ft, &i);
	ft[i] = '\0';
	return (ft);
}
