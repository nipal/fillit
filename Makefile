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
S =		coordone.c\
		error.c\
		filling.c\
		fillit_structure.c\
		main.c\
		tetriminos.c\
		debug.c
#		generate_order.c\

SRC = $(addprefix srcs/,$(S))
all: $(NAME)

$(NAME): $(OBJ)
	gcc $(FLAGS) $(SRC) libft.a -I includes -L includes -o $(NAME)

clean:
	rm -f nothing

fclean: clean
	rm -f $(NAME) 

re: fclean $(NAME)
