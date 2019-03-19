#include "../includes/fractol.h"

void		fract_iter_ju(t_fract *fract, t_mlx *mlx, long long x, long long y)
{
	long long	i;

	i = 0;
	fract->z_r = x / fract->zoom + fract->x1;
	fract->z_i = y / fract->zoom + fract->y1;
	while (fract->z_r * fract->z_r + fract->z_i * fract->z_i < 4 && i < fract->i_max)
	{
		fract->tmp = fract->z_r;
		fract->z_r = fract->z_r * fract->z_r - fract->z_i * fract->z_i + fract->c_r;
		fract->z_i = 2 * fract->z_i * fract->tmp + fract->c_i;
		i++;
	}
	if (i == fract->i_max)
		draw_fractol(mlx, x, y, 0x000000);
	else
		draw_fractol(mlx, x, y, mlx->infos->color * i);
}

void		fract_dspl_ju(t_mlx *mlx)
{
	long long	x;
	long long	y;

	x = 0;
	while (x < mlx->fract->img_x)
	{
		y = 0;
		while (y < mlx->fract->img_y)
		{
			fract_iter_ju(mlx->fract, mlx, x, y);
			y++;
		}
		x++;
	}
}

void		fract_init_ju(t_fract *fract)
{
	fract->img_x = WIDTH - 1;
	fract->img_y = HEIGHT - 1;
	fract->c_r = 0.285;
	fract->c_i = 0.01;
	fract->x1 = fract->img_x * -0.001 - 0.95;
	fract->x2 = 1;
	fract->y1 = fract->img_y * -0.001 - 0.9;
	fract->y2 = 1.2;
	fract->tmp = 0;
	fract->i_max = 30;
	fract->zoom = WIDTH / 6;
}
