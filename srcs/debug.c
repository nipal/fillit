/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <fjanoty@student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 06:46:52 by fjanoty           #+#    #+#             */
/*   Updated: 2016/01/27 09:29:41 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"

void	print_tetris(t_tetriminos *piece)
{
	int					i;
	int					j;
	unsigned	long	unite;

	unite = 1;
	j = 0;
	while (j < 4)
	{
		i = 0;
		while (i < 4)
		{
			if (piece->valu & (unite << (j * 8 + i)))
				printf("#");
			else
				printf(".");
			i++;
		}
		printf("\n");
		j++;
	}
	printf("\n");
}

void	print_coordone(t_coordone *pos, char *name)
{
	printf("%s	: x:%d\n", name, pos->x);
	printf("%s	: y:%d\n", name, pos->y);
}

void	describe_tetris(t_tetriminos *tetris)
{
	print_tetris(tetris);
	printf("gap		:%d\n", tetris->gap);
//	printf("valu	:%ld\n", (long) tetris->valu);
//	printf("id		:%c\n", tetris->id);
//	printf("type	:%d\n", tetris->type);
//	print_coordone(tetris->dim, "	dim");
//	print_coordone(tetris->pos, "	pos");
}

void	print_all_tetris(t_tetriminos *tetris)
{
	if (tetris)
	{
		describe_tetris(tetris);
		print_all_tetris(tetris->next);
	}
}
