/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_rm_tetri.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <fjanoty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 22:11:42 by fjanoty           #+#    #+#             */
/*   Updated: 2016/02/07 03:54:51 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "add_rm_tetri.h"
#include "debug.h"
#include <stdio.h>

/*area[x][y]*/
unsigned	long	ft_working_window(t_sqare *gr, t_coordone *pos)
{
	unsigned	long	mh;
	unsigned	long	mv;
	unsigned	long	ecr;

	mh = get_horizontal_mask(pos->x);
	mv = get_horizontal_mask(pos->y);
	ecr = ((gr->area[0][0] & ~mv & ~mh) >> (pos->x + (8 * pos->y)));
	ecr |= (((gr->area[0][1] & ~mv & mh) >> pos->x) << (8 * (8 - pos->y)));
	ecr |= (((gr->area[1][0] & mv & ~mh) << (8 - pos->x)) >> (8 * (pos->y)));
	ecr |= ((gr->area[1][1] & mv & mh) << ((8 - pos->x) + (8 * (8 - pos->y))));
	return (ecr);
}

unsigned	long	*ft_init_windows(t_coordone *pos, int stage)
{
	int					i;
	unsigned	long	*windows;
	t_sqare				*ground;
	int					nb_win;

	ground = glb_ground(GET, 0);
	nb_win = glb_nb_windows(GET, 0);
	pos = create_coordone_y(stage * 4);
	windows = (unsigned long *) malloc(sizeof(unsigned long) * 3);
	i = 0;
	while (i < nb_win)
	{
		pos->x = (i * 4);
		windows[i] = ft_working_window(ground, pos);
		i++;
	}
	free(pos);
	return (windows);
}

int		ft_set_tetris(t_tetriminos *t, t_coordone *pos)
{
	unsigned	long	mh;
	unsigned	long	mv;
	t_sqare				*gr;

	gr = glb_ground(GET, 0);
	pos->x *= 4;
	pos->y *= 4;
	mv = get_vertical_mask(pos->x);
	mh = get_horizontal_mask(pos->y);
	gr->area[0][0] |= (t->valu & ~mv & ~mh) >> (pos->x + (8 * pos->y));
	gr->area[0][1] |= ((t->valu & ~mv & mh) >> pos->x) << (8 * (8 - pos->y));
	gr->area[1][0] |= ((t->valu & mv & ~mh) << (8 - pos->x)) >> (8 * pos->y);
	gr->area[1][1] |= (t->valu & mv & mh) << (8 - pos->x + (8 * (8 - pos->y)));
//dprintf(1, "####################\n");
//print_ground(gr);
	return (1);
}

void	ft_remouve_tetris(t_tetriminos *t)
{
	unsigned	long	mh;
	unsigned	long	mv;
	t_coordone			*p;
	t_sqare				*gr;

	p = create_coordone();

	gr = glb_ground(GET, 0);
	p->x = (t->pos->x / 4) * 4;
	p->y = (t->pos->y / 4) * 4;
	mv = get_vertical_mask(p->x);
	mh = get_horizontal_mask(p->y);
	gr->area[0][0] &= ~((t->valu & ~mv & ~mh) >> (p->x + (8 * p->y)));
	gr->area[0][1] &= ~(((t->valu & ~mv & mh) >> p->x) << (8 * (8 - p->y)));
	gr->area[1][0] &= ~(((t->valu & mv & ~mh) << (8 - p->x)) >> (8 * p->y));
	gr->area[1][1] &= ~((t->valu & mv & mh) << (8 - p->x + (8 * (8 - p->y))));
	free(p);
}

static	int		my_free(t_coordone *indice)
{
	free(indice);
	return (1);
}

int		ft_last_loop(t_tetriminos *elem, t_coordone *indice, int dim
		, unsigned long *windows)
{
	while ((X < 8 - DIM_X) && X + (4 * IND_X) < dim - DIM_X)
	{
		if (((elem->valu & windows[IND_X]) == 0)
			&& ft_set_tetris(elem, indice) && my_free(indice))
		{
dprintf(1 , "%c MATCH IN   x:%d y:%d	", elem->id, X, Y);
dprintf(1, "e->val:%ld & w->val:%ld = %ld\n", elem->valu, windows[IND_X], (elem->valu & windows[IND_X]));
			X += IND_X * 4;
			Y += IND_Y * 4;
			return (1);
		}
		elem->valu <<= 1;
		(X)++;
	}
	(IND_X)++;
/*
if (IND_Y == nb_windows - 1 && IND_X == )
{
dprintf(1, "fail:%c\n", elem->id);
//print_tetris(elem);
}
//*/
	ft_resting_posx(elem, 0);
	return (0);
}

int	ft_push_tetriminos(t_tetriminos *elem)
{
	t_coordone			*indice;
	unsigned	long	*windows;
	int					nb_windows;
	int					dim;

//dprintf(1, "push-->id:%c\n", elem->id);
	indice = create_coordone();
	nb_windows = glb_nb_windows(GET, 0);
	dim = glb_sqr_dim(GET, 0);
dprintf(1, "		push_dim:%d\n", dim);
dprintf(1, "		nb_win:%d\n", nb_windows);
	while (IND_Y < nb_windows)
	{
		windows = ft_init_windows(0, IND_Y);
		while ((Y < 8 - DIM_Y) && Y + (4 * IND_Y) < dim - DIM_Y)
		{
			while(IND_X < nb_windows)
				if (ft_last_loop(elem, indice, dim, windows))
					return (1);
			elem->valu <<= 8;
			(Y)++;
		}
		(IND_Y)++;
		ft_resting_posy(elem, 0);
	}
	free(windows);
	free(indice);
	return (0);
}
