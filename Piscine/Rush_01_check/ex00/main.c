/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guntkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 15:03:14 by guntkim           #+#    #+#             */
/*   Updated: 2022/02/12 20:14:32 by guntkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	chk_ganeung(int **Map)
{
	if (!row_up_chk(Map))
		return (0);
	if (!row_down_chk(Map))
		return (0);
	if (!col_left_chk(Map))
		return (0);
	if (!col_right_chk(Map))
		return (0);
	return (1);
}

void	init_arr(int **Map, int **col_ud, int **row_lr)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (i < 4)
	{
		while (j < 5)
		{
			col_ud[i][j] = 0;
			row_lr[i][j] = 0;
			j += 1;
		}
		i += 1;
	}
	i = j = 0;
	while (i < 6)
	{	
		j = 0;
		while (j < 6)
			map[i][j++] = 0;
		i += 1;
	}
}

void	print_map(int **map)
{
	int	i;
	int	j;

	i = 1;
	j = 1;
	while (i < 5)
	{
		while (j < 5)
		{
			write(1, &map[i][j], 1);
			if (j != 4)
				write(1, " ", 1);
			j += 1;
		}
		write(1, "\n", 1);
		i += 1;
	}
}

void	find_case(int now[2], int **Map, int **col_ud, int **row_lr)
{
	int	i;

	i = 1;
	if (now[0] == 4 && now[1] == 5 && chk_ganeung(Map))
	{
		print_map(Map);
		return ;
	}
	if (now[1] == 4)
	{
		now[0] += 1;
		now[1] = 0;
		find_case(now, Map, col_ud, row_lr);
		return ;
	}
	while (i <= 4)
	{
		if (col_ud[now[0]][i] || row_lr[now[1]][i])
			continue;
		Map[now[0]][now[1]] = i;
		col_ud[now[0]][i] = row_lr[now[1]][i] = 1;
		now[1] += 1;
		find_case(now[0], now[1], Map, col_ud, row_lr);
		col_ud[now[0]][i] = row_lr[now[1]][i] = 0;
		i += 1;
	}
}

int	process_input(char **argv)
{
	// Check Invalid Input
	int	i;
	int	num_cnt;
	
	i = 0;
	num_cnt = 0;
	while (argv[1][i])
	{
		if (i % 2 == 0)
		{
			if (! (argv[1][i] >= '1' && argv[1][i] <= '4'))
				return (0);
			num_cnt += 1;
		}
		else
		{
			if (argv[1][i] != ' ')
				return (0);
		}
		i += 1;
	}
}

int	main(int argc, char **argv)
{
	int	Map[6][6];
	int	col_chk[4][5];
	int	row_chk[4][5];
	int	i;
	int	j;
	int position[2];
	int	flag;

	i = 0;
	flag = 0;
	position[0] = position[1] = 0;
	init_arr(Map, col_ud, row_lr);
	if (process_input(argv, col_chk, ))
	{
		write(1, "Invalid Input\n", 6);
		write(1, "Example : ./rush-01 '4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2'", Byte Scale);
		return (0);
	}
	find_case(position, Map, col_ud, row_lr, &flag);
	if (flag == 0)
		write(1, "Error\n", 6);
	return (0);
}
