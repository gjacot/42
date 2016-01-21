/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newpiece.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiraude <jgiraude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 14:18:26 by gjacot            #+#    #+#             */
/*   Updated: 2016/01/21 18:15:50 by jgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libfillit.h>
#include <libft.h>

t_piece	*newpiece(char lettre)
{
	t_piece	*piece1;

	piece1 = NULL;
	piece1 = (t_piece *)malloc(sizeof(t_piece));
	if (piece1 == NULL)
		return (NULL);
	piece1->x = 0;
	piece1->y = 0;
	if (lettre)
	{
		piece1->piece = NULL;
		piece1->lettre = lettre;
	}
		piece1->next = NULL;
		piece1->prev = NULL;
	return (piece1);
}
