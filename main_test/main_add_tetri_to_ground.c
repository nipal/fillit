/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_add_tetri_to_ground.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <fjanoty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/07 18:00:17 by fjanoty           #+#    #+#             */
/*   Updated: 2016/02/08 00:54:46 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "debug.h"
#include "add_rm_tetri.h"
#include "manip_bin.h"
#include "tetriminos.h"
#include "coordone.h"
#include "square_result.h"

void	print_all_mask()
{
	int					i;
	t_tetriminos		*tetri;
	
	tetri = create_tetriminos(0);
	i = 0;
	while (i < 9)
	{
		dprintf(1, "mask vertical:%d\n", i);
		tetri->valu = get_vertical_mask(i);
		print_tetris(tetri);
		i++;
	}
	i = 0;
	while (i < 9)
	{
		dprintf(1, "mask horizontal:%d\n", i);
		tetri->valu = get_horizontal_mask(i);
		print_tetris(tetri);
		i++;
	}
	
}

void	make_tetri_1(t_tetriminos *elem, t_coordone *incr)
{
	unsigned	long	alter1;
	unsigned	long	alter2;
	unsigned	long	alter;
	unsigned	long	blc;

	alter1 = 0b10101010;
	alter2 = 0b01010101 << 8;
	alter = (alter1 | alter2);
	blc = (0xf | (0xf << 8) | (0xf << 16) | (0xf << 24));

	elem->valu = (alter) | ((alter) << 16) | ((alter) << 32) |  ((alter) << 48);
	elem->dim->x = 1;
	elem->dim->y = 8;
//	elem->pos->x = incr->x;
	elem->valu = 72340172838076673;
	elem->valu |= 255;

	elem->valu = 0xFFFFFFFFFFFFFFFF;

	elem->valu = 0xf | (0xf << 8) | (0xf << 16) | (0xf << 24);
	elem->valu |= 0xf0 | (0xf0 << 16) ;
	elem->valu |= (alter1 | alter2) << (8 * 4);
	elem->valu |= (alter1 | alter2) << (8 * 6);
	elem->valu ^= (blc << (4 + (8 * 4)));
//	elem->valu |= (0xf0 << 8) | (0xf0 << 24);
}

void	decale_tetri(t_tetriminos *elem, int i, int j)
{
	if (i > 0)
	{
		elem->valu <<= i;
		elem->pos->x += i;
	}
	else
	{
		elem->valu >>= i;
		elem->pos->x -= i;
	}

	if (j > 0)
	{
		elem->valu <<= j * 8;
		elem->pos->y += j;
	}
	else
	{
		elem->valu >>= j * 8;
		elem->pos->x -= j;
	}
}

void	make_tetri_2(t_tetriminos *elem)
{
	unsigned	long	blc;

	blc =( 0xf | (0xf << 8) | (0xf << 16) | (0xf << 24));
	elem->valu = blc;
	decale_tetri(elem, 4, 4);
}

int	main(int ac, char **av)
{
	unsigned	long	*windows;
	t_sqare				*gr;
	t_coordone			*pos;
	t_tetriminos		*tetri_1;

	gr = ft_create_square();
	pos = create_coordone();
	gr->dim = 13;
	glb_ground(SET, gr);
	tetri_1 = create_tetriminos(0);

//enfait la on parle plutot d'ecran cad que c'est une position * 4
	pos->y = 1; 
	pos->x = 1;

//	make_tetri_1(tetri_1, 0);
	make_tetri_2(tetri_1);
	ft_set_tetris(tetri_1, pos->x, pos->y);
//	ft_set_tetris(tetri_1, pos->x, pos->y);
//tetri_1->valu = 0xFFFFFFFFFFFFFFFF;
	print_tetris(tetri_1);

//	tetri_1->valu = ~(tetri_1->valu);
//	print_tetris(tetri_1);
//	ft_remouve_tetris(tetri_1);

	windows = ft_init_windows(pos, 0);
	print_ground(gr);
	print_working_windows(windows);

	free(pos);
//	print_all_mask();
	return (0);
}

/*	Je ve tester le fontion d'ecritre d'un tetriminos dans le ground.
 *	donc la fonction ft_set_tetris()
 *
 * */
