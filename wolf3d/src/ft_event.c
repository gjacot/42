/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 12:03:12 by gjacot            #+#    #+#             */
/*   Updated: 2016/11/19 15:29:17 by gjacot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf3d.h"

int		ft_key_press(int key, t_env *e)
{
	(void)e;
	if (key == 53)
		exit(0);
	if (key == 13 || key == 126)
		e->go_forward = 1;
	if (key == 0)
		e->go_left = 1;
	if (key == 2)
		e->go_right = 1;
	if (key == 1 || key == 125)
		e->go_back = 1;
	if (key == 123)
		e->turn_left = 1;
	if (key == 124)
		e->turn_right = 1;
	return (0);
}

int		ft_key_release(int key, t_env *e)
{
	if (key == 13 || key == 126)
		e->go_forward = 0;
	if (key == 0)
		e->go_left = 0;
	if (key == 2)
		e->go_right = 0;
	if (key == 1 || key == 125)
		e->go_back = 0;
	if (key == 123)
		e->turn_left = 0;
	if (key == 124)
		e->turn_right = 0;
	return (0);
}

int		ft_redcross(t_env *e)
{
	(void)e;
	exit(0);
	return (0);
}
