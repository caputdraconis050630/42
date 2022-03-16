/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guntkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 13:52:19 by guntkim           #+#    #+#             */
/*   Updated: 2022/02/17 16:22:59 by guntkim          ###   ########.fr       */
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
	int		j;
	int		i;
	int		min;
	char	*tmp;

	i = 1;
	while (i < argc - 1)
	{
		min = i;
		j = i + 1;
		while (j < argc)
		{
			if (ft_strcmp(argv[j], argv[min]) < 0)
			{
				tmp = argv[j];
				argv[j] = argv[min];
				argv[min] = tmp;
			}
			j += 1;
		}
		i += 1;
	}
	ft_print_argv(argc, argv);
	return (0);
}
