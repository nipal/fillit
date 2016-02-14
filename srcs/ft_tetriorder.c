/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tetriorder.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboos <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 18:14:15 by tboos             #+#    #+#             */
/*   Updated: 2016/02/14 12:41:03 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "header.h"
# include <stdio.h>
# include "debug.h"

static t_tetriminos			*ft_findbegin(t_tetriminos *begin)
{
	while (begin->prev)
		begin = begin->prev;
	return (begin);
}

static t_tetriminos 	*ft_followrightrabbit(t_tetriminos *rabbit, short *i, int *readymade)
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
	elem->xp += 1;
	elem->valu <<= 1;
	return (1);
}

t_tetriminos			*ft_tetriorder(t_tetriminos *turtle, int len, int stage)
{
	short			i;
	int				readymade;
	t_tetriminos	*rabbit;
	t_tetriminos	*test;

	if (stage == len && ft_push_tetriminos(turtle))
		return (ft_findbegin(turtle));
	else if (stage == len)
		return (ft_reorder(turtle));
	i = 0;
	readymade = 0;
	rabbit = NULL;
	while (++i <= len - stage || rabbit)
	{
		if (ft_push_tetriminos(turtle))
		{
			if ((test = ft_tetriorder(turtle->next, len, stage + 1)))
				return (test);
			else if (stage == 0)
			{
				increm_tetris(turtle);
				if (ft_push_tetriminos(turtle))
				{
					test = ft_tetriorder(turtle->next, len, stage + 1);
					if (test)
						return (test);
				}
			}
		}
		else
			return (ft_reorder(turtle));
		rabbit = ft_followrightrabbit(turtle, &i, &readymade);
		ft_tetriswap(turtle, rabbit);
		if (rabbit)
			turtle = rabbit;
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
		if((result = ft_tetriorder(begin, len, 0)))
			return (result);
		sq++;
	}
	return (NULL);
}
