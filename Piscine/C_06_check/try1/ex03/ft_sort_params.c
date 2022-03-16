/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guntkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 13:52:19 by guntkim           #+#    #+#             */
/*   Updated: 2022/02/12 13:52:30 by guntkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i += 1;
	return (s1[i] - s2[i]);
}

void	ft_str_swap(char *s1, char *s2)
{
	char	temp[200];
	int		i;

	i = 0;
	while (s1[i] != '\0')
	{
		temp[i] = s1[i];
		i += 1;
	}
	temp[i] = '\0';
	i = 0;
	while (s2[i] != '\0')
	{
		s1[i] = s2[i];
		i += 1;
	}
	s1[i] = '\0';
	i = 0;
	while (temp[i] != '\0')
	{
		s2[i] = temp[i];
		i += 1;
	}
	s2[i] = '\0';
}

void	ft_print_argv(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			write(1, &argv[i][j], 1);
			j += 1;
		}
		write(1, "\n", 1);
		i += 1;
	}
	return ;
}

int	main(int argc, char **argv)
{
	int	j;
	int	i;

	i = argc - 1;
	while (i)
	{
		j = 1;
		while (j < i)
		{
			if (ft_strcmp(argv[j], argv[j + 1]) > 0)
				ft_str_swap(argv[j], argv[j + 1]);
			j += 1;
		}
		i -= 1;
	}
	ft_print_argv(argc, argv);
	return (0);
}
