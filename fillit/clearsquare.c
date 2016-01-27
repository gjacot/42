/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clearsquare.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiraude <jgiraude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 15:28:34 by jgiraude          #+#    #+#             */
/*   Updated: 2016/01/27 17:35:07 by jgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libfillit.h>
#include <libft.h>

void	clean(char **square, char lettre)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (square[j] != NULL)
	{
		if (square[j][i] >= lettre)
			square[j][i] = '.';
		if (square[j][i] == '\0')
		{
			j++;
			i = -1;
		}
		i++;
	}
}

char 	**newsquare(int taille)
{
	char	**nvsquare;
	int		i;
	int		j;

	j = 0;
	nvsquare = ft_memalloc(sizeof(char *) * (taille + 1));
	while (j < taille)
	{
		i = 0;
		nvsquare[j] = ft_memalloc(sizeof(char) * (taille + 1));
		while (i < taille)
		{
			printf("taille newsquare = %d\n", taille);
			nvsquare[j][i] = '.';
			i++;
		}
		j++;
	}
	return (nvsquare);
}

char	**clearsquare(char **square, char lettre, int taille)
{
	int tailleactuel;
	int i;
	int j;

	i = 0;
	j = 0;
	tailleactuel = ft_strlen(square[0]);
	printf("square[0] = %s\n", square[0]);
	printf("tailleactuel = %d\n", tailleactuel);
	if (tailleactuel < taille)
	{
		while (square[j] != NULL)
		{
			free(square[j]);
			j++;
		}
		square = newsquare(taille);
	}
	else
		clean(square, lettre);
	return (square);
}
