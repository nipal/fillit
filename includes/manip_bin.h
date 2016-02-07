/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manip_bin.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <fjanoty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 20:08:05 by fjanoty           #+#    #+#             */
/*   Updated: 2016/02/07 14:21:26 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MANIP_BIN_H
# define MANIP_BIN_H

# include "tetriminos.h"
# define HORIZONTAL 255
# define VERTICAL 72340172838076673

unsigned	long	get_vertical_mask(int size);
unsigned	long	get_horizontal_mask(int size);
int					ft_resting_posx(t_tetriminos *elem, int i);
int					ft_resting_posy(t_tetriminos *elem, int j);
#endif
