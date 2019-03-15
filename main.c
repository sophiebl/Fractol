#include "fractol.h"
#include <stdio.h>
/*
   int			ft_exit(t_mlx *mlx)
   {
   mlx_destroy_image(mlx->ptr, mlx->img.img_ptr);
   mlx_destroy_window(mlx->ptr, mlx->wdw);
   exit(1);
   }
 */
void		ft_error(void)
{
	write(2, "Error mlx\n", 10);
	exit(1);
}

void		ft_init_mlx(t_mlx *mlx)
{
	if (!(mlx->ptr = mlx_init()))
		ft_error();
	if (!(mlx->wdw = mlx_new_window(mlx->ptr, WIN_WIDTH, WIN_HEIGHT, "Fractol")))
		ft_error();
	if (!(mlx->img.img_ptr = mlx_new_image(mlx->ptr, WIN_WIDTH, WIN_HEIGHT)))
		ft_error();
	mlx->img.data = (int *)mlx_get_data_addr(mlx->img.img_ptr, &(mlx->img.bpp), &(mlx->img.s_l),
		&(mlx->img.endian));
}

int	main(void)
{
	int i;
	int x = 0;
	int y = 0;
	int z;
	int c_r;
	int c_i;
	int z_r;
	int z_i;
	int tmp;
	t_mlx	mlx;
	t_img 	img;

	double x1 = -2.1;
	double x2 = 0.6;
	double y1 = -1.2;
	double y2 = 1.2;
	z = 0;
	int zoom_x = WIN_WIDTH / (x2 -x1);
	int zoom_y = WIN_HEIGHT / (y2 -y1);
	img = mlx.img;
	ft_init_mlx(&mlx);
	while (x < WIN_WIDTH)
	{
		while (y > WIN_HEIGHT)
		{
			c_r = x / zoom_x + x1;
			c_i = y / zoom_y + y1;
			z_r = 0;
			z_i = 0;
			i = 0;
			while ((z_r*z_r + z_i*z_i) < 4 && i < 51)
			{
				tmp = z_r; 
				z_r = z_r*z_r - z_i*z_i + c_r;
				z_i = 2*z_i*tmp + c_i;
				if (i == 50)		
					img.data[z_i * WIN_WIDTH + z_r] = 0xFFFFFF;
				//	mlx_pixel_put (mlx->ptr, mlx->win, z_r, z_i, 0xFFFFFF);
				i++;
			}
			y++;
		}
		x++;
	}
	printf("hello\n");
	mlx_put_image_to_window(mlx.ptr, mlx.wdw, mlx.img.img_ptr, 0, 0);
	mlx_loop(mlx.ptr);
	return (0);
}
