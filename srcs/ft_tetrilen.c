/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tetrilen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboos <marvin@42.fr> 	                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 21:44:00 by tboos             #+#    #+#             */
/*   Updated: 2016/02/14 16:27:34 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int				ft_tetrilen(t_tetriminos *begin)
{
	short				i;

	i = 0;
	while (begin)
	{
		begin = begin->next;
		i++;
	}
	return (i - 1);
}
