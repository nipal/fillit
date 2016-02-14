/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windows.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <fjanoty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/14 07:42:03 by fjanoty           #+#    #+#             */
/*   Updated: 2016/02/14 07:42:48 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "add_rm_tetri.h"

unsigned	long	ft_working_window(t_sqare *gr, int x, int y)
{
	unsigned	long	mh;
	unsigned	long	mv;
	unsigned	long	ecr;

	mh = get_vertical_mask(x);
	mv = get_horizontal_mask(y);
	ecr = ((gr->area[0][0] & ~mv & ~mh) >> (x + (8 * y)));
	ecr |= (((gr->area[0][1] & mv & ~mh) >> x) << (8 * (8 - y)));
	ecr |= (((gr->area[1][0] & ~mv & mh) << (8 - x)) >> (8 * y));
	ecr |= ((gr->area[1][1] & mv & mh) << ((8 - x) + (8 * (8 - y))));
	return (ecr);
}

void				ft_init_windows(unsigned long *windows, int stage)
{
	int					i;
	t_sqare				*ground;
	int					nb_win;
	int					x;
	int					y;

	ground = glb_ground(GET, 0);
	nb_win = glb_nb_windows(GET, 0);
	i = 0;
	y = stage * 4;
	while (i < nb_win)
	{
		x = (i * 4);
		windows[i] = ft_working_window(ground, x, y);
		i++;
	}
}
