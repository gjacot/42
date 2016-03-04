/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_division.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 02:31:50 by jgiraude          #+#    #+#             */
/*   Updated: 2016/01/11 18:10:21 by jgiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		*ft_division(int a, int b)
{
	int *tab;

	if (b == 0)
		return (NULL);
	tab = (int *)ft_memalloc(sizeof(int) * 2);
	tab[0] = (a / b);
	tab[1] = (a % b);
	return (tab);
}
