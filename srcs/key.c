/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboulaao <sboulaao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 22:53:03 by sboulaao          #+#    #+#             */
/*   Updated: 2019/03/19 22:53:04 by sboulaao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fract_op.h"

void		ft_menu(t_mlx *mlx)
{
	int		x;
	int		y;

	x = 40;
	y = 20;
	mlx_string_put(mlx->ptr, mlx->wdw, x + 40, y, 0xFFFFFF, "-- COMMANDES --");
	mlx_string_put(mlx->ptr, mlx->wdw, x, y + 40, 0xFFFFFF, "Zoom  : +/-");
	mlx_string_put(mlx->ptr, mlx->wdw, x, y + 60, 0xFFFFFF, "Move : arrow");
	mlx_string_put(mlx->ptr, mlx->wdw, x, y + 80, 0xFFFFFF, "Color : C");
	mlx_string_put(mlx->ptr, mlx->wdw, x, y + 100, 0xFFFFFF, "Psychedelic : P");
	mlx_string_put(mlx->ptr, mlx->wdw, x, y + 120, 0xFFFFFF, "Exit : ESC");
}

static int			deal_key_ter(int key, t_mlx *mlx)
{
	if (key == 46)
	{
		if (mlx->infos->mouse == 0)
			mlx->infos->mouse = 1;
		else
			mlx->infos->mouse = 0;
	}
	else if (key == 124)
		mlx->fract->x1 -= 0.2;
	else if (key == 123)
		mlx->fract->x1 += 0.2;
	else if (key == 125)
		mlx->fract->y1 -= 0.2;
	else if (key == 126)
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
	else if (key == 34 && mlx->fract->i_max < 400)
		mlx->fract->i_max++;
	else if (key == 31 && mlx->fract->i_max > 10)
		mlx->fract->i_max--;
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
