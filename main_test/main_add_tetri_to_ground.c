#include <stdio.h>
#include "debug.h"
#include "add_rm_tetri.h"
#include "manip_bin.h"
#include "tetriminos.h"
#include "coordone.h"
#include "square_result.h"

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
	elem->pos->x = incr;
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
		dprintf(1, "mask horizontl:%d\n", i);
		tetri->valu = get_horizontal_mask(i);
		print_tetris(tetri);
		i++;
	}
	
}

int	main(int ac, char **av)
{
	unsigned	long	*windows;
	t_sqare				*gr;
	t_coordone			*pos;
	t_tetriminos		*tetri_1;

	gr = ft_create_square();
	pos = create_coordone();
	gr->dim = 16;
	glb_ground(SET, gr);
	tetri_1 = create_tetriminos(0);

	pos->y = 2;
	pos->x = 1;

	make_tetri_1(tetri_1);
	ft_set_tetris(tetri_1, pos);
	print_tetris(tetri_1);
	ft_remouve_tetris(tetri_1);

	windows = ft_init_windows(pos, 0);
	print_ground(gr);
	print_working_windows(windows);

//	print_all_mask();
	return (0);
}

/*	Je ve tester le fontion d'ecritre d'un tetriminos dans le ground.
 *	donc la fonction ft_set_tetris()
 *
 * */
