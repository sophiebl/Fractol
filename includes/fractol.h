#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include "../mlx/mlx.h"
# include "../libft/libft.h"
# define WDEF		1920
# define HDEF		1300

typedef struct		s_fract
{
	double			c_i;
	double			c_r;
	double			z_i;
	double			z_r;
	double			x1;
	double			x2;
	double			y1;
	double			y2;
	double			tmp;
	double			zoom;
	long long		i_max;
	long long		img_x;
	long long		img_y;
}					t_fract;

typedef	struct		s_img
{
	void			*mlx_img;
	int				*data;
	int				bperpix;
	int				size_line;
	int				endian;
}					t_img;

typedef struct		s_info
{
	short			mouse;
	short			stop_psy;
	short			fract;
	int				width;
	int				height;
	short			i_tab;
	unsigned int	color_tab[11];
	unsigned int	color;
	char			*iterations;
	char			*i_max_str;
	t_img			*img;
}					t_info;

typedef struct		s_mlx
{
	void			*ptr;
	void			*wdw;
	t_info			*infos;
	t_fract			*fract;
}					t_mlx;

typedef struct		s_fractop
{
	int			id;
	char		*fract_name;
	void		(*fract_dspl)(t_mlx *mlx);
	void		(*fract_init)(t_fract *fract, t_mlx *mlx);
}					t_fractop;

/*
**	init.c
*/
void				fract_init_mand(t_fract *fract, t_mlx *mlx);
void				fract_init_burning(t_fract *fract, t_mlx *mlx);
void				fract_init_ju(t_fract *fract, t_mlx *mlx);

/*
**	usage.c
*/
void				display_usage(t_mlx *mlx);

/*
**	mandelbrot.c
*/
void				fract_dspl_mand(t_mlx *mlx);

/*
**	julia.c
*/
void				fract_dspl_ju(t_mlx *mlx);

/*
**	burning.c
*/
void				fract_dspl_burning(t_mlx *mlx);

/*
** 	error.c
*/
void				fract_err(int id);
void				fract_exit(int id);

/*
**	windows.c
*/
void				mlxinfos_init(t_info *infos);
void				fract_graph(t_mlx *mlx);

/*
**	utils.c
*/
void				fract_pxl(t_mlx *mlx, int x, int y, unsigned int c);
void				init_tabcolor(t_info *infos);
unsigned int		random_color(void);

/*
**	deal.c
*/
int					deal_key(int key, t_mlx *mlx);
int					loop_hook(t_mlx *mlx);
int					deal_mouse(int x, int y, t_mlx *mlx);

/*
**	mouse.c
*/
int					deal_mouse(int x, int y, t_mlx *mlx);
int					deal_scroll(int button, int x, int y, t_mlx *mlx);
int					deal_close(int key, t_mlx *mlx);

#endif
