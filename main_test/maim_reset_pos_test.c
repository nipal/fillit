/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maim_reset_pos_test.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <fjanoty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/06 17:00:03 by fjanoty           #+#    #+#             */
/*   Updated: 2016/02/06 17:30:42 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "manip_bin.h"
#include "tetriminos.h"
#include "debug.h"
#include "coordone.h"

t_tetriminos	*init_tetri()
{
	int				i;
	t_tetriminos	*tetri;

	tetri = create_tetriminos(0);
	tetri->valu = 1 + 2 + 512 + 1024;
	tetri->id = 'A';
	tetri->type = 1;
	tetri->gap = 0;
	tetri->dim = create_coordone();
	tetri->pos = create_coordone();
	tetri->dim->x = 3;
	tetri->dim->y = 2;
	tetri->pos->x = 1;
	tetri->pos->y = 1;
	tetri->next = 0;
	tetri->prev = 0;
	return (tetri);
}

int	main(void)
{
	t_tetriminos	*tetri;

	tetri = init_tetri();
	print_tetris(tetri);
	ft_resting_posx(tetri, 0);
	ft_resting_posy(tetri, 0);
	print_tetris(tetri);
	return (0);
}
