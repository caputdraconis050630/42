/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guntkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 12:33:38 by guntkim           #+#    #+#             */
/*   Updated: 2022/02/08 13:19:40 by guntkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	process_num(char *str, long long num, int sign)
{
	int	i;

	i = 0;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		if (num * sign > 2147483647)
			return (-1);
		else if (num * sign < -2147483648)
			return (0);
		else
			num = num * 10 + (str[i] - '0');
		i++;
	}
	return (num * sign);
}

void	process_minus(int minus, int *sign)
{
	if (minus % 2)
		*sign = -1;
}

int	is_space(char c)
{
	if (c == '\f')
		return (1);
	if (c == '\n')
		return (1);
	if (c == '\v')
		return (1);
	if (c == '\t')
		return (1);
	if (c == '\r')
		return (1);
	if (c == ' ')
		return (1);
	return (0);	
}
int	ft_atoi(char *str)
{
	int			i;
	int			minus;
	int			sign;
	long long	num;

	i = 0;
	sign = 1;
	minus = 0;
	num = 0;
	while (is_space(str[i]))
		i += 1;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			minus += 1;
		i += 1;
	}
	process_minus(minus, &sign);
	return process_num(&str[i], num, sign);
}
