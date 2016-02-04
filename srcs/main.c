/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <fjanoty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/03 22:45:56 by fjanoty           #+#    #+#             */
/*   Updated: 2016/02/04 19:16:03 by tboos            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int		main(int ac, char **av)
{
	int		err;
	int		fd;

	if (ac == 2)
	{
		if ((fd = open(av[1], O_RDONLY, S_IREAD)) != 1)
		{
			err = fillit_structure(fd);
			if (err == -1)
				ft_putstr_fd("error\n", 2);
			else if (err == -2)
				ft_putstr_fd("error\n", 2);
		}
		else
			ft_putstr_fd("error\n", 2);
	}
	else if (ac == 1)
		ft_putstr_fd("error\n", 2);
	else
		ft_putstr_fd("error\n", 2);
	return (0);
}
