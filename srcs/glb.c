/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 21:51:14 by fjanoty           #+#    #+#             */
/*   Updated: 2016/02/05 04:24:14 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "glb.h"

int		glb_nb_windows(int mode, int sqr_dim)
{
	static	int	nb_windows = 1;

	if (mode & GET)
		return (nb_windows);
	else if (mode & SET)
	{
		nb_windows = (sqr_dim <= 12) ? 2 : 3;
		nb_windows = (sqr_dim <= 8) ? 1 : nb_windows;
		return (nb_windows);
	}
	else
		return (1);
}

int		glb_sqr_dim(int mode, int value)
{
	static	int	sqr_dim = 1;
	t_sqare		*ground;

	if (mode & GET)
		return (sqr_dim);
	else if (mode & SET)
	{
		ground = glb_ground(GET, 0);
		ground->dim = value;
		glb_nb_windows(SET, value);
		sqr_dim = value;
		return (sqr_dim);
	}
	else
		return (1);
}

t_sqare	*glb_ground(int mode, t_sqare *value)
{
	static	t_sqare	*ground;

	if (mode & GET)
		return (ground);
	else if (mode & SET)
	{
		ground = value;
		glb_sqr_dim(SET, ground->dim);
		return (ground);
	}
	else
		return (NULL);
}
