/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 15:36:42 by gjacot            #+#    #+#             */
/*   Updated: 2016/11/19 16:07:29 by gjacot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf3d.h"

void	ft_wolf_init(t_env *e)
{
	e->size = 1000;
	e->screen_x = 1024;
	e->screen_y = 768;
	e->p_x = 1.5 * e->size;
	e->p_y = 1.5 * e->size;
	e->player_dir = 0;
	e->map_height = 5 * e->size;
	e->map_weight = 5 * e->size;
}

void	ft_mlx_init(t_env *e)
{
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, e->screen_x, e->screen_y, "wolf3d");
}

float	ft_abs(float n)
{
	if (n < 0)
		n *= -1;
	return (n);
}

void	ft_distwall(t_env *e, float x_dir, float p_dir)
{
	int		dist;
	float	dir;

	dist = 0;
	dir = p_dir + x_dir;
	if (dir != 0 && dir != 180)
		e->a = ft_wall_hori(e, dir);
	else
		e->a = -1;
	if (dir != 90 && dir != 270)
		e->b = ft_wallverti(e, dir);
	else
		e->b = -1;
}

int		main(void)
{
	t_env	*e;

	e = (t_env *)malloc(sizeof(t_env));
	ft_wolf_init(e);
	ft_init_map(e);
	ft_mlx_init(e);
	mlx_hook(e->win, 2, 0, &ft_key_press, e);
	mlx_hook(e->win, 3, 0, &ft_key_release, e);
	mlx_hook(e->win, 17, 0, &ft_redcross, e);
	mlx_loop_hook(e->mlx, &ft_wolf, e);
	mlx_loop(e->mlx);
}
