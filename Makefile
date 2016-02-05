# ************************************************************************** #
#                                                                            #
#                                                        :::      ::::::::   #
#   Makefile                                           :+:      :+:    :+:   #
#                                                    +:+ +:+         +:+     #
#   By: tboos <marvin@42.fr>                       +#+  +:+       +#+        #
#                                                +#+#+#+#+#+   +#+           #
#   Created: 2015/11/04 18:24:51 by tboos             #+#    #+#             #
#   Updated: 2015/11/05 00:11:36 by tboos            ###   ########.fr       #
#                                                                            #
# ************************************************************************** #
#NOTE: -l DIR pour inclure un dossier contenant des headers!
.PHONY: clean fclean re 
NAME = fillit
FLAGS = -Wall -Wextra -Werror
S =		add_rm_tetri.c\
		coordone.c\
		debug.c\
		error.c\
		filling.c\
		fillit_structure.c\
		ft_reorder.c\
		ft_tetrilen.c\
		ft_tetriorder.c\
		glb.c\
		main.c\
		manip_bin.c\
		print.c\
		square_result.c\
		tetriminos.c

SRC = $(addprefix srcs/,$(S))
all: $(NAME)

$(NAME): $(OBJ)
	gcc $(FLAGS) $(SRC) -I includes libft.a -o $(NAME)

clean:
	rm -f nothing

fclean: clean
	rm -f $(NAME) 

re: fclean $(NAME)
