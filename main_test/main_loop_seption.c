/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_loop_seption.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <fjanoty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/05 00:20:38 by fjanoty           #+#    #+#             */
/*   Updated: 2016/02/05 00:31:30 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	main()
{
	int	i = 0;
	int	j = 0;

	if (j == 0)
		while (++j < 10 && !(i = 0))
		{
			while (++i < 10)
				if (i % 3 == 0)
					printf("i:%d\n", i);
		}
	return (0);
}
