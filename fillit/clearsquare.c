/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clearsquare.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiraude <jgiraude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 15:28:34 by jgiraude          #+#    #+#             */
/*   Updated: 2016/01/27 15:32:50 by jgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libfillit.h>
#include <libft.h>

void	clearsquare(char **piece, int taille)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (j <= taille && i <= taille)
	{
		if (i == taille)
		{
			j++;
			i = 0;
		}
		piece[j][i] = '.';
		i++;
	}
}