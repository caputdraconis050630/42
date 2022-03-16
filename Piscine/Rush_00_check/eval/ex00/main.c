/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guntkim <guntkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 18:30:33 by guntkim           #+#    #+#             */
/*   Updated: 2022/02/06 18:32:45 by guntkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	rush(int x, int y);

int	atoi(const char *ptr)
{
	int			i;
	int			sign;
	long long	n;

	i = 0;
	sign = 1;
	n = 0;
	while (ptr[i] == ' ' || ptr[i] == '\n' || ptr[i] == '\t' || ptr[i] == '\v'
		|| ptr[i] == '\f' || ptr[i] == '\r')
		i++;
	if (ptr[i] == '-')
		sign *= -1;
	if (ptr[i] == '-' || ptr[i] == '+')
		i++;
	while (ptr[i] && ptr[i] >= '0' && ptr[i] <= '9')
	{
		if (n * sign > 2147483647)
			return (-1);
		else if (n * sign < -2147483648)
			return (0);
		else
			n = n * 10 + (ptr[i] - '0');
		i++;
	}
	return (n * sign);
}

int	main(int argc, char **argv)
{
	int	rows;
	int	cols;

	if (argc > 3)
		return (1);
	else if (argc == 3)
	{
		rows = atoi(argv[1]);
		cols = atoi(argv[2]);
	}
	else if (argc == 2)
	{
		rows = atoi(argv[1]);
		cols = atoi(argv[1]);
	}
	else
	{
		rows = 5;
		cols = 5;
	}
	rush(rows, cols);
	return (0);
}
