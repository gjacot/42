/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 15:36:42 by gjacot            #+#    #+#             */
/*   Updated: 2016/11/19 15:32:46 by gjacot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf3d.h"

void	ft_wolf_init(t_env *e)
{
	e->size = 1000;
	e->screen_x = 1024;
	e->screen_y = 768;
	e->p_x = 2.5 * e->size;
	e->p_y = 2.5 * e->size;
	e->player_dir = 0;
	e->map_height = 5 * e->size;
	e->map_weight = 5 * e->size;
}

void	ft_init_map(t_env *e)
{
	int i;
	int j;

	i = 0;
	e->map = (int **)malloc(sizeof(int *) * 5);
	while (i != 6)
	{
		e->map[i] = (int *)malloc(sizeof(int) * 5);
		i++;
	}
	e->map[0][0] = 1;
	e->map[0][1] = 1;
	e->map[0][2] = 1;
	e->map[0][3] = 1;
	e->map[0][4] = 1;
	e->map[1][0] = 1;
	e->map[1][1] = 0;
	e->map[1][2] = 0;
	e->map[1][3] = 0;
	e->map[1][4] = 1;
	e->map[2][0] = 1;
	e->map[2][1] = 0;
	e->map[2][2] = 0;
	e->map[2][3] = 0;
	e->map[2][4] = 1;
	e->map[3][0] = 1;
	e->map[3][1] = 0;
	e->map[3][2] = 0;
	e->map[3][3] = 0;
	e->map[3][4] = 1;
	e->map[4][0] = 1;
	e->map[4][1] = 1;
	e->map[4][2] = 1;
	e->map[4][3] = 1;
	e->map[4][4] = 1;
	i = 0;
	while(i < 5)
	{
		j = 0;
		while (j < 5)
		{
			printf("%d",e->map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
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

void	ft_init_pos(t_pos *pos, float x, float y)
{
	pos->x = x;
	pos->y = y;
}

void	ft_initwallhori(t_env *e, float dir, t_pos *a, t_pos *t)
{
	if (dir < 180)
	{
		t->y = -1 * e->size;
		t->x = e->size / tan(M_PI * dir / 180);
		a->y = (int)(e->p_y / e->size) * e->size - 1;
		a->x = e->p_x + (e->p_y - a->y - 1) / tan(M_PI * dir  / 180);
	}
	else
	{
		t->y = e->size;
		t->x = e->size / tan(M_PI * dir / 180) * -1;
		a->y = (int)(e->p_y / e->size) * e->size + e->size;
		a->x = e->p_x + (e->p_y - a->y) / tan(M_PI * dir / 180);
	}
}

float	ft_wall_hori(t_env *e, float dir)
{
	t_pos a;
	t_pos t;

	ft_initwallhori(e, dir, &a, &t);
	while (a.y >= 0 && a.y < e->map_height && a.x >= 0 && a.x < e->map_weight
		   && !e->map[(int)a.y / e->size][(int)a.x / e->size])
	{
		ft_init_pos(&a, a.x + t.x, a.y + t.y);
	}
	if (a.y < 0 || a.y >= e->map_height || a.x < 0 || a.x >= e->map_weight)
	{
		return (-1);
	}
	if (dir < 180)
	{
		return (sqrt(ft_abs(pow((e->p_y - a.y - 1), 2)) + ft_abs(pow((e->p_x - a.x), 2))));
	}
	return (sqrt(ft_abs(pow((e->p_y - a.y), 2)) + ft_abs(pow((e->p_x - a.x), 2))));
}

void	ft_initwallverti(t_env *e, float dir, t_pos *b, t_pos *t)
{
	if (dir > 90 && dir < 270)
	{
		t->x = -1 * e->size;
		t->y = e->size * tan(M_PI * dir / 180);
		b->x = (int)(e->p_x / e->size) * e->size - 1;
		b->y = e->p_y + (e->p_x - b->x - 1) * tan(M_PI * dir / 180);
	}
	else
	{
		t->x = e->size;
		t->y = e->size * tan(M_PI * dir  / 180) * -1;
		b->x = (int)(e->p_x / e->size) * e->size + e->size;
		b->y = e->p_y + (e->p_x - b->x)  * tan(M_PI * dir / 180);
	}
}

float	ft_wallverti(t_env *e, float dir)
{
	t_pos b;
	t_pos t;

	ft_initwallverti(e, dir, &b, &t);
	while (b.y >= 0 && b.y < e->map_height && b.x >= 0 && b.x < e->map_weight
		   && !e->map[(int)b.y / e->size][(int)b.x / e->size])
	{
		ft_init_pos(&b, b.x + t.x, b.y + t.y);
	}
	if (b.y < 0 || b.y >= e->map_height || b.x < 0 || b.x >= e->map_weight)
	{
		return (-1);
	}
	if (dir > 90 && dir < 270)
	{
		return (sqrt (ft_abs(pow((e->p_y - b.y), 2)) + ft_abs(pow((e->p_x - b.x), 2))));
	}
	return (sqrt(ft_abs(pow((e->p_y - b.y), 2)) + ft_abs(pow((e->p_x - b.x), 2))));
}

void	ft_distwall(t_env *e, float x_dir, float p_dir)
{
	int dist;
	float dir;

	dist = 0;
	dir = p_dir + x_dir;
	//printf("dir = %f\n", dir);
	if (dir != 0 && dir != 180)
		e->a = ft_wall_hori(e, dir);
	else
		e->a = -1;
	if (dir != 90 && dir != 270)
		e->b = ft_wallverti(e, dir);
	else
		e->b = -1;
}

void	ft_trace_column(t_env *e, float dist, int x, int prout)
{
	int y;
	int start;
	int end;

	if (prout == 1 && e->x_dir + e->p_dir > 180)
		e->color = 0xFF0000;
	else if (prout == 1)
		e->color = 0x00FF00;
	else if (prout == 2 && e->x_dir + e->p_dir > 90 && e->p_dir + e->x_dir < 270)
		e->color = 0x0000FF;
	else
		e->color = 0xFFFF00;
	y = 0;
	dist = dist * cos(M_PI * e->x_dir / 180);
	e->w_height = (277 * e->size) / dist;
	start = (e->screen_y - e->w_height) / 2;
	end = start + e->w_height;
	if (e->screen_y < end)
		end = e->screen_y;
	while (y < start)
	{
		*(e->data + (y * e->s_line / 4) + x) = 0;
		y++;
	}
	while (y < end)
	{
		*(e->data + (y * e->s_line / 4) + x) = e->color;
		y++;
	}
	while (y < e->screen_y)
	{
		*(e->data + (y * e->s_line / 4) + x) = 0;
		y++;
	}
}

void	ft_verif_dir(t_env *e)
{
	if (e->p_dir + e->x_dir >= 360)
		e->p_dir -= 360;
	else if (e->p_dir + e->x_dir < 0)
		e->p_dir += 360;
}

void	ft_move(t_env *e)
{
	if (e->go_forward == 1)
		ft_go_forward(1, e);
	if (e->go_back == 1)
		ft_go_forward(-1, e);
	if (e->turn_left == 1)
		ft_turn(-1, e);
	if (e->turn_right == 1)
		ft_turn(1 ,e);
}

int		ft_wolf(t_env *e)
{
	int x;

	x = 0;
	e->p_dir = e->player_dir;
	e->x_dir = -30;
	ft_move(e);
	e->img = mlx_new_image(e->mlx, e->screen_x, e->screen_y);
	e->data = (int *) mlx_get_data_addr(e->img, &(e->bpp), &(e->s_line), &(e->endian));
	while (x < e->screen_x)
	{
		e->x = x;
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
			{
				ft_trace_column(e, e->b, x, 2);
			}
			else
			{
				ft_trace_column(e, e->a, x, 1);
			}
		}
		else
		{
			printf("tamagochi = %d\n", x);
			ft_trace_column(e, e->a, x, 1);
		}
		x++;
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	mlx_destroy_image(e->mlx, e->img);
	return (0);
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
//	mlx_hook(e->win, 17, 0, &ft_redcross, e);
	mlx_loop_hook(e->mlx, &ft_wolf, e);
	mlx_loop(e->mlx);
}
