/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiraude <jgiraude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 16:08:22 by jgiraude          #+#    #+#             */
/*   Updated: 2016/01/27 17:48:18 by jgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <libfillit.h>

void	allfree(char **square, char *buf, t_piece *lst)
{
	freesquare();
	freebuf();
	freetabpiece();
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
//tab.c + newpiece
//initsquare
//inittab
//newpiece
