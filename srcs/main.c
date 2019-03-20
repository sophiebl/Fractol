/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboulaao <sboulaao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 22:53:16 by sboulaao          #+#    #+#             */
/*   Updated: 2019/03/20 00:57:12 by sboulaao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void		fract_init_infos(short mouse, short fract, t_info *infos)
{
	infos->mouse = mouse;
	infos->fract = fract;
}

static void		fract_verif_prms(t_info *infos, char *prms)
{
	if (ft_strcmp(prms, "Mandelbrot") == 0)
		fract_init_infos(0, 1, infos);
	else if (ft_strcmp(prms, "Julia") == 0)
		fract_init_infos(1, 2, infos);
	else if (ft_strcmp(prms, "Burningship") == 0)
		fract_init_infos(0, 3, infos);
	if (infos->fract == -1)
		fract_err(1);
}

int				main(int ac, char **av)
{
	t_info		infos[1];

	if (ac == 2)
	{
		infos->fract = -1;
		fract_verif_prms(infos, av[1]);
		init_tabcolor(infos);
		mlxinfos_init(infos);
	}
	else
		fract_err(1);
	return (0);
}
