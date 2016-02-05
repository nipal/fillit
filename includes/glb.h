/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glb.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <fjanoty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 21:53:00 by fjanoty           #+#    #+#             */
/*   Updated: 2016/02/05 04:24:13 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLB_H
# define GLB_H
# define GET 1
# define SET 2
# include <stdlib.h>
# include "square_result.h"


int			glb_nb_windows(int mode, int sqr_dim);
int			glb_sqr_dim(int mode, int value);
t_sqare		*glb_ground(int mode, t_sqare *value);


#endif
