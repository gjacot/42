/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 15:36:42 by gjacot            #+#    #+#             */
/*   Updated: 2016/11/13 15:46:26 by gjacot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf3d.h"

void	ft_wolf_init(t_env *e)
{
	e->p_fov = 60;
	e->p_height = 32;
	e->w_height = 64;
	e->screen_x = 1000;
	e->screen_y = 625;
	e->screen_xd2 = 500;
	e->screen_yd2 = 312;
	e->p_screen = 866;
	e->p_x = 3;
	e->p_y = 3;
	e->dir_x = -1;
	e->dir_y = 0;
	e->planex = 0;
	e->planey = 0.66;
	e->time = 0;
	e->oldtime = 0;
	e->hit = 0;
}

void	ft_init_map(t_env *e)
{
	int i;

	i = 0;
	e->map = (int **)malloc(sizeof(int *) * 4);
	while (i != 5)
	{
		e->map[i] = (int *)malloc(sizeof(int) * 4);
		i++;
	}
	e->map[0][0] = 1;
	e->map[0][1] = 1;
	e->map[0][2] = 1;
	e->map[0][3] = 1;
	e->map[1][0] = 1;
	e->map[1][1] = 0;
	e->map[1][2] = 0;
	e->map[1][3] = 1;
	e->map[2][0] = 1;
	e->map[2][1] = 0;
	e->map[2][2] = 0;
	e->map[3][0] = 1;
	e->map[3][1] = 1;
	e->map[3][2] = 1;
	e->map[3][3] = 1;
}

void	ft_mlx_init(t_env *e)
{
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, e->screen_x, e->screen_y, "wolf3d");
	e->img = mlx_new_image(e->mlx, e->screen_x, e->screen_y);
	e->data = (int *)mlx_get_data_addr(e->img, &e->bpp, &e->s_line, &e->endian);
}

void	ft_vertic_line(int x, t_env *e)
{
	int h;

	h = 0;
	printf("%d\n", e->drawend);
	while (h < e->drawstart)
	{
		*(e->data + (h * e->s_line / 4) + x) = 0;
		h++;
	}
	while (h < e->drawend)
	{
		*(e->data + (h * e->s_line / 4) + x) = e->color;
		h++;
	}
	while (h < e->screen_y)
	{
		*(e->data + (h * e->s_line / 4) + x) = 0;
		h++;
	}
}

void	ft_detect_wall(t_env *e)
{
	int x;

	x = 0;
	while (x < e->screen_x)
	{
		e->camerax = 2 * x / e->screen_x - 1;
		e->ray_posx = e->p_x;
		e->ray_posy = e->p_y;
		e->ray_dirx = e->dir_x + e->planex * e->camerax;
		e->ray_diry = e->dir_y + e->planey * e->camerax;
		e->mapx = (int)e->ray_posx;
		e->mapy = (int)e->ray_posy;
		e->deltadistx = sqrt(1 + (e->ray_diry * e->ray_diry) / (e->ray_dirx * e->ray_dirx));
		e->deltadisty = sqrt(1 + (e->ray_dirx * e->ray_dirx) / (e->ray_diry * e->ray_diry));
		if (e->ray_dirx < 0)
		{
			e->stepx = -1;
			e->sidedistx = (e->ray_posx - e->mapx) * e->deltadistx;
		}
		else
		{
			e->stepx = 1;
			e->sidedistx = (e->mapx + 1 - e->ray_posx) * e->deltadistx;
		}
		if (e->ray_diry < 0)
		{
			e->stepy = -1;
			e->sidedisty = (e->ray_posy - e->mapy) * e->deltadisty;
		}
		else
		{
			e->stepy = -1;
			e->sidedisty = (e->mapy + 1 - e->ray_posy) * e->deltadisty;
		}
		while (e->hit == 0)
		{
			if (e->sidedistx < e->sidedisty)
			{
				e->sidedistx += e->deltadistx;
				e->mapx += e->stepx;
				e->side = 0;
			}
			else
			{
				e->sidedisty += e->deltadisty;
				e->mapy += e->stepy;
				e->side = 1;
			}
			if (e->map[e->mapx][e->mapy] > 0)
				e->hit = 1;
		}
		if (e->side == 0)
			e->prepawalldist = (e->mapx - e->ray_posx + (1 - e->stepx) / 2) / e->ray_dirx;
		else
			e->prepawalldist = (e->mapy - e->ray_posy + (1 - e->stepy) / 2) / e->ray_diry;
		e->lineheight = (e->screen_y / e->prepawalldist);
		e->drawstart = -e->lineheight / 2 + e->screen_y / 2;
		if (e->drawstart < 0)
			e->drawstart = 0;
		e->drawend = e->lineheight / 2 + e->screen_y / 2;
		if (e->drawend < 0)
			e->drawend = e->screen_y - 1;
		else if (e->map[e->mapx][e->mapy] == 1)
			e->color = 0xFF0000;
		else if (e->map[e->mapx][e->mapy] == 2)
			e->color = 0x00FF00;
		else if (e->map[e->mapx][e->mapy] == 3)
			e->color = 0x0000FF;
		else if (e->map[e->mapx][e->mapy] == 4)
			e->color = 0x222222;
		else
			e->color = 0xFFFF00;
//		if (e->side == 1)
		//		e->color = e->color / 2;
		ft_vertic_line(x, e);
		x++;
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
}

int		main(void)
{
	t_env	*e;

	e = (t_env *)malloc(sizeof(t_env));
	ft_wolf_init(e);
	ft_init_map(e);
	ft_mlx_init(e);
	ft_detect_wall(e);
	mlx_loop(e->mlx);
}
