/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <fjanoty@student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 06:51:42 by fjanoty           #+#    #+#             */
/*   Updated: 2016/01/27 09:24:03 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURE_H
# define STRUCTURE_H

# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include "tetriminos.h"
# include "filling.h"
# include "debug.h"

int				fillit_structure(int fd);
t_tetriminos	*get_next_piece(int fd, int id);
t_tetriminos	*get_the_pieces(int fd);
#endif
