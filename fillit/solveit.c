/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solveit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiraude <jgiraude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 15:07:48 by gjacot            #+#    #+#             */
/*   Updated: 2016/02/12 16:52:32 by jgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <libfillit.h>

int		firstsquare(int i)
{
	if (i == 1)
		return (2);
	if (i == 2)
		return (3);
	if (i > 2 && i < 5)
		return (4);
	if (i > 4 && i < 7)
		return (5);
	if (i > 6 && i < 10)
		return (6);
	if (i > 9 && i < 13)
		return (7);
	if (i > 12 && i < 17)
		return (8);
	if (i > 16 && i < 21)
		return (9);
	if (i > 20 && i < 26)
		return (10);
	else
		return (11);
}

void	affiche(char **tab_piece)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (tab_piece[j] != NULL)
	{
		ft_putchar(tab_piece[j][i]);
		if (tab_piece[j][i] == '\0')
		{
			j++;
			i = -1;
			ft_putchar('\n');
		}
		i++;
	}
}

int		solveit(char *buf)
{
	int		taille;
	int		i;
	char	**tab_piece;
	char	**square;
	t_piece	*piece;

	piece = NULL;
	i = 0;
	while (buf[i] != '\0')
		i++;
	i++;
	i = i / 21;
	taille = firstsquare(i);
	tab_piece = inittab(buf);
	remplir_tab(buf, tab_piece);
	piece = remplir_list(tab_piece, piece, 0);
	affiche_lst(piece);
	square = newsquare(taille);
	printf("pointeur square1 = %p\n", square);
	printf("comptetab = %d\n", compte_tab(buf));
	square = moveit(piece, square);
	printf("--- AFFICHAGE ---\n");
	affiche(square);
	return (0);
}
