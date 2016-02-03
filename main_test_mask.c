/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test_mask.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 18:20:41 by fjanoty           #+#    #+#             */
/*   Updated: 2016/02/02 18:37:24 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

#include "includes/tetriminos.h"

#define HORIZONTAL 255
#define VERTICAL 72340172838076673

unsigned	long	get_vertical_mask(int size)
{
	static	unsigned	long	masks[9];
	static	int					init = 1;
	unsigned	long			vertical;
	int							i;
	int							j;

	if (init)
	{
		init = 0;
		vertical = VERTICAL;
		j = 0;
		while (j < 9)
		{
			i = 0;
			masks[j] = 0;
			while (i < j)
			{
				masks[j] |= vertical << i;
				i++;
			}
			j++;
		} 
	}
	return (masks[size]);
}

unsigned	long	get_horizontal_mask(int size)
{
	static	unsigned	long	masks[9];
	static	int					init = 1;
	unsigned	long			horizontal;
	int							i;
	int							j;

	if (init)
	{
		init = 0;
		horizontal = HORIZONTAL;
		j = 0;
		while (j < 9)
		{
			i = 0;
			masks[j] = 0;
			while (i < j)
			{
				masks[j] |= horizontal << (i * 8);
				i++;
			}
			j++;
		} 
	}
	return (masks[size]);
}

void	print_tetris(unsigned long piece)
{
	int					i;
	int					j;
	unsigned	long	unite;

	printf("\n");
	unite = 1;
	j = 0;
	while (j < 8)
	{
		i = 0;
		while (i < 8)
		{
			if (piece & (unite << (j * 8 + i)))
				printf("#");
			else
				printf(".");
			i++;
		}
		printf("\n");
		j++;
	}
}

int		main(int ac, char **av)
{
	int i = 0;

	while (i < 9)
	{
		printf("\nsize:%d", i);
		print_tetris(get_vertical_mask(i));
		print_tetris(get_horizontal_mask(i));
		i++;
	}
	return (0);
}
