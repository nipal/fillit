/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generateur_fillit.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <fjanoty@student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/15 19:07:34 by fjanoty           #+#    #+#             */
/*   Updated: 2016/01/16 00:21:16 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <unistd.h>

void			init_tab_val(unsigned short **tab)
{
	tab[0][0] = 15;
	tab[0][1] = 4;
	tab[0][2] = 1;

	tab[1][0] = 4369;
	tab[1][1] = 1;
	tab[1][2] = 4;

	tab[2][0] = 51;
	tab[2][1] = 2;
	tab[2][2] = 2;

	tab[3][0] = 39;
	tab[3][1] = 3;
	tab[3][2] = 2;

	tab[4][0] = 305;
	tab[4][1] = 2;
	tab[4][2] = 3;

	tab[5][0] = 562;
	tab[5][1] = 2;
	tab[5][2] = 3;

	tab[6][0] = 114;
	tab[6][1] = 3;
	tab[6][2] = 2;

	tab[7][0] = 23;
	tab[7][1] = 3;
	tab[7][2] = 2;

	tab[8][0] = 547;
	tab[8][1] = 2;
	tab[8][2] = 3;

	tab[9][0] = 116;
	tab[9][1] = 3;
	tab[9][2] = 2;

	tab[10][0] = 785;
	tab[10][1] = 2;
	tab[10][2] = 3;

	tab[11][0] = 71;
	tab[11][1] = 3;
	tab[11][2] = 2;

	tab[12][0] = 802;
	tab[12][1] = 2;
	tab[12][2] = 3;

	tab[13][0] = 113;
	tab[13][1] = 3;
	tab[13][2] = 2;

	tab[14][0] = 275;
	tab[14][1] = 2;
	tab[14][2] = 3;

	tab[15][0] = 99;
	tab[15][1] = 3;
	tab[15][2] = 2;

	tab[16][0] = 306;
	tab[16][1] = 2;
	tab[16][2] = 3;

	tab[17][0] = 54;
	tab[17][1] = 3;
	tab[17][2] = 2;

	tab[18][0] = 561;
	tab[18][1] = 2;
	tab[18][2] = 3;
}

unsigned short **init_tab(void)
{
	unsigned short	**tab;
	int				i;
	int				j;

	tab = (unsigned short **)malloc(sizeof(unsigned short*) * 19);
	i = 0;
	while (i < 19)
	{
		tab[i] = (unsigned short *) malloc(sizeof(unsigned short) * 3);
		if (tab[i])
		{
			j = 0;
			while (j < 3)
			{
				tab[i][j] = 0;
				j++;
			}
		}
		i++;
	}
	init_tab_val(tab);
	return (tab);
}

void	print_piece(unsigned short **tab, int num, int alea)
{
	int		decal_x;
	int		decal_y;
	short	nb;
	int		i;
	int		j;

	if(alea)
	{
		decal_x = (rand() %  (4 - tab[num][1] + 1));
		decal_y = (rand() %  (4 - tab[num][2] + 1));
		nb = (tab[num][0] << (decal_x + (4 * decal_y))) ;
	}
	else
		nb = tab[num][0];
	j = 0;
	while (j < 4)
	{
		i = 0;
		while (i < 4)
		{
			if (nb & (1 << (4 * j + i)))
				write(1, "#", 1);
			else
				write(1, ".", 1);
			i++;
		}
		write(1, "\n", 1);
		j++;
	}
}

int	main(int ac, char **av)
{
	unsigned short	**tab;
	int				i;
	int				piece;
	int				nb_piece;

	srand(time(NULL));
	tab = init_tab();
	i = 0;
	if (ac >= 2)
		nb_piece = atoi(av[1]);
	else
		nb_piece = 3;
	while (i < nb_piece)
	{
		piece = rand() % 19;
		print_piece(tab, piece, 1);
		if (i < nb_piece - 1)
			write(1, "\n", 1);
		i++;
	}
	return (0);
}
