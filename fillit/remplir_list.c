/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remplir_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 15:47:10 by gjacot            #+#    #+#             */
/*   Updated: 2016/01/21 16:55:33 by gjacot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <libfillit.h>

void	remplir_list(char **tab_piece, t_piece *lst)
{
	int		i;
	char	lettre;
	t_piece	*prev;

	i = 0;
	lettre = 'A';
	prev = NULL;
	lst = newpiece(lettre, prev);
	while (tab_piece[i++] != NULL)
	{
		lst->next = newpiece(lettre, prev);
		lst->prev = lst;
		lst = lst->next;
		lettre++;
	}
	i--;
	while (lst->prev != NULL)
	{
		lst->piece = tab_piece[i--];
		lst = lst->prev;
	}
}










