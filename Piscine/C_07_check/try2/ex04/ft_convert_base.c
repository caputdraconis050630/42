/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guntkim <guntkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 11:04:24 by guntkim           #+#    #+#             */
/*   Updated: 2022/02/20 12:36:56 by guntkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_atoi_base(char *str, char *base, int len);

int	check_base(char *base)
{
	int	i;
	int	j;
	int	len;

	len = 0;
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
		if ((base[i] >= 9 && base[i] <= 13) || base[i] == 32)
			return (1);
		i += 1;
		len += 1;
	}
	if (len <= 1)
		return (1);
	return (0);
}

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len += 1;
	return (len);
}

void	nbr_base(int num, char *ft, int *i, char *base_to)
{
	if (num >= ft_strlen(base_to))
		nbr_base(num / ft_strlen(base_to), ft, i, base_to);
	ft[*i] = base_to[num % ft_strlen(base_to)];
	(*i) += 1;
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char		*ft;
	long long	num;
	int			i;

	i = 0;
	ft = (char *)malloc(sizeof(char) * 4096);
	if (!ft || check_base(base_from) || check_base(base_to))
		return (0);
	num = ft_atoi_base(nbr, base_from, ft_strlen(base_from));
	if (num < 0)
	{
		num *= -1;
		ft[i++] = '-';
	}
	nbr_base(num, ft, &i, base_to);
	ft[i] = '\0';
	return (ft);
}
