/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordone.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <fjanoty@student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 07:10:04 by fjanoty           #+#    #+#             */
/*   Updated: 2016/02/05 03:54:44 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COORDONE_H
# define COORDONE_H

# include <stdlib.h>

typedef	struct	s_coordone
{
	int			x;
	int			y;
}				t_coordone;

t_coordone		*create_coordone(void);
t_coordone		*create_coordone_y(int y);
void			copy_coordone(t_coordone *pos_dst, t_coordone *pos_src);
#endif
