/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tetriorder.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboos <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 18:14:15 by tboos             #+#    #+#             */
/*   Updated: 2016/02/13 23:05:13 by fjanoty          ###   ########.fr       */
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
	elem->pos->x += 1;
	elem->valu <<= 1;
//	print_tetris(elem);
//	print_ground(glb_ground(GET, 0));
	return (0);
}

t_tetriminos			*ft_tetriorder(t_tetriminos *turtle, int len, int stage)
{
	short			i;
	int				readymade;
	t_tetriminos	*rabbit;
	t_tetriminos	*test;

//dprintf(1, "stage:%d ", stage);
//dprintf(1, "%c dim:%d\n", turtle->id, glb_sqr_dim(GET, 0));
	if (stage == len && ft_push_tetriminos(turtle))
		return (ft_findbegin(turtle));
	else if (stage == len)
	{
//		print_ground(glb_ground(GET, 0));
		return (ft_reorder(turtle));
	}
	i = 0;
	readymade = 0;
	rabbit = NULL;
	while (++i <= len - stage || rabbit)
	{
//		printf("%c ", turtle->id);
		if (ft_push_tetriminos(turtle))
		{
			if ((test = ft_tetriorder(turtle->next, len, stage + 1)))
			{
//printf("PUUUUUSH\n");
//dprintf(1, "stage:%d\n", stage);
//dprintf(1, "%c\n", turtle->id);
				return (test);
			}
			else if (stage == 0)
			{
		//		printf("ratee %c\n", turtle->id);
				increm_tetris(turtle);
				if (ft_push_tetriminos(turtle))
				{
		//			printf("");
					test = ft_tetriorder(turtle->next, len, stage + 1);
					if (test)
						return (test);
					else
					{
		//				printf("avant\n");
	//		print_ground(glb_ground(GET, 0));
			//			ft_remouve_tetris(turtle);
	//					printf("apres\n");
	//		print_ground(glb_ground(GET, 0));
					}

	//				print_ground(glb_ground(GET, 0));
				}
			}
		}
		else
		{
//			printf("size:%d\n", glb_sqr_dim(GET, 0));
//			if (turtle->id == 'A')
//			print_ground(glb_ground(GET, 0));
//			if (stage == 0)
//				printf("finish for :%c\n", turtle->id);
			return (ft_reorder(turtle));
		}
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
