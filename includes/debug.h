/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <fjanoty@student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 06:59:34 by fjanoty           #+#    #+#             */
/*   Updated: 2016/02/06 18:24:10 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_H
# define DEBUG_H

# include "coordone.h"
# include "tetriminos.h"
# include "square_result.h"
# include <stdio.h>
void	print_tetris(t_tetriminos *piece);
void	print_coordone(t_coordone *pos, char *name);
void	describe_tetris(t_tetriminos *tetris);
void	print_all_tetris(t_tetriminos *tetris);
void	print_ground(t_sqare *sqr);

#endif
