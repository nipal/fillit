/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_coordone.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <fjanoty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 18:23:53 by fjanoty           #+#    #+#             */
/*   Updated: 2016/02/10 20:12:59 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "coordone.h"

t_coordone		*create_coordone(void)
{
	t_coordone	*position;

	if (!(position = (t_coordone*)malloc(sizeof(t_coordone))))
		return (NULL);
	position->x = 0;
	position->y = 0;
	return (position);
}

t_coordone		*create_coordone_y(int y)
{
	t_coordone	*position;

	if (!(position = (t_coordone*)malloc(sizeof(t_coordone))))
		return (NULL);
	position->x = 0;
	position->y = y;
	return (position);
}

void			copy_coordone(t_coordone *pos_dst, t_coordone *pos_src1, t_coordone *pos_src2)
{
	pos_dst->x = pos_src1->x + (pos_src2->x * 4);
	pos_dst->y = pos_src1->y + (pos_src2->y * 4);
}
