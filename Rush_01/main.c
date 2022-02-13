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
#include <stdio.h> // Delete it
int total_chk(int Map[][6]);
int row_up_chk(int Map[6][6]);
int row_down_chk(int Map[6][6]);
int col_left_chk(int Map[6][6]);
int col_right_chk(int Map[6][6]);

void init_arr(int Map[][6], int col_ud[0][5], int row_lr[][5], int now[3])
{
	int i;
	int j;

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
			Map[i][j++] = 0;
		i += 1;
	}
	now[0] = now[1] = now[2] = 0;
}

void print_map(int Map[][6])
{
	int i;
	int j;

	i = 1;
	j = 1;
	while (i < 5)
	{
		j = 1;
		while (j < 5)
		{
			write(1, &Map[i][j], 1);
			if (j != 4)
				write(1, " ", 1);
			j += 1;
		}
		write(1, "\n", 1);
		i += 1;
	}
}

void find_case(int now[3], int Map[6][6], int col_chk[5][5], int row_chk[5][5])
{
	int i;

	i = 1;
	if (now[2]) // Already Find a case, And Print it
		return;
	if (now[0] == 4 && now[1] == 5)
	{
		if (total_chk(Map))
		{
			print_map(Map);
			now[2] = 1;
		}
		return;
	}
	if (now[1] == 5)
	{
		now[0] += 1;
		now[1] = 1;
		find_case(now, Map, col_chk, row_chk);
		return;
	}
	while (i <= 4)
	{
		if (col_chk[now[0]][i] || row_chk[now[1]][i])
			continue;
		Map[now[0]][now[1]] = i;
		col_chk[now[0]][i] = row_chk[now[1]][i] = 1;
		now[1] += 1;
		find_case(now, Map, col_chk, row_chk);
		col_chk[now[0]][i] = row_chk[now[1]][i] = 0;
		i += 1;
	}
	return;
}

// Check Invalid Argv Input
int chk_error_argv(char **argv)
{
	// Check Invalid Input
	int i;

	i = 0;
	while (argv[1][i] != '\0')
	{
		if (i % 2 == 0)
		{
			if (!(argv[1][i] >= '1' && argv[1][i] <= '4'))
				return (0);
		}
		else
		{
			if (argv[1][i] != ' ')
				return (0);
		}
		i += 1;
	}

	return (1); // Valid argv
}

void set_map_init(char **argv, int Map[6][6])
{
	Map[0][1] = argv[1][0];
	Map[0][2] = argv[1][2];
	Map[0][3] = argv[1][4];
	Map[0][4] = argv[1][6];

	Map[5][1] = argv[1][8];
	Map[5][2] = argv[1][10];
	Map[5][3] = argv[1][12];
	Map[5][4] = argv[1][14];

	Map[1][0] = argv[1][16];
	Map[2][0] = argv[1][18];
	Map[3][0] = argv[1][20];
	Map[4][0] = argv[1][22];

	Map[1][5] = argv[1][24];
	Map[2][5] = argv[1][26];
	Map[3][5] = argv[1][28];
	Map[4][5] = argv[1][30];
	return;
}

int main(int argc, char **argv)
{
	int Map[6][6];
	int col_chk[4][5];
	int row_chk[4][5];
	int now[3];

	init_arr(Map, col_chk, row_chk, now);
	if (!chk_error_argv(argv))
	{
		write(1, "Invalid Input\n", 14);
		write(1, "Example : ./rush-01 '4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2'\n", 54);
		return (0);
	}
	else
		set_map_init(argv, Map);
	// printf("호잇호잇~")
	find_case(now, Map, col_chk, row_chk);
	if (now[2] != 1)
		write(1, "Error\n", 6);
	return (0);
}
