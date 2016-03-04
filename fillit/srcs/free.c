/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiraude <jgiraude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 16:08:22 by jgiraude          #+#    #+#             */
/*   Updated: 2016/03/04 18:40:14 by jgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libfillit.h>

void	allfree(char **square, char *buf, t_piece *piece)
{
	freesquare(square);
	freebuf(buf);
	freetabpiece(piece);
}

void	freesquare(char **square)
{
	int j;

	j = 0;
	while (square[j] != NULL)
	{
		free(square[j]);
		j++;
	}
	square = NULL;
}

void	freebuffer(char *buf)
{
	INIT(int, i, 0);

	while (i < BUF_SIZE)
	{
		buf[i] = '\0';
		i++;
	}
	buf = NULL;
}

void	freetabpiece(t_piece piece)
{
	t_piece temp;
	t_piece head;

	
	mazpiece(piece, 0);
	head = piece;
	while(piece->next)
	{
		temp = piece;
		piece = piece->next;
		free(temp);
	}
	free(head);
}


//tab.c + newpiece
//initsquare
//inittab
//newpiece
