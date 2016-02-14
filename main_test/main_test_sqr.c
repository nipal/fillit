/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test_sqr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <fjanoty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/06 18:26:00 by fjanoty           #+#    #+#             */
/*   Updated: 2016/02/06 18:32:35 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "square_result.h"
#include "debug.h"

int 	main()
{
	t_sqare *sqr;

	sqr = ft_create_square();
	print_ground(sqr);
	return (0);
}
