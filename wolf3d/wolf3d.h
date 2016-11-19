/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 15:38:05 by gjacot            #+#    #+#             */
/*   Updated: 2016/11/19 15:08:34 by gjacot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		WOLF3D_H
# define	WOLF3D_H

# include "./libft/libft.h"
# include <mlx.h>
# include <math.h>
# include			<stdio.h>

typedef struct s_pos
{
	float			x;
	float			y;
}				t_pos;

typedef struct	s_env
{
	int			x;
	float		player_dir;
	float		a;
	float		b;
	int			**map;
	void		*mlx;
	void		*win;
	void		*img;
	int			*data;
	int			bpp;
	int			s_line;
	int			endian;
	float		p_x;
	float		p_y;
	int			screen_x;
	int			screen_y;
	int			mapx;
	int			mapy;
	int			color;
	float		p_dir;
	float		x_dir;
	int			size;
	int			map_height;
	int			map_weight;
	int			w_height;
	int			go_forward;
	int			go_back;
	int			go_left;
	int			go_right;
	int			turn_left;
	int			turn_right;
}				t_env;

int		ft_turn(int i, t_env *e);
int		ft_key_press(int key, t_env *e);
int		ft_key_release(int key, t_env *e);
int		ft_go_forward(int i, t_env *e);

#endif


















