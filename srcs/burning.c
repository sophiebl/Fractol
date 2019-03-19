/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboulaao <sboulaao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 22:51:51 by sboulaao          #+#    #+#             */
/*   Updated: 2019/03/19 22:51:54 by sboulaao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	fract_iter_burning(t_fract *fract, t_mlx *mlx, long long x, long long y)
{
	long long		i;

	fract->c_r = x / fract->zoom + fract->x1;
	fract->c_i = y / fract->zoom + fract->y1;
	fract->z_r = 0;
	fract->z_i = 0;
	i = 0;
	while (fract->z_r * fract->z_r + fract->z_i * fract->z_i < 4 && i < fract->i_max)
	{
		fract->tmp = fract->z_r;
		fract->z_r = fract->z_r * fract->z_r - fract->z_i * fract->z_i + fract->c_r;
		fract->z_i = 2 * fabs(fract->tmp * fract->z_i) + fract->c_i;
		i++;
	}
	if (i == fract->i_max)
		draw_fractol(mlx, x, y, 0x000000);
	else
		draw_fractol(mlx, x, y, mlx->infos->color * i);
}

void	fract_dspl_burning(t_mlx *mlx)
{
	long long		x;
	long long		y;

	x = 0;
	while (x < mlx->fract->img_x)
	{
		y = 0;
		while (y < mlx->fract->img_y)
		{
			fract_iter_burning(mlx->fract, mlx, x, y);
			y++;
		}
		x++;
	}
}

void		fract_init_burning(t_fract *fract)
{
	fract->img_x = WIDTH - 1;
	fract->img_y = HEIGHT - 1;
	fract->x1 = fract->img_x * -0.001 - 1 - 0.75;
	fract->x2 = 2.1;
	fract->y1 = fract->img_y * -0.001 - 1;
	fract->y2 = 1.2;
	fract->zoom = HEIGHT / 5;
	fract->i_max = 300;
}
