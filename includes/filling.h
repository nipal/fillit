/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filling.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <fjanoty@student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 07:41:44 by fjanoty           #+#    #+#             */
/*   Updated: 2016/01/27 09:18:32 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLING_H
# define FILLING_H

# include "tetriminos.h"

void	actual_mini_maxi(t_tetriminos *tetris, int i);
int		first_case(char *str);
void	search_the_diese(char *piece, t_tetriminos *tetris, int *nb, int i);
int		style_alive(char *str);
#endif
