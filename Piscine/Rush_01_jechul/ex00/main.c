/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykang <ykang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 15:03:14 by guntkim           #+#    #+#             */
/*   Updated: 2022/02/13 18:05:21 by guntkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int		total_chk(int Map[6][6]);
int		dup_chk(int dup_chk_arr[9][5], int row_col, int line_num, int value);
int		dup_chk_assign(int dup_chk_arr[9][5], int x, int y, int value);
int		dup_chk_unassign(int dup_chk_arr[9][5], int x, int y, int vlaue);
int		chk_error_argv(char **argv);
void	set_map_init(char **argv, int Map[6][6]);
void	init_arr(int Map[6][6], int dup_chk_arr[9][5]);

void	put_nbr(int n)
{
	char	c;

	c = n + '0';
	write(1, &c, 1);
}

void	print_map(int Map[][6])
{
	int	i;
	int	j;

	i = 1;
	j = 1;
	while (i < 5)
	{
		j = 1;
		while (j < 5)
		{
			put_nbr(Map[i][j]);
			if (j != 4)
				write(1, " ", 1);
			j += 1;
		}
		write(1, "\n", 1);
		i += 1;
	}
}

void	find_case(int x, int y, int Map[6][6], int dup_chk_arr[9][5])
{
	int	i;

	i = 1;
	if (Map[0][0])
		return ;
	if (x == 4 && y == 5)
	{
		if (total_chk(Map))
		{
			print_map(Map);
			Map[0][0] = 1;
		}
		return ;
	}
	if (y == 5)
	{
		x += 1;
		y = 1;
	}
	while (i <= 4)
	{
		if (dup_chk(dup_chk_arr, 0, x, i) || dup_chk(dup_chk_arr, 1, y, i))
		{
			i += 1;
			continue ;
		}
		Map[x][y] = i;
		dup_chk_assign(dup_chk_arr, x, y, i);
		find_case(x, y + 1, Map, dup_chk_arr);
		dup_chk_unassign(dup_chk_arr, x, y, i);
		i += 1;
	}
	return ;
}

int	main(int argc, char **argv)
{
	int	map[6][6];
	int	dup_chk_arr[9][5];
	int	now[3];

	(void)argc;
	init_arr(map, dup_chk_arr);

	if (!chk_error_argv(argv))
	{
		write(1, "Invalid Input\n", 14);
		write(1, "Example : ./rush-01 '4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2'\n", 54);
		return (0);
	}
	else
		set_map_init(argv, map);
	find_case(1, 1, map, dup_chk_arr);
	if (map[0][0] != 1)
		write(1, "Error\n", 6);
	return (0);
}
