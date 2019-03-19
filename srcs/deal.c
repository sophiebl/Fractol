#include "../includes/fract_op.h"

static int			deal_key_ter(int key, t_mlx *mlx)
{
	if (key == 46)
	{
		if (mlx->infos->mouse == 0)
			mlx->infos->mouse = 1;
		else
			mlx->infos->mouse = 0;
	}
	else if (key == 123)
		mlx->fract->x1 -= 0.2;
	else if (key == 124)
		mlx->fract->x1 += 0.2;
	else if (key == 126)
		mlx->fract->y1 -= 0.2;
	else if (key == 125)
		mlx->fract->y1 += 0.2;
	else if (key == 8)
	{
		mlx->infos->i_tab++;
		if (mlx->infos->i_tab == 11)
			mlx->infos->i_tab = 0;
		mlx->infos->color = mlx->infos->color_tab[mlx->infos->i_tab];
	}
	return (0);
}

static int			deal_key_bis(int key, t_mlx *mlx)
{
	if (key == 35)
	{
		if (mlx->infos->stop_psy == 0)
			mlx->infos->stop_psy = 1;
		else
			mlx->infos->stop_psy = 0;
	}
	else
		deal_key_ter(key, mlx);
	return (0);
}

int			deal_key(int key, t_mlx *mlx)
{
	if (key == 53)
		fract_exit(0);
	else if (key == 24 || key == 69)
	{
		mlx->fract->zoom += 5.5;
		mlx->fract->x1 -= 0.0001;
		mlx->fract->y1 += 0.0001;
	}
	else if ((key == 27 || key == 78) && mlx->fract->zoom > 2)
	{
		mlx->fract->zoom -= 5.5;
		mlx->fract->x1 -= 0.0001;
		mlx->fract->y1 += 0.0001;
	}
	deal_key_bis(key, mlx);
	mlx_clear_window(mlx->ptr, mlx->wdw);
	fract_graph(mlx);
	return (0);
}

int			loop_hook(t_mlx *mlx)
{
	if (mlx->infos->stop_psy == 0)
	{
		mlx->infos->color = rand();
		mlx_clear_window(mlx->ptr, mlx->wdw);
		fract_graph(mlx);
	}
	return (0);
}
