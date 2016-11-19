/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 16:12:38 by gjacot            #+#    #+#             */
/*   Updated: 2016/11/19 16:12:39 by gjacot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf3d.h"

void	ft_column_trace(t_env *e, int start, int end, int x)
{
	int y;

	y = 0;
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

void	ft_trace_column(t_env *e, float dist, int x, int prout)
{
	int start;
	int end;

	if (prout == 1 && e->x_dir + e->p_dir > 180)
		e->color = 0xFF0000;
	else if (prout == 1)
		e->color = 0x00FF00;
	else if (prout == 2 && e->x_dir + e->p_dir > 90 &&\
		e->p_dir + e->x_dir < 270)
		e->color = 0x0000FF;
	else
		e->color = 0xFFFF00;
	dist = dist * cos(M_PI * e->x_dir / 180);
	e->w_height = (277 * e->size) / dist;
	start = (e->screen_y - e->w_height) / 2;
	end = start + e->w_height;
	if (e->screen_y < end)
		end = e->screen_y;
	ft_column_trace(e, start, end, x);
}
