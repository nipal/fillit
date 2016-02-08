/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_rm_tetri.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <fjanoty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 22:11:42 by fjanoty           #+#    #+#             */
/*   Updated: 2016/02/08 17:31:25 by fjanoty          ###   ########.fr       */
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

	mh = get_vertical_mask(pos->x);
	mv = get_horizontal_mask(pos->y);
	ecr = ((gr->area[0][0] & ~mv & ~mh) >> (pos->x + (8 * pos->y)));
	ecr |= (((gr->area[0][1] & mv & ~mh) >> pos->x) << (8 * (8 - pos->y)));
	ecr |= (((gr->area[1][0] & ~mv & mh) << (8 - pos->x)) >> (8 * (pos->y)));
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

int		ft_set_tetris(t_tetriminos *t, int x, int y)
{
	unsigned	long	mh;
	unsigned	long	mv;
	t_sqare				*gr;

	gr = glb_ground(GET, 0);
	x *= 4;
	y *= 4;
	mv = get_vertical_mask(8 - x);
	mh = get_horizontal_mask(8 - y);
	gr->area[0][0] ^= (t->valu & mv & mh) << (x + (8 * y));
	gr->area[0][1] ^= ((t->valu & mv & ~mh) << x) >> (8 * (8 - y ));
	gr->area[1][0] ^= ((t->valu & ~mv & mh) >> (8 - x)) << (8 * y);
	gr->area[1][1] ^= (t->valu & ~mv & ~mh) >> (8 - x + (8 * (8 - y)));
	return (1);
}

void	ft_remouve_tetris(t_tetriminos *tetri)
{
	ft_set_tetris(tetri, tetri->ecr->x, tetri->ecr->y);
	ft_resting_posx(tetri);
	ft_resting_posy(tetri);
	tetri->ecr->x = 0;
	tetri->ecr->y = 0;
}

int		ft_last_loop(t_tetriminos *elem, int dim, unsigned long *windows)
{
	while ((X < 8 - DIM_X) && X + (4 * ECR_X) < dim - DIM_X)
	{
		if (((elem->valu & windows[ECR_X]) == 0)
			&& ft_set_tetris(elem, ECR_X, ECR_Y))
			return (1);
		elem->valu <<= 1;
		(X)++;
	}
	(ECR_X)++;
	ft_resting_posx(elem);
	return (0);
}

int	ft_push_tetriminos(t_tetriminos *elem)
{
	unsigned	long	*windows;
	int					nb_windows;
	int					dim;

	nb_windows = glb_nb_windows(GET, 0);
	dim = glb_sqr_dim(GET, 0);
	while (ECR_Y < nb_windows)
	{
		windows = ft_init_windows(0, ECR_Y);
		while ((Y < 8 - DIM_Y) && Y + (4 * ECR_Y) < dim - DIM_Y)
		{
			while(ECR_X < nb_windows)
				if (ft_last_loop(elem, dim, windows))
					return (1);
			elem->valu <<= 8;
			(Y)++;
		}
		(ECR_Y)++;
		ft_resting_posy(elem);
	}
//	free(windows);
	return (0);
}
