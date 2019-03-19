/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboulaao <sboulaao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 22:52:15 by sboulaao          #+#    #+#             */
/*   Updated: 2019/03/19 22:52:17 by sboulaao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void		fract_err(int id)
{
	if (id == 1)
		ft_putendl_fd("Usage: ./fractol <fractals_model>\nFractals models : Mandelbrot, Julia, Burningship", 2);
	if (id == 2)
		ft_putendl_fd("error : mlx", 2);
	exit(id);
}

void		fract_exit(int id)
{
	if (id == 0)
		ft_putendl("Fractol is closed");
	exit(id);
}
