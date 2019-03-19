#include "../includes/fract_op.h"

void		fract_init_img(t_info *window, t_img *img, void *ptr)
{
	if (!(img->mlx_img = mlx_new_image(ptr, window->width, window->height)))
		fract_err(2);
	img->data = (int *)mlx_get_data_addr(img->mlx_img, &img->bperpix,
			&img->size_line, &img->endian);
}

void		fract_graph(t_mlx *mlx)
{
	t_img	img[1];

	fract_init_img(mlx->infos, img, mlx->ptr);
	mlx->infos->img = img;
	g_fractop[mlx->infos->fract].fract_dspl(mlx);
	mlx_put_image_to_window(mlx->ptr, mlx->wdw,
			mlx->infos->img->mlx_img, 0, 0);
	mlx->infos->i_max_str = ft_itoa(mlx->fract->i_max);
	mlx->infos->iterations = ft_strjoin(ITER, mlx->infos->i_max_str);
	display_usage(mlx);
	mlx_destroy_image(mlx->ptr, mlx->infos->img->mlx_img);
	ft_strdel(&mlx->infos->iterations);
	ft_strdel(&mlx->infos->i_max_str);
}

void		mlxinfos_init(t_info *infos)
{
	t_mlx		mlx[1];
	t_fract		fract[1];

	if (!(mlx->ptr = mlx_init()))
		fract_err(2);
	if (!(mlx->wdw = mlx_new_window(mlx->ptr, infos->width,
					infos->height, "Fractol")))
		fract_err(2);
	mlx->infos = infos;
	infos->width = WDEF;
	infos->height = HDEF;
	g_fractop[mlx->infos->fract].fract_init(fract, mlx);
	mlx->fract = fract;
	fract_graph(mlx);
	mlx_hook(mlx->wdw, 2, 5, deal_key, mlx);
	mlx_hook(mlx->wdw, 6, (1L << 6), deal_mouse, mlx);
	mlx_hook(mlx->wdw, 4, 0, deal_scroll, mlx);
	mlx_hook(mlx->wdw, 17, (1L << 17), deal_close, mlx);
	mlx_loop_hook(mlx->ptr, loop_hook, mlx);
	mlx_loop(mlx->ptr);
}
