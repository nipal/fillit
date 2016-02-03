/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <fjanoty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 22:03:34 by fjanoty           #+#    #+#             */
/*   Updated: 2016/02/03 22:11:21 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

char	*ft_init_str_result()
{
	char	*reslut;
	int		len;
	int		i;

	len = glb_sqr_dim(GET, 0);
	len = len * (len + 1);
	if (!(result = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	resut[len] = '\0';
}

int	indice_input(t_coordone *pos, t_coordone *ind, int len)
{
	return ((indice->x + pos->x) + ((indice->y + pos->y) * len + 1));
}

char	*ft_get_result(t_coordone *pos, t_coordone *indice, t_tetriminos *elem, int len)
{
	static	char		*result = 0;
	static	int			init = 1;
	unsigned	double	unite;

	if (init)
		result = ft_init_str_result();
	unite = 1;
	while (indice->y < 4)
	{
		indice->x = 0;
		while (indice->x < 4)
		{
			if (elem->valu & unite << (indice->x + (8 * indice->y)))
				result[indice_input(pos, indice, len)] = elem->id;
			(indice->x)++;
		}
		(indice->y)++;
	}
	return (result);
}

void	ft_print_resut(t_tetriminos *begin)
{
	t_coordone			*pos;
	t_coordone			*indice;
	int					len;

	pos = create_coordone();
	indice = create_coordone();
	len= glb_sqr_dim(GET, 0);
	while (begin)
	{
		copy_coordone(pos, begin->pos);
		ft_resting_posx(begin, 0);
		ft_resting_posx(begin, 0);
		result = ft_get_result(pos, indice, begin, len);
		begin = begin->next;
	}
	ft_putsrt(result);
	free(result);
	free(pos);
	free(pos);
}
