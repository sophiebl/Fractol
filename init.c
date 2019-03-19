#include "../includes/fractol.h"

void		fract_init_mand(t_fract *fract)
{
	fract->img_x = WIDTH - 1;
	fract->img_y = HEIGHT - 1;
	fract->x1 = fract->img_x * -0.001 - 0.5;
	fract->x2 = 2.1;
	fract->y1 = fract->img_y * -0.001;
	fract->y2 = 1.2;
	fract->tmp = 0;
	fract->i_max = 30;
	fract->zoom = WIDTH / 6;
}

void		fract_init_ju(t_fract *fract)
{
	fract->img_x = WIDTH - 1;
	fract->img_y = HEIGHT - 1;
	fract->c_r = 0.285;
	fract->c_i = 0.01;
	fract->x1 = fract->img_x * -0.001;
	fract->x2 = 1;
	fract->y1 = fract->img_y * -0.001;
	fract->y2 = 1.2;
	fract->tmp = 0;
	fract->i_max = 30;
	fract->zoom = WIDTH / 6;
}

void		fract_init_burning(t_fract *fract)
{
	fract->img_x = WIDTH - 1;
	fract->img_y = HEIGHT - 1;
	fract->x1 = fract->img_x * -0.001 - 1;
	fract->x2 = 2.1;
	fract->y1 = fract->img_y * -0.001 - 1;
	fract->y2 = 1.2;
	fract->zoom = HEIGHT / 5;
	fract->i_max = 300;
}
