/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tetriorder.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboos <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 18:14:15 by tboos             #+#    #+#             */
/*   Updated: 2016/02/14 17:21:30 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static t_tetriminos			*ft_findbegin(t_tetriminos *begin)
{
	while (begin->prev)
		begin = begin->prev;
	return (begin);
}

static t_tetriminos 	*ft_get_to_swap(t_tetriminos *rabbit
						, short *i, int *readymade)
{
	short			tmp;

	tmp = *i;
	while (tmp && rabbit)
	{
		rabbit = rabbit->next;
		tmp--;
	}
	while (rabbit && (*readymade & rabbit->type))
	{
		rabbit = rabbit->next;
		(*i)++;
	}
	if (rabbit)
		*readymade += rabbit->type;
	return (rabbit);
}

int	increm_tetris(t_tetriminos *elem)
{
	elem->pos->x += 1;
	elem->valu <<= 1;
	return (ft_push_tetriminos(elem));
}

t_tetriminos			*ft_tetriorder(t_tetriminos *turtle
						, int len, int stage, int i)
{
	int				readymade;
	t_tetriminos	*rabbit;
	t_tetriminos	*test;

	if (stage == len && ft_push_tetriminos(turtle))
		return (ft_findbegin(turtle));
	else if (stage == len)
		return (ft_reorder(turtle));
	readymade = 0;
	while (++i <= len - stage || rabbit)
	{
		if (ft_push_tetriminos(turtle))
		{
			if ((test = ft_tetriorder(turtle->next, len, stage + 1, 0)))
				return (test);
			else if (stage == 0 && increm_tetris(turtle)
					&& (test = ft_tetriorder(turtle->next, len, stage + 1, 0)))
						return (test);
		}
		else
			return (ft_reorder(turtle));
		ft_tetriswap(turtle, (rabbit = ft_get_to_swap(turtle, &i, &readymade)));
		turtle = (rabbit) ? rabbit : turtle;
	}
	return (ft_reorder(turtle));
}

t_tetriminos			*ft_squ_lunch(t_tetriminos *begin, int len)
{
	int				i;
	int				j;
	int				sq;
	t_tetriminos	*result;

	i = (len + 1) * 4;
	j = 1;
	sq = 0;
	while (i > 0)
	{
		i = i - j;
		j += 2;
		sq++;
	}
	while (sq < 16)
	{
		glb_sqr_dim(SET, sq);
		if((result = ft_tetriorder(begin, len, 0, 0)))
			return (result);
		sq++;
	}
	return (NULL);
}
