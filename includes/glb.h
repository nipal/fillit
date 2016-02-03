/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glb.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <fjanoty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 21:53:00 by fjanoty           #+#    #+#             */
/*   Updated: 2016/02/03 22:10:30 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLB_H
# define GLB_H
# define GET 1
# define SET 2

#include "sqare_result.h"

int			glb_nb_windows(int mode, int sqr_dim);
int			glb_sqr_dim(int mode, int value);
t_sqare		*glb_ground(int mode, t_sqare *value);


#endif
