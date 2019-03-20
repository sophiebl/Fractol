/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboulaao <sboulaao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 22:52:02 by sboulaao          #+#    #+#             */
/*   Updated: 2019/03/20 01:00:25 by sboulaao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void			draw_fractol(t_mlx *mlx, int x, int y, unsigned int c)
{
	int		i;

	i = y * WIDTH + x;
	mlx->infos->img->data[i] = c;
}

void			init_tabcolor(t_info *infos)
{
	infos->stop_psy = 1;
	infos->color_tab[0] = 13487615;
	infos->color_tab[1] = 6329952;
	infos->color_tab[2] = 13130239;
	infos->color_tab[3] = 6939236;
	infos->color_tab[4] = 9856250;
	infos->color_tab[5] = 16404540;
	infos->color_tab[6] = 16724730;
	infos->color_tab[7] = 16750110;
	infos->color_tab[8] = 3289850;
	infos->color_tab[9] = 678399;
	infos->color_tab[10] = 9881850;
	infos->color = infos->color_tab[0];
	infos->i_tab = 0;
}
