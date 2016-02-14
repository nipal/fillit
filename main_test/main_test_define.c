/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test_define.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <fjanoty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 21:56:17 by fjanoty           #+#    #+#             */
/*   Updated: 2016/02/04 23:19:48 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#define BLA_BLA "je suis un petit lapin\n"
#define OPERATION 8 - 3 + 4


int	main()
{
	int	ope = OPERATION;
	printf("ope:%d\n", ope);
	printf(BLA_BLA);
	return (0);
}
