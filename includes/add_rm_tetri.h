/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_rm_tetri.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <fjanoty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 19:09:50 by fjanoty           #+#    #+#             */
/*   Updated: 2016/02/14 12:47:32 by fjanoty          ###   ########.fr       */
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

# define Y elem->yp
# define X elem->xp
# define DIM_X elem->xd
# define DIM_Y elem->yd
# define ECR_Y elem->ys
# define ECR_X elem->xs

unsigned	long	ft_working_window(t_sqare *gr, int x, int y);
void				ft_init_windows(unsigned long *windows, int stage);
void				ft_remouve_tetris(t_tetriminos *elem);
int					ft_set_tetris(t_tetriminos *elem, int x, int y);
int					ft_push_tetriminos(t_tetriminos *elem);
#endif
