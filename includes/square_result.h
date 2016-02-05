/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square_result.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjanoty <fjanoty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 18:23:53 by fjanoty           #+#    #+#             */
/*   Updated: 2016/02/05 06:18:55 by fjanoty          ###   ########.fr       */
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
#endif

/*
 * 



 * */

/*	totale:	 	17
	
	glb:			3
int					glb_nb_windows(int mode, int sqr_dim);--------------------------------------------------------------->	oui
int					glb_sqr_dim(int mode, int value);-------------------------------------------------------------------->	oui
t_sqare				*glb_ground(int mode, t_sqare *value);--------------------------------------------------------------->	oui

	print:		4
int					indice_input(t_coordone *pos, t_coordone *ind, int len);
char				*ft_init_str_result();
char				*ft_get_result(t_coordone *pos, t_coordone *indice, t_tetriminos *elem, int len);//
void				ft_print_resut(t_tetriminos *begin);

	add_rm_tetri:		5
unsigned	long	ft_working_window(t_sqare *gr, t_coordone *pos, unsigned long horizontal, unsigned long vertical);--->	oui
unsigned	long	*ft_init_windows(t_coordone *pos, int stage);
void				ft_remouve_tetris(t_tetriminos *elem);
void				ft_set_tetris(t_tetriminos *elem, t_coordone *pos);
int					ft_push_tetriminos(t_tetriminos *elem); //(testeur de posion)

	sqr:		1
t_sqare				*ft_create_square()

	manip_bin:	4
unsigned	long	get_vertical_mask(int size);------------------------------------------------------------------------->	oui
unsigned	long	get_horizontal_mask(int size);----------------------------------------------------------------------->	oui
int					ft_resting_posx(t_tetriminos *elem, int i);
int					ft_resting_posy(t_tetriminos *elem, int j);

	





 * */

//	initialisation du tableau---------------------------------->	DONE
//	incrementation de la taille du taleau---------------------->
//	calcule du plus petit carre possible----------------------->
//	recuperer une ecran de travail----------------------------->	DONE
//	decaler l'ecran de travail--------------------------------->	DONE
//	placer une piece dans le tableau--------------------------->	DONE
//		-la placer dans l'ecran de travail
//		-ecrire l'ecran dans le tableau
//	retirer une piece du tableau------------------------------->	DONE
//		-on cheque sur quel area elle est presente
//		-on genere des masque pour chaque area
//		-on relance lecran
//	creation du resultat--------------------------------------->	DONE
//	liberation de toute la memoire----------------------------->
//	detection des case vide ===>>>#####  OU PAS ####<<<===
//		-index par type de la dernier place emprinter
//		-recherche de zone vide puis matchage avec les piece


//	OPTIMISATION
//		-garder en memoir tout les masque possible------------->	DONE
//		-garder en memoir 2 ou 3 ecran selon la taille--------->	DONE

//	eran:   (Hum je ne suis plus vraiment trex sur de ca)
//	on pourai utiliser des eccran superposer:
//	on aurai donc 3 ecran superposer



