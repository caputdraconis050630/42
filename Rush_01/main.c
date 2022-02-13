/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guntkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 15:03:14 by guntkim           #+#    #+#             */
/*   Updated: 2022/02/13 14:11:37 by guntkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h> // Delete it

int	total_chk(int Map[6][6]);

void init_arr(int Map[6][6], int dup_chk_arr[9][5])
{
	int i;
	int j;

	i = 0;
	while (i < 9)
	{
		j = 1;
		while (j < 5)
		{
			dup_chk_arr[i][j] = 0;
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

void find_case(int x, int y, int Map[6][6], int dup_chk_arr[9][5])
{
	int i;

	i = 1;
	if (Map[0][0]) // Already Find a case, And Print it
		return;
	if (x == 4 && y == 5)
	{

		if (total_chk(Map))
		{
			print_map(Map);
			Map[0][0] = 1; // Set Flag
		}
		return;
	}
	if (y == 5)
	{
		x += 1;
		y = 0;
	}
	while (i <= 4)
	{
		if (duplicate_chk(dup_chk_arr, 0, x, i) || duplicate_chk(dup_chk_arr, 1, y, i))
		{
			i += 1;
			continue;
		}
		Map[x][y] = i;
		dup_chk_assign(dup_chk_arr, x, y, i);
		find_case(x, y + 1, Map, dup_chk_arr);
		dup_chk_unassign(dup_chk_arr, x, y, i);
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
	(void)argc;
	int Map[6][6];
	int dup_chk_arr[9][5];
	int now[3];
	init_arr(Map, dup_chk_arr, now);
	if (!chk_error_argv(argv))
	{
		write(1, "Invalid Input\n", 14);
		write(1, "Example : ./rush-01 '4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2'\n", 54);
		return (0);
	}
	else
		set_map_init(argv, Map);
	find_case(1, 1, Map, dup_chk_arr);
	if (now[2] != 1)
		write(1, "Error\n", 6);
	return (0);
}
