/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affiche_lst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiraude <jgiraude@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 16:33:09 by gjacot            #+#    #+#             */
/*   Updated: 2016/01/21 18:56:46 by jgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <libfillit.h>
#include <stdio.h>

void	affiche_lst(t_piece *lst)
{
	int i;

	i = 0;
	while (lst->prev != NULL)
		lst = lst->prev;
	printf("debut lst = %p\n", lst);
	while (lst->next != NULL)
	{
		printf("lst[%d] = %s\n", i, lst->piece);
		//ft_putstr(lst->piece);
		ft_putchar('\n');
		lst = lst->next;
		i++;
	}
}


















