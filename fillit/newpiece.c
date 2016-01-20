/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newpiece.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 14:18:26 by gjacot            #+#    #+#             */
/*   Updated: 2016/01/20 15:33:18 by gjacot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libfillit.h>
#include <libft.h>

t_piece	*newpiece(char **piece, t_piece *next, char lettre, t_piece prev)
{
	t_piece	*Piece;

	Piece = NULL;
	Piece = (t_piece *)malloc(sizeof(t_piece));
	if (Piece == NULL)
		return (NULL);
	if (piece && lettre)
	{
		Piece->piece = piece;
		Piece->lettre = lettre;
	}
	if (next)
		Piece->next = next;
	if (prev)
		Piece->prev = prev;
	return (0);
}




















