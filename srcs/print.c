/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <fjanoty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 22:03:34 by fjanoty           #+#    #+#             */
/*   Updated: 2016/02/05 21:36:46 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"
#include <stdio.h>
#include "header.h"
#include "debug.h"

char	*ft_init_str_result()
{
	char	*result;
	int		len;

	len = glb_sqr_dim(GET, 0);
	len = len * (len + 1);
dprintf(1, "len_char_result:%d\n", len);
	if (!(result = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	result[len] = '\0';
	return (result);
}

int	indice_input(t_coordone *pos, t_coordone *indice,int len)
{
	return ((indice->x + pos->x) + ((indice->y + pos->y) * len + 1));
}

char	*ft_get_result(t_coordone *pos, t_coordone *indice, t_tetriminos *elem, int len)
{
	static	char		*result = 0;
	static	int			init = 1;
	unsigned	long	unite;

	if (init && !(init = 0))
		result = ft_init_str_result();
	unite = 1;
	while (indice->y < 4)
	{
		indice->x = 0;
		while (indice->x < 4)
		{
dprintf(1, "val:%ld\n", elem->valu);
			if (elem->valu & unite << (indice->x + (8 * indice->y)))
{
//dprintf(1, "x:%d y:%d\n", );
				result[indice_input(pos, indice, len)] = elem->id;
dprintf(1, "s:%s\n", result);
}
			(indice->x)++;
		}
		(indice->y)++;
	}
	return (result);
}

void	ft_print_result(t_tetriminos *begin)
{
	t_coordone			*pos;
	t_coordone			*indice;
	int					len;
	char	*result;
int	debug = 0;

//print_all_tetris(begin);
if(!begin)
dprintf(1, "ON T'AS NICKER\n");
dprintf(1, "len_tetri:%d\n", ft_tetrilen(begin));
	pos = create_coordone();
	indice = create_coordone();
	len= glb_sqr_dim(GET, 0);
	while (begin)
	{
dprintf(1, "print_piece:%d\n", ++debug);
		copy_coordone(pos, begin->pos);
		ft_resting_posx(begin, 0);
		ft_resting_posx(begin, 0);
		result = ft_get_result(pos, indice, begin, len);
		begin = begin->next;
	}
	ft_putstr(result);
//printf("###############################################:	%s\n", result);
	free(result);
	free(pos);
}
