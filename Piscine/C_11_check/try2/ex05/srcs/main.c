/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guntkim <guntkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 08:35:32 by guntkim           #+#    #+#             */
/*   Updated: 2022/02/21 09:32:31 by guntkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doop.h"

void	process(int (*calc)(int, int), int num1, int num2)
{
	if (calc == div && num2 == 0)
		ft_putstr("Stop : division by zero\n");
	else if (calc == mod && num2 == 0)
		ft_putstr("Stop : modulo by zero\n");
	else
	{
		ft_putnbr(calc(num1, num2));
		ft_putchar('\n');
	}
}

int	main(int argc, char **argv)
{
	int	(*arr[5])(int, int);

	arr[0] = add;
	arr[1] = sub;
	arr[2] = div;
	arr[3] = mul;
	arr[4] = mod;
	if (argc == 4)
	{
		if (argv[2][0] == '+')
			process(arr[0], ft_atoi(argv[1]), ft_atoi(argv[3]));
		else if (argv[2][0] == '-')
			process(arr[1], ft_atoi(argv[1]), ft_atoi(argv[3]));
		else if (argv[2][0] == '/')
			process(arr[2], ft_atoi(argv[1]), ft_atoi(argv[3]));
		else if (argv[2][0] == '*')
			process(arr[3], ft_atoi(argv[1]), ft_atoi(argv[3]));
		else if (argv[2][0] == '%')
			process(arr[4], ft_atoi(argv[1]), ft_atoi(argv[3]));
		else
			write(1, "0\n", 2);
	}
	return (0);
}
