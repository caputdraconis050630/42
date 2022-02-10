/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guntkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 14:01:19 by guntkim           #+#    #+#             */
/*   Updated: 2022/02/10 14:06:34 by guntkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	len;
	int	j;

	len = 0;
	while (argv[len])
		len += 1;
	while (--len)
	{
		j = 0;
		while (argv[len][j])
		{
			write(1, &argv[len][j], 1);
			j += 1;
		}
		write(1, "\n", 1);	
	}
}
