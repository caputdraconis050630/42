/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guntkim <guntkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 14:00:33 by guntkim           #+#    #+#             */
/*   Updated: 2022/02/03 18:11:12 by guntkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_print_alphabet(void);

void ft_print_alphabet(void){
	char a = 'a';
	while(a  <= 'z'){
		write(1, &a, 1);
	   	a+=1;
	}
}

