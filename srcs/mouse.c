#include "../includes/fractol.h"

int			deal_mouse(int x, int y, t_mlx *mlx)
{
	x = x - mlx->infos->width / 3;
	y = y - mlx->infos->height / 3;
	if (mlx->infos->fract == 1 && mlx->infos->mouse == 1)
	{
		mlx->fract->c_r = (double)((double)x / (double)y);
		mlx->fract->c_i = (double)((double)x / (double)y);
	}
	mlx_clear_window(mlx->ptr, mlx->wdw);
	fract_graph(mlx);
	return (0);
}

int			deal_scroll(int button, int x, int y, t_mlx *mlx)
{
	if (button == 4 || button == 1)
	{
		mlx->fract->x1 += (double)x * 0.0001;
		mlx->fract->y1 += (double)y * 0.0001;
		mlx->fract->zoom += 30.5;
	}
	else if (button == 5 || button == 2)
	{
		mlx->fract->x1 -= (double)x * 0.00001;
		mlx->fract->y1 -= (double)y * 0.00001;
		mlx->fract->zoom -= 30.5;
	}
	mlx_clear_window(mlx->ptr, mlx->wdw);
	fract_graph(mlx);
	return (0);
}

int			deal_close(int key, t_mlx *mlx)
{
	(void)mlx;
	(void)key;
	fract_exit(0);
	return (0);
}
