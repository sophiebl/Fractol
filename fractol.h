#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <stdlib.h>
# include "minilibx/mlx.h"
# include "libft/libft.h"
# include <fcntl.h>

# define WIN_WIDTH 270
# define WIN_HEIGHT 240

typedef struct		s_img
{
	void	*img_ptr;
	int	*data;
	int	bpp;
	int	s_l;
	int	endian;
}			t_img;


typedef struct		s_mlx
{
	void	*ptr;
	void	*wdw;
	int	color;
	int	x;
	int	y;
	t_img	img;
}			t_mlx;

#endif
