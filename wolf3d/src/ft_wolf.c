/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wolf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 16:18:36 by gjacot            #+#    #+#             */
/*   Updated: 2016/11/19 16:21:17 by gjacot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf3d.h"

void	ft_wolf2(t_env *e, int x)
{
	e->x_dir += 60.0 / e->screen_x;
	ft_verif_dir(e);
	ft_distwall(e, e->x_dir, e->p_dir);
	if (e->a < e->b)
	{
		if (e->a > -1)
			ft_trace_column(e, e->a, x, 1);
		else
			ft_trace_column(e, e->b, x, 2);
	}
	else if (e->b < e->a)
	{
		if (e->b > -1)
			ft_trace_column(e, e->b, x, 2);
		else
			ft_trace_column(e, e->a, x, 1);
	}
	else
		ft_trace_column(e, e->a, x, 1);
}

int		ft_wolf(t_env *e)
{
	int x;

	x = 0;
	e->p_dir = e->player_dir;
	e->x_dir = -30;
	ft_move(e);
	e->img = mlx_new_image(e->mlx, e->screen_x, e->screen_y);
	e->data = (int *)mlx_get_data_addr(e->img, &(e->bpp),\
		&(e->s_line), &(e->endian));
	while (x < e->screen_x)
	{
		ft_wolf2(e, x);
		x++;
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	mlx_destroy_image(e->mlx, e->img);
	return (0);
}
