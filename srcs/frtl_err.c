#include "../includes/frtl.h"

void		frtl_err(int id)
{
	if (id == 1)
		ft_putendl_fd(ERR_USAGE, 2);
	if (id == 2)
		ft_putendl_fd(ERR_MLX, 2);
	exit(id);
}

void		frtl_exit(int id)
{
	if (id == 0)
		ft_putendl(EXIT);
	exit(id);
}
