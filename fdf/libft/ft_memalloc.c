/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 11:12:48 by gjacot            #+#    #+#             */
/*   Updated: 2015/12/13 14:56:17 by gjacot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned char	*i;
	size_t			j;

	i = NULL;
	j = 0;
	i = (unsigned char *)malloc(sizeof(unsigned char) * size);
	if (i == NULL || size == 0)
		return (NULL);
	while (j < size)
	{
		i[j] = '\0';
		j++;
	}
	return (i);
}
