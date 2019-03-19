#include "../includes/fractol.h"

void		fract_init_mand(t_fract *fract, t_mlx *mlx)
{
	fract->img_x = mlx->infos->width - 1;
	fract->img_y = mlx->infos->height - 1;
	fract->x1 = fract->img_x * -0.001 - 0.5;
	fract->x2 = 2.1;
	fract->y1 = fract->img_y * -0.001;
	fract->y2 = 1.2;
	fract->tmp = 0;
	fract->i_max = 30;
	fract->zoom = mlx->infos->width / 6;
}

void		fract_init_ju(t_fract *fract, t_mlx *mlx)
{
	fract->img_x = mlx->infos->width - 1;
	fract->img_y = mlx->infos->height - 1;
	fract->c_r = 0.285;
	fract->c_i = 0.01;
	fract->x1 = fract->img_x * -0.001;
	fract->x2 = 1;
	fract->y1 = fract->img_y * -0.001;
	fract->y2 = 1.2;
	fract->tmp = 0;
	fract->i_max = 30;
	fract->zoom = mlx->infos->width / 6;
}

void		fract_init_burning(t_fract *fract, t_mlx *mlx)
{
	fract->img_x = mlx->infos->width - 1;
	fract->img_y = mlx->infos->height - 1;
	fract->x1 = fract->img_x * -0.001 - 1;
	fract->x2 = 2.1;
	fract->y1 = fract->img_y * -0.001 - 1;
	fract->y2 = 1.2;
	fract->zoom = mlx->infos->height / 5;
	fract->i_max = 300;
}
