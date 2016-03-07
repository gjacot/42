/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affiche_lst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiraude <jgiraude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 16:33:09 by gjacot            #+#    #+#             */
/*   Updated: 2016/03/07 16:34:02 by jgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libfillit.h>

void	affiche_lst(t_piece *lst)
{
	int i;

	i = 0;
	while (lst->prev != NULL)
		lst = lst->prev;
	while (lst->next != NULL)
	{
		printf("lst[%c] = ", lst->lettre);
		ft_putstr(lst->piece);
		ft_putchar('\n');
		lst = lst->next;
		i++;
	}
		printf("lst[%c] = ", lst->lettre);
		ft_putstr(lst->piece);
		ft_putchar('\n');
}
