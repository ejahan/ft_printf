/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elisa <elisa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 15:25:52 by ejahan            #+#    #+#             */
/*   Updated: 2021/02/19 16:52:08 by elisa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	(void)ac;
	(void)av;
	int		size_original;
	int		size_mine;
	//char	*str = NULL;
	void	*ptr;

	ptr = NULL;
	size_original = printf("ORIG => [%5.p]\n", ptr);
	size_mine = ft_printf("MINE => [%5.p]\n", ptr);
	printf("ORIG [%d]\n", size_original);
	printf("MINE [%d]\n", size_mine);
	if (size_original == size_mine)
		printf("\033[1;32m-> OK  :)\033[0m\n");
	else
		printf("\033[1;31m-> KO  :(\033[0m\n");
	return (0);
}

/*
		c	 -->	conversion + flags		>>>OK<<<
		s	 -->	conversion + flags		>>>OK<<<
		d	 -->	conversion + flags		>>>OK<<<
		p	 -->	conversion + flags		>>>OK<<<
		u	 -->	conversion + flags		>>>OK<<<
		x	 -->	conversion + flags		>>>OK<<<
		X	 -->	conversion + flags		>>>OK<<<
		%	 -->	conversion + flags		>>>OK<<<
*/
