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

//	1		2		4		8		0	1	2	3
//	16		32		64		128		4	5	6	7
//	256		512		1024	2048	8	9	10	11
//	4096	8192	16384	32768	12	13	14	15


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

	tab[5][0] = 526;
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

	tab[18][0] = 563;
	tab[18][1] = 2;
	tab[18][2] = 3;
}

unsigned short **init_tab(void)
{
	unsigned short	**tab;
	int				i;
	int				j;

	tab = (unsigned short **)malloc(sizeof(unsigned short*) * 21);
	i = 0;
	while (i < 21)
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

void	print_piece(unsigned short **tab, int nb_piece)
{

}

int	main(int ac, char **av)
{
	unsigned short	**tab;

	tab = init_tad();

}
