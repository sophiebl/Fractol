#include "../includes/fract_op.h"

void		display_usage_bis(t_mlx *mlx, int x, int y)
{
	mlx_string_put(mlx->ptr, mlx->wdw, x, y + 380, 0xFFFFFF,
			"                      /\\");
	mlx_string_put(mlx->ptr, mlx->wdw, x, y + 400, 0xFFFFFF,
			"                   <      > ");
	mlx_string_put(mlx->ptr, mlx->wdw, x, y + 420, 0xFFFFFF,
			"                      \\/");
	mlx_string_put(mlx->ptr, mlx->wdw, x, y + 360, 0xFFFFFF,
			"Navigation                      ");
}

void		display_usage(t_mlx *mlx)
{
	int		x;
	int		y;

	x = 40;
	y = 20;
	mlx_string_put(mlx->ptr, mlx->wdw, x + 40, y, 0xFFFFFF,
			"-------- COMMANDES --------");
	mlx_string_put(mlx->ptr, mlx->wdw, x, y + 40, 0xFFFFFF,
			"Exit                  ESC");
	mlx_string_put(mlx->ptr, mlx->wdw, x, y + 120, 0xFFFFFF,
			"Zoom/Dezoom            +/-");
	mlx_string_put(mlx->ptr, mlx->wdw, x, y + 160, 0xFFFFFF,
			"Change color           C");
	mlx_string_put(mlx->ptr, mlx->wdw, x, y + 240, 0xFFFFFF,
			"Psychedelic mode       P");
	mlx_string_put(mlx->ptr, mlx->wdw, x, y + 320, 0xFFFFFF,
			"Mouse                  M");
	display_usage_bis(mlx, x, y);
}
