/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <fjanoty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 18:23:53 by fjanoty           #+#    #+#             */
/*   Updated: 2016/01/27 18:18:29 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <stdlib.h>

typedef	struct s_coordone	t_tetriminos;
typedef	struct		s_coordone
{
	int				x;
	int				y;
}					t_coordone;
struct				s_tetriminos
{
	t_tetriminos	*next;
	t_tetriminos	*prev;
	unsigned long	valu;
	char			id;
	int				type;
	t_coordone		*dim;
	t_coordone		*pos;
};
t_tetriminos		*ft_findbegin(t_tetriminos *begin);
int					tetris_free(t_tetriminos *elem);
int					ft_tetrilen(t_tetriminos *begin);
void				print_all_tetris(t_tetriminos *tetris);
void				ft_tetriswap(t_tetriminos *r1, t_tetriminos *r2);
void				ft_reorder(t_tetriminos *rabbit);
t_tetriminos		*ft_tetriorder(t_tetriminos *turtle, int len, int stage);
#endif
