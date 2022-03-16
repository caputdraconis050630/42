/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guntkim <guntkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 08:39:57 by guntkim           #+#    #+#             */
/*   Updated: 2022/02/21 08:43:04 by guntkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOOP_H
# define DOOP_H

# include <unistd.h>

int		ft_atoi(char *str);
int		add(int num1, int num2);
int		sub(int num1, int num2);
int		div(int num1, int num2);
int		mul(int num1, int num2);
int		mod(int num1, int num2);
void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putnbr(int nb);
void	process(int (*calc)(int, int), int num1, int num2);
#endif
