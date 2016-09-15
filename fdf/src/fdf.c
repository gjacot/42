/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/30 16:32:59 by gjacot            #+#    #+#             */
/*   Updated: 2016/09/15 15:59:40 by gjacot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point		*fill_lst(int nb, t_env *e)
{
	t_point	*new;

	new = (t_point *)malloc(sizeof(t_point));
	if (e->point->prev)
		e->point->x = e->point->prev->x + 50;
	else
	{
		ft_putstr("ok first\n");
		e->point->first = e->point;
		e->point->x = 50;
		e->point->y = 50;
	}
	e->point->z = nb;
	e->point->next = new;
	//printf("%d", e->point->z);
	new->prev = e->point;
	e->point = e->point->next;
	return (e->point);
}
