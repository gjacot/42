/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 12:40:26 by gjacot            #+#    #+#             */
/*   Updated: 2016/11/19 15:29:24 by gjacot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf3d.h"

int		ft_go_forward(int i, t_env *e)
{
	int	x;
	int	y;

	ft_turn(0, e);
	x = 40 * (float)i * cos(M_PI * e->player_dir / 180);
	y = -40 * (float)i * sin(M_PI * e->player_dir /180);
	if (e->p_y + y > 0 && e->p_y + y < e->map_height && e->map\
		[(int)(e->p_y + y) / e->size][(int)(e->p_x) / e->size] == 0)
		e->p_y +=y;
	if (e->p_x + x > 0 && e->p_x + x < e->map_weight && e->map\
		[(int)(e->p_y) / e->size][(int)(e->p_x + x) / e->size] == 0)
		e->p_x +=x;
	return (0);
}

int		ft_turn(int i, t_env *e)
{
	e->player_dir += i;
	if (e->player_dir >= 360)
		e->player_dir -= 360;
	else if (e->player_dir < 0)
		e->player_dir += 360;
	return (0);
}
