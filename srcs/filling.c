/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filling.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <fjanoty@student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 07:38:47 by fjanoty           #+#    #+#             */
/*   Updated: 2016/02/14 12:42:47 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filling.h"

void			actual_mini_maxi(t_tetriminos *tetris, int i)
{
	int	x;
	int	y;

	x = i % 5;
	y = i / 5;
	if (x < tetris->xp)
		tetris->xp = x;
	if (y < tetris->yp)
		tetris->yp = y;
	if (x > tetris->xd)
		tetris->xd = x;
	if (y > tetris->yd)
		tetris->yd = y;
}

int				first_case(char *str)
{
	int	i;

	i = 0;
	while (i < 20)
	{
		if (i % 5 == 4 && str[i] != '\n')
			return (-1);
		if (i % 5 != 4 && str[i] == '#')
			return (i);
		else if (i % 5 != 4 && str[i] != '.')
			return (-1);
		i++;
	}
	return (i);
}

void			search_the_diese(char *piece, t_tetriminos *tetris
				, int *nb, int i)
{
	unsigned	long	unite;

	unite = 1;
	if (piece[i] == '#')
	{
		piece[i] = '.';
		tetris->valu += unite << (i % 5 + ((i / 5) * 8));
		*nb += 1;
		actual_mini_maxi(tetris, i);
		if (i - 5 >= 0)
			search_the_diese(piece, tetris, nb, i - 5);
		if ((i - 1) % 5 != 4 && (i - 1) >= 0)
			search_the_diese(piece, tetris, nb, i - 1);
		if ((i + 1) % 5 != 0 && (i + 1) % 5 != 4 && (i + 1) < 20)
			search_the_diese(piece, tetris, nb, i + 1);
		if (i + 5 < 20)
			search_the_diese(piece, tetris, nb, i + 5);
	}
	else if (piece[i] != '.')
		tetris->id = 0;
}

int				style_alive(char *str)
{
	int	i;

	i = 0;
	while (i < 20)
	{
		if (str[i] == '#'
		|| (i % 5 == 4 && str[i] != '\n')
		|| (i % 5 != 4 && str[i] != '.'))
			return (1);
		i++;
	}
	return (0);
}
