/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacot <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 17:54:27 by gjacot            #+#    #+#             */
/*   Updated: 2015/12/16 19:23:32 by gjacot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*i;

	i = NULL;
	i = (char *)ft_memalloc(size + 1);
	if (i == NULL)
		return (NULL);
	else
	{
		ft_bzero(i, size + 1);
		return (i);
	}
}
