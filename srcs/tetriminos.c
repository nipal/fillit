/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetriminos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <fjanoty@student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 06:06:49 by fjanoty           #+#    #+#             */
/*   Updated: 2016/01/27 06:19:26 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetriminos.h"

t_tetriminos	*create_tetriminos(int id)
{
	t_tetriminos	*piece;
	if (!(piece = (t_tetriminos*)malloc(sizeof(t_tetriminos))))
		return (NULL);
	if (!(piece->dim = create_coordone()) || !(piece->pos = create_coordone()))
		return (NULL);
	piece->id = id + 'A';
	piece->valu = 0;
	piece->pos->x = 8;
	piece->pos->y = 8;
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
	tetris->gap = (tetris->gap % 5) - tetris->pos->x; 
	tetris->dim->x = tetris->dim->x - tetris->pos->x;
	tetris->dim->y = tetris->dim->y - tetris->pos->y;
	tetris->valu = tetris->valu >> (tetris->pos->x + (tetris->pos->y * 8));
	tetris->pos->x = 0;
	tetris->pos->y = 0;
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


