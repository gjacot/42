/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affiche_lst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiraude <jgiraude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 16:33:09 by gjacot            #+#    #+#             */
/*   Updated: 2016/02/10 14:39:38 by gjacot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <libfillit.h>

void	affiche_lst(t_piece *lst)
{
	int i;

	i = 0;
	while (lst->prev != NULL)
		lst = lst->prev;
	while (lst->next != NULL)
	{
		ft_putstr("lst[] = ");
		ft_putstr(lst->piece);
		ft_putchar('\n');
		lst = lst->next;
		i++;
	}
}
