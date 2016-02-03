/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tetriorder.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboos <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 18:14:15 by tboos             #+#    #+#             */
/*   Updated: 2016/02/03 18:14:51 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "header.h"
#include <stdio.h>

t_tetriminos		*ft_findbegin(t_tetriminos *begin)
{
	while (begin->prev)
		begin = begin->prev;
	return (begin);
}

static t_tetriminos 	*ft_followrightrabbit(t_tetriminos *rabbit, short *i, int *readymade)
{
	short			tmp;

	tmp = *i;
	while (tmp)
	{
		rabbit = rabbit->next;
		tmp--;
	}
	while (rabbit && !(*readymade & rabbit->type))
	{
		rabbit = rabbit->next;
		(*i)++;
	}
	if (rabbit)
		*readymade += rabbit->type;
	return (rabbit);
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
		return (NULL)
	i = 1;
	readymade = 0;
	while (i <= len - stage)
	{
		test = ft_tetriorder(turtle->next, len, stage + 1);
		if (test)
			return (test);
		rabbit = ft_followrightrabbit(turtle, &i, &readymade);
		ft_tetriswap(turtle, rabbit);
		if (rabbit)
			turtle = rabbit;
		i++;
	}
	if (rabbit && !test)
		test = ft_tetriorder(turtle->next, len, stage + 1);
	if (!test)
		ft_reorder(turtle);
	return (test);
}
/*
   0123
   0132
   0213
   0231
   0312
   0321
   1023
   1032
   1203
   1230
   1302
   1320
   2013



   etage 0
   0123
   1023
   2013
   3012

   etage 1
   0123
   0213
   0312

   1023
   1203
   1302

   etage 2
   0123
   0132




*/
