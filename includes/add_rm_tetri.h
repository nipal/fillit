/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_rm_tetri.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <fjanoty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 19:09:50 by fjanoty           #+#    #+#             */
/*   Updated: 2016/02/04 20:00:43 by fjanoty          ###   ########.fr       */
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

unsigned	long	ft_working_window(t_sqare *gr, t_coordone *pos
					, unsigned long horizontal, unsigned long vertical);
unsigned	long	*ft_init_windows(t_coordone *pos, int stage);
void				ft_remouve_tetris(t_tetriminos *elem);
void				ft_set_tetris(t_tetriminos *elem, t_coordone *pos);
int					ft_push_tetriminos(t_tetriminos *elem);
#endif
