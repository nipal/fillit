/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetriminos.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <fjanoty@student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 06:15:34 by fjanoty           #+#    #+#             */
/*   Updated: 2016/02/08 00:45:31 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TETRIMINOS_H
# define TETRIMINOS_H

# include <stdlib.h>
# include "coordone.h"
# include "error.h"

/*	dim: dimentionde la piece	*/
/*	pos: nombre de decalage que la piece a subi	*/
/*	ecr: numerot quand on pushle tetri	*/
typedef	struct s_tetriminos	t_tetriminos;
struct				s_tetriminos
{
	t_tetriminos	*next;
	t_tetriminos	*prev;
	unsigned long	valu;
	char			id;
	int				type;
	int				gap;
	t_coordone		*dim;
	t_coordone		*pos;
	t_coordone		*ecr;
};

t_tetriminos		*create_tetriminos(int id);
void				tetris_define_type(t_tetriminos *elem);
int					tetris_free(t_tetriminos *elem);
t_tetriminos		*tetris_push_front(t_tetriminos *begin, t_tetriminos *elem);
void				finished_tetriminos(t_tetriminos *tetris);

#endif
