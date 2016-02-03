/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <fjanoty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 22:05:06 by fjanoty           #+#    #+#             */
/*   Updated: 2016/02/03 22:11:18 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_H
# define PRINT_H

#include <stdlib.h>
#include "libft.h"
#include "coordone.h"
#include "tetriminos.h"


int					indice_input(t_coordone *pos, t_coordone *ind, int len);
char				*ft_init_str_result();
char				*ft_get_result(t_coordone *pos, t_coordone *indice, t_tetriminos *elem, int len);
void				ft_print_resut(t_tetriminos *begin);
#endif
