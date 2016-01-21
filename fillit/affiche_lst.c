/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affiche_lst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 16:33:09 by gjacot            #+#    #+#             */
/*   Updated: 2016/01/21 16:49:20 by gjacot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <libfillit.h>
#include <stdio.h>

void	affiche_lst(t_piece *lst)
{
	int i;

	i = 1;
	while (lst->prev)
		lst = lst->prev;
	while (lst->next)
	{
		printf("lst%d\n", i);
		ft_putstr(lst->piece);
		ft_putchar('\n');
		lst = lst->next;
		i++;
	}
}


















