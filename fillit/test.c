/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 15:24:57 by gjacot            #+#    #+#             */
/*   Updated: 2016/01/10 16:10:58 by gjacot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfillit.h"

int	test(void)
{
	return (error());
}

void test3(char **tab)
{
	tab[1] = "slt\0";
}
void test2(void)
{
	char **tab;
	int i;
	
	i = 0;	
	tab = (char **)malloc(sizeof(char *) * 3);
	tab[2] = NULL;
	while (i < 2)
		tab[i++] = (char *)malloc(sizeof(char) * 4);
	
	tab[0] = "bjr\0";
	test3(tab);
	ft_putstr(tab[0]);
	ft_putstr(tab[1]);
	ft_putstr(tab[2]);
}
