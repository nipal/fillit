/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_rm_tetri.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <fjanoty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 19:09:50 by fjanoty           #+#    #+#             */
/*   Updated: 2016/02/05 06:27:33 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ADD_RM_TETRI_H
# define ADD_RM_TETRI_H

# include "square_result.h"
# include "coordone.h"
# include "tetriminos.h"
# include "stdlib.h"
# include "manip_bin.h"
# include "glb.h"

# define Y elem->pos->y
# define X elem->pos->x
# define DIM_X elem->dim->x
# define DIM_Y elem->dim->y
# define IND_Y indice->y
# define IND_X indice->x

unsigned	long	ft_working_window(t_sqare *gr, t_coordone *pos);
unsigned	long	*ft_init_windows(t_coordone *pos, int stage);
void				ft_remouve_tetris(t_tetriminos *elem);
int					ft_set_tetris(t_tetriminos *elem, t_coordone *pos);
int					ft_push_tetriminos(t_tetriminos *elem);
#endif
