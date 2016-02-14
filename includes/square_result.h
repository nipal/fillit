/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square_result.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <fjanoty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 18:23:53 by fjanoty           #+#    #+#             */
/*   Updated: 2016/02/14 16:57:58 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SQUARE_RESULT_H
# define SQUARE_RESULT_H

# include <stdlib.h>

typedef	struct			s_square
{
	unsigned	long	**area;
	int					dim;
}						t_sqare;
t_sqare				*ft_create_square();
#endif
