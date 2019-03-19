#ifndef fract_OP_H
# define fract_OP_H

# include "fractol.h"

static t_fractop	g_fractop[] =
{
	{0, "", &fract_dspl_mand, &fract_init_mand},
	{1, "Mandelbrot", &fract_dspl_mand, &fract_init_mand},
	{2, "Julia", &fract_dspl_ju, &fract_init_ju},
	{3, "Burning", &fract_dspl_burning, &fract_init_burning}
};

#endif
