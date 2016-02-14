/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square_result.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <fjanoty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 18:23:53 by fjanoty           #+#    #+#             */
/*   Updated: 2016/02/14 16:19:38 by fjanoty          ###   ########.fr       */
/*                                                                            */
/*                                                                            */
/* ************************************************************************** */

#include "square_result.h"

t_sqare	*ft_create_square(void)
{
	t_sqare	*ground;
	int		i;
	int		j;

	ground = (t_sqare*)malloc(sizeof(t_sqare));
	if (!ground)
		return (NULL);
	ground->area = (unsigned long **)malloc(sizeof(unsigned long *) * 2);
	if (!ground->area)
		return (NULL);
	i = 0;
	while (i < 2)
	{
		j = -1;
		ground->area[i] = (unsigned long *)malloc(sizeof(unsigned long) * 2);
		if (!ground->area[i])
			return (NULL);
		while (++j < 2)
			ground->area[i][j] = 0;
		i++;
	}
	ground->dim = 0;
	return (ground);
}
