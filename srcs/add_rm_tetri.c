/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_rm_tetri.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <fjanoty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 22:11:42 by fjanoty           #+#    #+#             */
/*   Updated: 2016/02/03 22:17:31 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "add_rm_tetri.h"

unsigned	long	ft_working_window(t_sqare *gr, t_coordone *pos
					, unsigned long horizontal, unsigned long vertical)
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
	unsigned	long	windows[3];
	t_sqare				*ground;
	int					nb_win;

	ground = glb_ground(GET, 0);
	nb_win = glb_nb_windows(GET, 0);
	pos = create_coordone_y(stage * 4);
	i = 0;
	while (i < nb_win)
	{
		pos->x = (i * 4);
		windows[i] = ft_working_window(ground, pos, HORIZONTAL, VERTICAL);
		i++;
	}
	free(pos);
	return (wimdows);
}

void	ft_set_tetris(t_tetriminos *elem, t_coordone *pos)
{
	unsigned	long	mh;
	unsigned	long	mv;
	t_sqare				*gr;

	gr = glb_ground(GET, 0);
	pos->x *= 4;
	pos->y *= 4;
	mv = get_vertical_mask(pos->x);
	mh = get_horizontal_mask(pos->y);
	gr->area[0][0] |= (elem->value & ~mh & ~mv) >> (pos->x + (8 * pos->y));
	gr->area[0][1] |= ((elem->value & ~mh & mv) >> pos->x) << (8 * (8 - pos->y));
	gr->area[1][0] |= ((elem->value & mh & ~mv) << (8 - pos->x)) >> (8 * pos->y);
	gr->area[1][1] |= (elem->value & mh & mv) << (8 - pos->x + (8 * (8 - pos->y)));
}

void	ft_remouve_tetris(t_tetriminos *elem)
{
	unsigned	long	mh;
	unsigned	long	mv;
	t_coordone			*pos;
	t_sqare				*gr;

	pos = create_coordone();

	gr = glb_ground(GET, 0);
	pos->x = (elem->pos->x / 4) * 4;
	pos->y = (elem->pos->y / 4) * 4;
	mv = get_vertical_mask(pos->x);
	mh = get_horizontal_mask(pos->y);
	gr->area[0][0] &= ~((elem->value & ~mh & ~mv) >> (pos->x + (8 * pos->y)));
	gr->area[0][1] &= ~(((elem->value & ~mh & mv) >> pos->x) << (8 * (8 - pos->y)));
	gr->area[1][0] &= ~(((elem->value & mh & ~mv) << (8 - pos->x)) >> (8 * pos->y));
	gr->area[1][1] &= ~((elem->value & mh & mv) << (8 - pos->x + (8 * (8 - pos->y))));
	free(pos);
}

int	ft_push_tetriminos(t_tetriminos *elem)
{
	t_coordone			indice;
	unsigned	long	wimdows[3];
	int					nb_windows;

	i = 0;
	pos = create_coordone();
	indice = create_coordone();
	nb_windows = glb_nb_windows(GET, 0);

	windows = ft_init_windows(0, indice->y);
	while (indice->y < nb_windows)
	{
		while ((elem->pos->y < 8 - elem->dim->y) && elem->pox->y + (4 * nb_windows) < glb_sqr_dim(GET, 0) - elem->dim->y)
		{
			while(indice->x < nb_windows)
			{
				while ((elem->pos->x < 8 - elem->dim->x) && elem->pox->x + (4 * nb_windows) < glb_sqr_dim(GET, 0) - elem->dim->x)
				{
					if (elem->value & windows[i] == 0)
					{
						ft_set_tetris(elem, indice);
						free(indice);
						return (1);
					}
					elem->valu <<= 1;
					(elem->pos->x)++;
				}
				ft_resting_posx(elem, (indice->x)++);
			}
			elem->valu <<= 8;
			(elem->pos->y)++;
		}
		ft_resting_posy(elem, (indice->y)++);
	}
	free(pos);
	return (0);
}
