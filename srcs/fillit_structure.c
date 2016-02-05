/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_structure.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <fjanoty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 18:23:53 by fjanoty           #+#    #+#             */
/*   Updated: 2016/02/05 08:31:28 by fjanoty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include "structure.h"

static int		my_free(void *addr)
{
	free(addr);
	return (1);
}

t_tetriminos	*get_next_piece(int fd, int id)
{
	t_tetriminos	*tetris;
	int				oct_lu;
	char			str[21];

	if (!(tetris = create_tetriminos(id)) && error(SET))
		return (NULL);
	if ((oct_lu = read(fd, str, 20)) != 20 && error(SET) && my_free(tetris) + 1)
		return (NULL);
	oct_lu = 0;
	search_the_diese(str, tetris, &oct_lu, (tetris->gap = first_case(str)));
	if ((tetris->id == 0 || oct_lu != 4 || style_alive(str))
	&& error(SET) && my_free(tetris))
		return (NULL);
	finished_tetriminos(tetris);
	return (tetris);
}

t_tetriminos	*get_the_pieces(int fd)
{
	t_tetriminos	*begin;
	int				i;
	char			c;
	int				oct_lu;

	i = 0;
	oct_lu = 1;
	c = '\n';
	begin = NULL;
	while (i < 26 && oct_lu && c == '\n')
	{
		begin = tetris_push_front(begin, get_next_piece(fd, i));
		oct_lu = read(fd, &c, 1);
		if (oct_lu && c != '\n')
			error(SET);
		i++;
	}
	if (error(GET) && tetris_free(begin))
		return (NULL);
	return (begin);
}

int				fillit_structure(int fd)
{
	t_tetriminos	*first_tetris;

	error(INIT);
	first_tetris = get_the_pieces(fd);
	if (!first_tetris)
		return (-1);
//	print_all_tetris(first_tetris);
	glb_ground(SET, ft_create_square());
	first_tetris = ft_squ_lunch(first_tetris, ft_tetrilen(first_tetris));
	ft_print_result(first_tetris);
	return (0);
}
