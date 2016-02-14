/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetriminos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <fjanoty@student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 06:06:49 by fjanoty           #+#    #+#             */
/*   Updated: 2016/02/14 14:01:27 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetriminos.h"

t_tetriminos	*create_tetriminos(int id)
{
	t_tetriminos	*piece;
	if (!(piece = (t_tetriminos*)malloc(sizeof(t_tetriminos))))
		return (NULL);
	piece->id = id + 'A';
	piece->valu = 0;
	piece->xp = 8;
	piece->yp = 8;
	piece->next = NULL;
	piece->prev = NULL;
	return (piece);
}

void				tetris_define_type(t_tetriminos *elem)
{
	int				type_max;
	t_tetriminos	*tetris;
	int				first;
	type_max = 1;
	tetris = elem->prev;
	first = 1;
	while (tetris && tetris->valu != elem->valu)
	{
		first = 0;
		if (tetris->type > type_max)
			type_max = tetris->type;
		tetris = tetris->prev;
	}
	if (tetris)
		elem->type = tetris->type;
	else if (first)
		elem->type = type_max;
	else
		elem->type = type_max << 1;
}

int	tetris_free(t_tetriminos *elem)
{
	t_tetriminos	*save;

	if (elem)
	{
		while (elem)
		{
			save = (elem)->next;
			free(elem);
			elem = save;
		}
	}
	return (1);
}

void			finished_tetriminos(t_tetriminos *tetris)
{
	tetris->gap = (tetris->gap % 5) - tetris->xp; 
	tetris->xd = tetris->xd - tetris->xp + 1;
	tetris->yd = tetris->yd - tetris->yp + 1;
	tetris->valu = tetris->valu >> (tetris->xp + (tetris->yp * 8));
	tetris->xp = 0;
	tetris->yp = 0;
}

t_tetriminos	*tetris_push_front(t_tetriminos *begin, t_tetriminos *elem)
{
	t_tetriminos	*tmp;

	if (begin && elem)
	{
		tmp = begin;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = elem;
		elem->prev = tmp;
		tetris_define_type(elem);
		return (begin);
	}
	else if (elem)
	{
		tetris_define_type(elem);
		return (elem);
	}
	else
		return (NULL);
}


