/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remplir_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiraude <jgiraude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 15:47:10 by gjacot            #+#    #+#             */
/*   Updated: 2016/01/21 18:59:43 by jgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <libfillit.h>

#include <stdio.h>

t_piece	*remplir_list(char **tab_piece, t_piece *lst)
{
	int		i;
	char	lettre;
	t_piece	*tmp;

	i = 0;
	tmp = NULL;
	lettre = 'A';
	lst = newpiece(lettre);
	while (tab_piece[i] != NULL)
	{
		lst->next = newpiece(lettre);
		tmp = lst;
		lst = lst->next;
		lst->prev = tmp;
		lettre++;
		i++;
	}
	while (i >= 0)
	{
		lst->piece = tab_piece[i];
		if (i != 0)
		{
			lst = lst->prev;
		}
		i--;
	}
	return (lst);
}
