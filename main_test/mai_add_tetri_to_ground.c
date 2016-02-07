#include <stdio.h>
#include "debug.h"
#include "add_rm_tetri.h"
#include "manip_bin.h"
#include "tetriminos.h"
#include "coordone.h"
#include "square_result.h"

int	main(void)
{
	unsigned	long	*windows;
	t_sqare				*gr;
	t_coordone			*pos;
	t_tetriminos		*tetri_1;

	gr = ft_create_square();
	pos = create_coordone();
	gr->dim = 0;
	glb_ground(SET, gr);
	windows = ft_init_windows(pos, 0);
	print_working_windows(windows);
	return (0);
}
