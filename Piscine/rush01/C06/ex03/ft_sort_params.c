/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guntkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 14:50:07 by guntkim           #+#    #+#             */
/*   Updated: 2022/02/10 18:48:01 by guntkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_str_swap(char **s1, char **s2)
{
	char *tmp;
	
	tmp = *s1;
	*s1 = *s2;
	*s2 = tmp;
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
	{
		i += 1;
	}
	return (s1[i] - s2[i]);
}i

int	main(int argc, char **argv)
{
	int	i;
	int	j;
	int	len;

	len = argc - 1;
	i = len - 1
	while (i > 0)
	{	
		j = 0;
		while (j < i)
		{
			if (ft_strcmp(argv[j], argv[j + 1] > 0)
				ft_str_swap(&argv[j], &argv[j + 1]);
			j += 1;
		i -= 1;
	}
	i = 1;
	while (i <= len)
	{
		j = 0;
		while (argv[i][j])
		{
			write(1, &argv[i][j], 1);
		}
		write(1, "\n", 1);	
	}
}

