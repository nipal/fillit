/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_rm_tetri.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <fjanoty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 22:11:42 by fjanoty           #+#    #+#             */
/*   Updated: 2016/02/14 16:17:51 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "add_rm_tetri.h"

int		ft_last_loop(t_tetriminos *elem, int dim, unsigned long *windows)
{
	while ((X < 8 - DIM_X) && X + (4 * ECR_X) < dim - DIM_X)
	{
		if ((elem->valu & windows[ECR_X]) == 0)
		{
			ft_set_tetris(elem, ECR_X, ECR_Y);
			return (1);
		}
		elem->valu <<= 1;
		(X)++;
	}
	(ECR_X)++;
	ft_resting_posx(elem);
	return (0);
}

void	ft_init_pos(t_tetriminos *elem)
{
	t_tetriminos *prev;

	prev = elem->prev;
	if (prev)
	{
		if ((prev->pos->x + elem->dim->x) < 8)
			elem->pos->x = prev->pos->x;
		else
			elem->pos->x = 8 - elem->dim->x;
		if ((prev->pos->y + elem->dim->y) < 8)
			elem->pos->y = prev->pos->y;
		else
			elem->pos->y = 8 - elem->dim->y;
		elem->ecr->x = prev->ecr->x;
		elem->ecr->y = prev->ecr->y;
		elem->valu <<= elem->pos->x + (8 * elem->pos->y);
	}
}

void	ft_end_push(t_tetriminos *elem)
{
		ft_resting_posy(elem);
		ft_resting_posx(elem);
		(ECR_Y)++;
}

int		ft_push_tetriminos(t_tetriminos *elem)
{
	unsigned	long	windows[3];
	int					nb_windows;
	int					dim;

	nb_windows = glb_nb_windows(GET, 0);
	dim = glb_sqr_dim(GET, 0);
	ft_init_pos(elem);
	while (ECR_Y < nb_windows)
	{
		ft_init_windows(windows, ECR_Y);
		while ((Y < 8 - DIM_Y) && Y + (4 * ECR_Y) < dim - DIM_Y)
		{
			while(ECR_X < nb_windows)
			{
				if (ft_last_loop(elem, dim, windows))
					return (1);
			}
			ECR_X = 0;
			elem->valu <<= 8;
			(Y)++;
		}
		ft_end_push(elem);
	}
	ECR_Y = 0;
	return ((ECR_X = 0));
}
