#include "../includes/fractol.h"

static void		fract_init_infos(short mouse, short fract, t_info *infos)
{
	infos->mouse = mouse;
	infos->fract = fract;
}

static void		fract_verif_prms(t_info *infos, char *prms)
{
	if (ft_strcmp(prms, MAND) == 0)
		fract_init_infos(0, 0, infos);
	else if (ft_strcmp(prms, JU) == 0)
		fract_init_infos(1, 1, infos);
	else if (ft_strcmp(prms, BURNING) == 0)
		fract_init_infos(0, 2, infos);
	if (infos->fract == -1)
		fract_err(1);
}

static void		fract_setwin(t_info *infos, int x, int y)
{
	if (x >= WDEF || y >= HDEF)
	{
		infos->width = WDEF;
		infos->height = HDEF;
	}
	else if (x >= 400 && y >= 400)
	{
		infos->width = x;
		infos->height = y;
	}
	else
	{
		infos->width = WDEF;
		infos->height = HDEF;
	}
}

int			main(int ac, char **av)
{
	t_info	infos[1];

	if (ac == 2 || ac == 4)
	{
		infos->fract = -1;
		fract_verif_prms(infos, av[1]);
		init_tabcolor(infos);
		if (ac == 4)
		{
			if (!(ft_strisnumeric(av[2])) || !(ft_strisnumeric(av[3])))
				fract_err(1);
			fract_setwin(infos, ft_atoi(av[2]), ft_atoi(av[3]));
		}
		else
			fract_setwin(infos, WDEF, HDEF);
		mlxinfos_init(infos);
	}
	else
		fract_err(1);
	return (0);
}
