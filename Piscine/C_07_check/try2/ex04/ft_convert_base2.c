/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guntkim <guntkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 11:03:33 by guntkim           #+#    #+#             */
/*   Updated: 2022/02/20 11:03:54 by guntkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_there(char *base, char c)
{
	int	i;

	i = 0;
	while (base[i] && base[i] != c)
	{
		i += 1;
	}
	if (base[i] == c)
		return (1);
	return (0);
}

char	*preprocess_str(char *str, int *sign)
{
	int	i;

	i = 0;
	while (str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\f'
		|| str[i] == '\r' || str[i] == ' ')
		i += 1;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			*sign *= -1;
		i += 1;
	}
	return (&str[i]);
}

int	ft_atoi_base(char *str, char *base, int len)
{
	int			sign;
	int			i;
	int			j;
	long long	ans;

	sign = 1;
	ans = 0;
	i = 0;
	str = preprocess_str(str, &sign);
	while (str[i] && is_there(base, str[i]))
	{
		j = 0;
		while (str[i] != base[j])
			j += 1;
		if (str[i] == base[j])
			ans = ans * len + j;
		else
			return (0);
		i += 1;
	}
	return (sign * ans);
}
