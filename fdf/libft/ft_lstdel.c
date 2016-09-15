/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 13:06:26 by gjacot            #+#    #+#             */
/*   Updated: 2015/12/18 16:31:05 by gjacot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *alst2;
	t_list *mem;

	alst2 = *alst;
	while (alst2 != NULL)
	{
		mem = alst2->next;
		del(alst2->content, alst2->content_size);
		free(alst2);
		alst2 = mem;
	}
	*alst = NULL;
}
