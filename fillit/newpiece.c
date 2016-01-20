/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newpiece.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 14:18:26 by gjacot            #+#    #+#             */
/*   Updated: 2016/01/20 16:08:39 by gjacot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libfillit.h>
#include <libft.h>

t_piece	*newpiece(char **piece, t_piece *next, char lettre, t_piece prev)
{
	t_piece	*piece1;
	int		x;
	int		y;

	x = 0;
	y = 0;
	piece1 = NULL;
	piece1 = (t_piece *)malloc(sizeof(t_piece));
	if (piece1 == NULL)
		return (NULL);
	piece1->x = x;
	piece1->y = y;
	if (piece && lettre)
	{
		piece1->piece = piece;
		piece1->lettre = lettre;
	}
	if (next)
		piece1->next = next;
	if (prev)
		piece1->prev = prev;
	return (0);
}
